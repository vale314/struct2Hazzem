#include "biblioteca.h"


Biblioteca::Biblioteca()
{

}



void Biblioteca::menu()
{
    int opc;
    do{
        system("cls");
        cout<<menuCrear<<" Menu Crear"<<endl
            <<menuMostrar<<" Menu Mostrar"<<endl
            <<menuMostrarPorGenero<<" Menu Mostrar Por Genero"<<endl
            <<menuMostrariInvertida<<" Menu Mostrar Invertida"<<endl
            <<menuModificar<<" Menu Modificar"<<endl
            <<menuEliminar<<" Menu Eliminar"<<endl
            <<menuSalir<<" Menu Salir"<<endl;
        cin>>opc;
        switch (opc) {
            case menuCrear:
                crearLibro();
            break;
            case menuMostrar:
                mostrar();
            break;
            case menuMostrarPorGenero:
                mostrarPorGenero();
            break;
            case menuMostrariInvertida:
                mostrarInvertida();
            break;
            case menuModificar:
                modificar();
            break;
            case menuEliminar:
                eliminar();
            break;
            case menuSalir:
            break;
        }
    }while(opc!=menuSalir);
}

void Biblioteca::crearLibro()
{
    int id;
    char nombre[20];
    char autor[20];
    char genero[20];

    Libro libro;

    cout<<"Ingrese el id"<<endl;
    cin>>id;

    cin.ignore();
    cout<<"Ingrese El Libro"<<endl;
    cin.getline(nombre,20,'\n');


    cout<<"Ingrese el autor"<<endl;
    cin.getline(autor,20,'\n');


    cout<<"Ingrese el genero"<<endl;
    cin.getline(genero,20,'\n');

    libro.setCodigo(id);
    libro.setNombre(nombre);
    libro.setAutor(autor);
    libro.setGenero(genero);

    admin.agregarLibro(libro);
}

void Biblioteca::mostrar()
{
    admin.mostrar();

    system("pause");
}

void Biblioteca::mostrarPorGenero()
{
    char genero[20];

    admin.mostrarGenero();

    cin.ignore();
    cout<<"Introdusca El Genero"<<endl;
    cin.getline(genero,20,'\n');

    admin.mostrarPorGenero(genero);

    system("pause");
}

void Biblioteca::mostrarInvertida()
{
    cout<<"Lista Invertida"<<endl;
    admin.mostrarListaInvertida();
    system("pause");
}

void Biblioteca::modificar()
{
    int id;
    cout<<"Ingrese el id"<<endl;
    cin>>id;

    if(!admin.validarId(id)){
        cout<<"Id Inesistente"<<endl;
        system("pause");
        return;
    }

    char nombre[20];
    char autor[20];
    char genero[20];

    Libro libro;

    cin.ignore();
    cout<<"Ingrese El Libro"<<endl;
    cin.getline(nombre,20,'\n');


    cout<<"Ingrese el autor"<<endl;
    cin.getline(autor,20,'\n');


    cout<<"Ingrese el genero"<<endl;
    cin.getline(genero,20,'\n');

    libro.setCodigo(id);
    libro.setNombre(nombre);
    libro.setAutor(autor);
    libro.setGenero(genero);

    admin.modificar(id,libro);

    system("pause");
}

void Biblioteca::eliminar()
{
    int id;
    cout<<"Ingrese El Id"<<endl;
    cin>>id;

    admin.eliminar(id);
}
