#include "administracion.h"

Administracion::Administracion()
{

}

void Administracion::menu(){
    int opc;
    do{
        system("cls");
        cout<<menuInsertar<<" Insertar"<<endl
            <<menuMostrar<<" Mostrar"<<endl
            <<menuMostrarTodos<<" Mostrar Todos"<<endl
            <<menuMostarTodosSeccion<<" Mostrar Toda Seccion"<<endl
            <<menuActualizar<<" Actualizar"<<endl
            <<menuEliminar<<" Eliminar"<<endl
            <<menuSalir<<" Salir"<<endl;
        cin>>opc;
        switch (opc) {
            case menuInsertar:
                insertar();
                system("pause");
            break;
            case menuMostrar:
                mostrar();
                system("pause");
            break;
            case menuMostrarTodos:
                mostrarTodos();
                system("pause");
            break;
            case menuMostarTodosSeccion:
                mostrarTodosSeccion();
                system("pause");
            break;
            case menuActualizar:
                actualizar();
            break;
            case menuEliminar:
                eliminar(true);
            break;
            case menuSalir:
            break;
        }
    }while(opc!=menuSalir);
}

void Administracion::insertar()
{
    Persona personaAux;

    inicia();
    personaAux=crearPersona();

    cout<<personaAux<<endl;

    long long pos=personaAux.posicion();
    cout<<"Pos: "<<pos<<endl;
    insertarPersonaEnArchivo(pos,personaAux);
}

void Administracion::insertarPersonaEnArchivo(long long pos,Persona personaAux)
{
    int cantidad=0;
    long long posNew=0;
    fstream salida("dispersa.txt",ios::in|ios::out|ios::binary);
        salida.seekg(pos);
        salida.seekp(pos);
        cout<<salida.tellg()<<endl;

        salida.read(reinterpret_cast<char*>(&cantidad),sizeof (int));
        cout<<"Cantidad: "<<cantidad<<endl;
        if(cantidad!=0){
            if(cantidad>=4){
                cout<<"Se Enceuntra Lleno"<<endl;
                system("pause");
                salida.close();
                return;
            }
            long long auxPos=salida.tellp();
            posNew=cantidad*sizeof (Persona);
            posNew=auxPos+posNew;
            salida.seekp(posNew);
        }
        salida.write(reinterpret_cast<char*>(&personaAux),sizeof (Persona));
        salida.seekg(pos);
        cantidad++;
        salida.write(reinterpret_cast<char*>(&cantidad),sizeof (int));
    salida.close();
}

Persona Administracion::crearPersona()
{
    Persona personaAux;

    char nombre[50];
    char domicilio[50];
    char telefono[30];
    char RFC[7];

    cin.ignore();
    bool cont=0;
    //do{
        if(cont)
            cout<<"Codigo Repetido O Invalido"<<endl<<"Ingrese El RFC"<<endl;
        else
            cout<<"Ingrese el RFC"<<endl;
        cin.getline(RFC,7,'\n');
        cont++;
    //}while(strlen(RFC)<6/*||!validateRFC(RFC)*/);
    cout<<"Nombre: "<<endl;
    cin.getline(nombre,50,'\n');

    cout<<"Domicilio: "<<endl;
    cin.getline(domicilio,50,'\n');

    cout<<"Telefono: "<<endl;
    cin.getline(telefono,30,'\n');

    personaAux.setNombre(nombre);
    personaAux.setDomicilio(domicilio);
    personaAux.setTelefono(telefono);
    personaAux.setRFC(RFC);

    return personaAux;

}


void Administracion::inicia(){
    int cont=0;
    Persona personaAux;

    if(validateFile())
        return;
    ofstream salida("dispersa.txt",ios::app|ios::binary);
    for(size_t i=0;i<TAM;i++){
        salida.write(reinterpret_cast<char*>(&cont),sizeof(int));
        for(size_t j=0;j<4;j++)
            salida.write(reinterpret_cast<char*>(&personaAux),sizeof (Persona));
    }
    salida.close();
}

bool Administracion::validateFile()
{
    ifstream entrada("dispersa.txt",ios::in);
    if(!entrada.good()){
        entrada.close();
        return false;
    }
    entrada.close();
    return true;
}

long long Administracion::mostrar()
{
    Persona personaAux;
    char RFC[7];
    long long pos;
    int cantidad=0;
    long long posS=0;

    cin.ignore();
    cout<<"Ingrese El RFC"<<endl;
    cin.getline(RFC,7,'\n');
    strcpy(RFCR,RFC);

    personaAux.setRFC(RFC);
    pos=personaAux.posicion();


    ifstream salida("dispersa.txt",ios::in|ios::binary);
        if(!salida.good()){
            salida.close();
            return -1;
        }
        salida.seekg(pos);
        salida.read(reinterpret_cast<char*>(&cantidad),sizeof (int));
        if(cantidad>=1){
            posS=salida.tellg();
            long long posAux=0;
            for(int i=0;i<cantidad;i++){
                posAux=salida.tellg();
                salida.read(reinterpret_cast<char*>(&personaAux),sizeof(Persona));
                if(personaAux.compareRFC(RFC))
                    break;
            }
            cout<<"Posicion: "<<posAux<<endl<<personaAux<<endl;
            salida.close();
            return posS-sizeof (int);
        }else{
            cout<<"No Se Encontro Nada"<<endl;
            pos=-1;
        }
    salida.close();
    return pos;
}

