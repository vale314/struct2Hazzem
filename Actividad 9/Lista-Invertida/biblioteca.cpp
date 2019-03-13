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
            <<menuModificar<<" Menu Modificar"<<endl
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
            case menuModificar:
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
}

void Biblioteca::mostrarPorGenero()
{
    char genero[20];

    cin.ignore();
    cout<<"Introdusca El Genero"<<endl;
    cin.getline(genero,20,'\n');


}
