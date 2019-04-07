#include "administracion.h"

Administracion::Administracion()
{
    endPos=TAM*sizeof (Persona);
    sizeOfPersona=sizeof (Persona);
}

void Administracion::menu()
{
    int opc;
    do{
        cout<<menuInsertar<<" Insertar"<<endl
            <<menuMostrar<<" Mostrar"<<endl
            <<menuMostrarTodos<<" Mostrar Todos"<<endl
            <<menuActualizar<<" Actualizar"<<endl
            <<menuEliminar<<" Eliminar"<<endl
            <<menuSalir<<" Salir"<<endl;
        cin>>opc;
        switch (opc) {
            case menuInsertar:
                insertar();
            break;
            case menuMostrar:
                mostrar();
            break;
            case menuMostrarTodos:
                mostrarTodos();
            break;
            case menuActualizar:
            break;
            case menuEliminar:
                eliminar();
            break;
            case menuSalir:
            break;
        }
    }while(opc!=menuSalir);
}

void Administracion::insertar()
{
    char nombre[50];
    char RFC[7];
    char domicilio[50];
    char telefono[30];
    long long pos=0;

    Persona persona;

    if(!validarArchivo())
        crearArchivo();

    cin.ignore();

    do{
        cout<<"RFC: "<<endl;
        cin.getline(RFC,7,'\n');
    }while(strlen(RFC)<6);

    cout<<"Nombre: "<<endl;
    cin.getline(nombre,50,'\n');

    cout<<"Domicilio: "<<endl;
    cin.getline(domicilio,50,'\n');

    cout<<"Telefono: "<<endl;
    cin.getline(telefono,30,'\n');

    persona.setRFC(RFC);
    persona.setNombre(nombre);
    persona.setDomicilio(domicilio);
    persona.setTelefono(telefono);

    pos=persona.posicion();

    pos=regresarPosicion(pos,RFC);

    if(pos==-1){
        cout<<"El RFC Ya Se Encuentra"<<endl;
        system("pause");
        return;
    }
    insertarEnArchivo(persona,pos);
}

long long Administracion::regresarPosicion(long long pos,char RFC[7])
{
    Persona personaAux;

    ifstream entrada("Persona.txt",ios::in);
    if(!entrada.good()){
        cout<<"Error a el abrir archivo"<<endl;
        return -1;
    }
    entrada.seekg(pos);


    entrada.read(reinterpret_cast<char*>(&personaAux),sizeof (Persona));
    if(personaAux.vacio()){
        entrada.close();
        return pos;
    }

    while(entrada.tellg()!=pos){
        if(entrada.tellg()==endPos)
            entrada.seekg(0);
        if(personaAux.compareRFC(RFC))
            return -1;
        entrada.read(reinterpret_cast<char*>(&personaAux),sizeof (Persona));
        if(personaAux.vacio()){
            long long actual=entrada.tellg();
            entrada.close();
            return actual-(sizeof (Persona));
        }
    }
}

void Administracion::crearArchivo()
{
    Persona persona;
    persona.setRFC("000");
    persona.setNombre("null");
    persona.setDomicilio("null");
    persona.setTelefono("000");
    ofstream salida("Persona.txt",ios::out);
    for(int i=0;i<TAM;i++)
        salida.write(reinterpret_cast<char*>(&persona),sizeof (Persona));
    salida.close();
}

bool Administracion::validarArchivo()
{
    ifstream salida("Persona.txt",ios::in);
        if(!salida.good()){
            salida.close();
            return false;
        }
        else{
            salida.close();
            return true;
        }
}

void Administracion::insertarEnArchivo(Persona persona, long long pos)
{
    cout<<pos<<endl;
    fstream salida("Persona.txt",ios::out|ios::in|ios::binary);
        salida.seekp(pos);
        salida.write(reinterpret_cast<const char*>(&persona),sizeof (Persona));
        salida.close();
}

void Administracion::mostrar()
{
    char RFCAux[7];
    Persona personaAux;
    long long pos=0;

    cout<<"Ingrese su RFC"<<endl;
    cin.ignore();
    cin.getline(RFCAux,7,'\n');

    personaAux.setRFC(RFCAux);
    pos=personaAux.posicion();

    imprimirArchivo(pos,RFCAux);
}

