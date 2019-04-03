#include "administracion.h"

Administracion::Administracion()
{

}

void Administracion::menu()
{
    int opc;
    do{
        cout<<menuInsertar<<" Insertar"<<endl
            <<menuMostrar<<" Mostrar"<<endl
            <<menuActualizar<<" Actualizar"<<endl
            <<menuEliminar<<" Eliminar"<<endl
            <<menuSalir<<" Salir"<<endl;
        cin>>opc;
        switch (opc) {
            case menuInsertar:
                insertar();
            break;
            case menuMostrar:
            break;
            case menuActualizar:
            break;
            case menuEliminar:
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

    cout<<"RFC: "<<endl;
    cin.getline(RFC,7,'\n');

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

    insertarEnArchivo(persona,pos);

}

void Administracion::crearArchivo()
{
    Persona persona;
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
    fstream salida("Persona.txt",ios::out|ios::in);
        salida.seekp(pos);
        salida.write(reinterpret_cast<char*>(&persona),sizeof(Persona));
    salida.close();
}
