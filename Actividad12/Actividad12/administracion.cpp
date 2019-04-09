#include "administracion.h"

Administracion::Administracion()
{

}

void Administracion::menu(){
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
                actualizar();
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
    Persona personaAux;

    inicia();
    personaAux=crearPersona();

    cout<<personaAux<<endl;

    cout<<"Pos: "<<personaAux.posicion()<<endl;
}

Persona Administracion::crearPersona()
{
    Persona personaAux;

    char nombre[50];
    char domicilio[50];
    char telefono[30];
    char RFC[7];

    cin.ignore();

    cout<<"Ingrese el RFC"<<endl;
    cin.getline(RFC,7,'\n');

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
    ofstream salida("dispersa.txt",ios::app);
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
    return  true;
}

void Administracion::mostrar()
{

}

void Administracion::mostrarTodos()
{

}

void Administracion::actualizar()
{

}

void Administracion::eliminar()
{

}