void Administracion::imprimirArchivo(long long pos,char RFCAux[7])
{
    Persona personaAux;
    bool end=false;
    bool encontrado=false;
    long long posEncontrado=0;

    ifstream entrada("Persona.txt",ios::in);
        if(!entrada.good()){
            cout<<"Error"<<endl;
            return;
        }

        entrada.seekg(pos);
        entrada.read(reinterpret_cast<char *>(&personaAux),sizeof(Persona));
        if(personaAux.compareRFC(RFCAux)){
            entrada.close();
            cout<<"Posicion: "<<pos<<endl;
            cout<<personaAux<<endl;
            return;
        }

        do{
            if(entrada.tellg()==endPos)
                entrada.seekg(0);
            entrada.read(reinterpret_cast<char *>(&personaAux),sizeof(Persona));
            if(personaAux.vacio())
                end=true;
            if(personaAux.compareRFC(RFCAux)){
                end=true;
                encontrado=true;
                posEncontrado=entrada.tellg()-sizeOfPersona;
            }

        }while(!end&&entrada.tellg()!=pos);
    entrada.close();

    if(encontrado)
        cout<<"Posicion: "<<posEncontrado<<endl<<personaAux<<endl;
    else
        cout<<"No encontrado"<<endl;
}

void Administracion::mostrarTodos()
{
    Persona personaAux;
    ifstream salida("Persona.txt",ios::in);
    if(!salida.good()){
        cout<<"No Se Pudo Abrir El Archivo"<<endl;
        return;
    }
    while(!salida.eof()){
        salida.read(reinterpret_cast<char*>(&personaAux),sizeof (Persona));
        if(salida.eof()){
            salida.close();
            return;
        }
        if(!personaAux.vacio()){
            cout<<"Posicion: "<<salida.tellg()-sizeOfPersona<<endl;
            cout<<personaAux<<endl;
        }
    }
    salida.close();
}

void Administracion::eliminar()
{
    Persona personaAux;
    char RFC[7];
    long long pos=0;

    cout<<"Ingrese El RFC"<<endl;
    cin.ignore();
    cin.getline(RFC,7,'\n');

    personaAux.setRFC(RFC);
    pos=personaAux.posicion();

    eliminarDeArchivo(RFC,pos);
}

void Administracion::eliminarDeArchivo(char RFC[7],long long pos)
{
    Persona personaAuxEmpty;
    Persona personaAux;
    long long posIncio=0;
    fstream salida("Persona.txt",ios::out|ios::in|ios::binary);
    if(!salida.good()){
        cout<<"Error"<<endl;
        return;
    }
    salida.seekg(pos);

    salida.read(reinterpret_cast<char*>(&personaAux),sizeof (Persona));

    while (salida.tellg()!=pos) {
        if(salida.tellg()==endPos)
            salida.seekg(0);
        if(personaAux.compareRFC(RFC)){
            salida.seekg(salida.tellg()-sizeOfPersona);
            salida.write(reinterpret_cast<char*>(&personaAuxEmpty),sizeof (Persona));
            break;
        }
        salida.read(reinterpret_cast<char*>(&personaAux),sizeof (Persona));
    }
    while (pos!=salida.tellg()) {
        if(salida.tellg()==endPos)
            salida.seekg(0);
        posIncio=salida.tellg()-sizeOfPersona;
        salida.read(reinterpret_cast<char*>(&personaAux),sizeof (Persona));

        if(personaAux.vacio()){
            salida.close();
            return;
        }
        if(personaAux.posicion()!=salida.tellg()-sizeOfPersona){
            salida.seekp(posIncio);
            Persona personaAuxEmpty;
            salida.write(reinterpret_cast<char*>(&personaAux),sizeof(Persona));
            salida.write(reinterpret_cast<char*>(&personaAuxEmpty),sizeof (Persona));
            //salida.seekp(salida.tellg()+sizeOfPersona);
        }else{
            salida.close();
            return;
        }
    }
    salida.close();
}