void Administracion::mostrarTodosSeccion()
{
    Persona personaAux;
    char RFC[7];
    long long pos;
    int cantidad=0;
    long long posAux=0;

    cin.ignore();
    cout<<"Ingrese El RFC"<<endl;
    cin.getline(RFC,7,'\n');

    personaAux.setRFC(RFC);
    pos=personaAux.posicion();

    ifstream salida("dispersa.txt",ios::in);
        if(!salida.good()){
            salida.close();
            return;
        }
        salida.seekg(pos);
        salida.read(reinterpret_cast<char*>(&cantidad),sizeof (int));
        if(cantidad>=1){
            posAux=salida.tellg();
            cout<<"Coincidencias: "<<cantidad<<" Posicion: "<<posAux-sizeof (int)<<endl;
            for(int i=0;i<cantidad;i++){
                posAux=salida.tellg();
                salida.read(reinterpret_cast<char*>(&personaAux),sizeof(Persona));
                cout<<"Posicion: "<<posAux<<endl<<personaAux<<endl;
            }
        }else
            cout<<"No Se Encontro Nada"<<endl;

    salida.close();
    return;
}

void Administracion::mostrarTodos()
{
    Persona personaAux;
    int cantidad=0;
    long long posAux=0;

    ifstream salida("dispersa.txt",ios::in|ios::binary);
        if(!salida.good()){
            salida.close();
            return;
        }
       while(!salida.eof()){
            salida.read(reinterpret_cast<char*>(&cantidad),sizeof (int));
            if(salida.eof())
                break;
            if(cantidad>=1){
                posAux=salida.tellg();
                cout<<"Coincidencias: "<<cantidad<<" Posicion: "<<posAux-sizeof (int)<<endl;
                for(int i=0;i<4;i++){
                    posAux=salida.tellg();
                    salida.read(reinterpret_cast<char*>(&personaAux),sizeof(Persona));
                    if(!personaAux.vacio())
                        cout<<"Posicion: "<<posAux<<endl<<personaAux<<endl;
                }
            }else{
                long long posAux=0;
                posAux=salida.tellg();
                posAux=posAux+(4*sizeof(Persona));
                salida.seekg(posAux);
            }
       }
    salida.close();
    return;
}

void Administracion::actualizar()
{
    Persona persona;

    if(eliminar(false)==-1)
        return;
    insertar();
}

int Administracion::eliminar(bool borrar)
{
    Persona persona;
    long long pos;
    long long posAux=0;
    int opc=1;

    pos=mostrar();

    if(pos==-1)
        return -1;
    if(borrar)
        cout<<"Desea Eliminar 1-Si   0-No"<<endl;
    else
        cout<<"Deseas Actualizar 1-Si   0-No"<<endl;
    cin>>opc;

    if(opc==0)
        return -1;
    int cantidad;
    fstream salida("dispersa.txt",ios::in|ios::out|ios::binary);
        if(!salida.good())
            return -1;
        salida.seekg(pos);
        salida.read(reinterpret_cast<char*>(&cantidad),sizeof (int));
        cantidad--;
        salida.seekp(pos);
        salida.write(reinterpret_cast<char*>(&cantidad),sizeof (int));

        for(int i=0;i<cantidad;i++){
            salida.read(reinterpret_cast<char*>(&persona),sizeof (Persona));
            if(persona.compareRFC(RFCR)){
                posAux=salida.tellg();
                posAux=posAux-sizeof (Persona);
                break;
            }
        }
        Persona personaAux;
        Persona personaValidate;
        Persona personaNull;

        salida.read(reinterpret_cast<char*>(&personaValidate),sizeof (Persona));
        if(personaValidate.vacio()){
            salida.seekp(posAux+sizeof (Persona));
            salida.write(reinterpret_cast<char*>(&personaNull),sizeof (Persona));
            salida.close();
            return 0;
        }

        for(int i=0;i<cantidad;i++){
            salida.seekp(posAux+sizeof (Persona));
            salida.read(reinterpret_cast<char*>(&personaAux),sizeof (Persona));
            salida.seekp(posAux);
            salida.write(reinterpret_cast<char*>(&personaAux),sizeof (Persona));
            posAux=posAux+sizeof (Persona);
        }
        salida.write(reinterpret_cast<char*>(&personaNull),sizeof (Persona));

    salida.close();

}

bool Administracion::validateRFC(char RFC[7])
{
    Persona personaAux;
    long long pos;
    int cantidad=0;

    personaAux.setRFC(RFC);
    pos=personaAux.posicion();

    ifstream salida("dispersa.txt",ios::in);
        if(!salida.good()){
            salida.close();
            return false;
        }
        salida.seekg(pos);
        salida.read(reinterpret_cast<char*>(&cantidad),sizeof (int));
        if(cantidad>=1){
            for(int i=0;i<cantidad;i++){
                salida.read(reinterpret_cast<char*>(&personaAux),sizeof(Persona));
                if(personaAux.compareRFC(RFC)){
                    salida.close();
                    return false;
                }
            }
        }else{
            salida.close();
            return true;
        }
    salida.close();
    return true;
}
