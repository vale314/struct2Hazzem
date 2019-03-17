#include "menu.h"

Menu::Menu()
{

}

void Menu::insertar()
{
    Libro libro;

    int id;
    char nombre[TAMCHAR];
    char author[TAMCHAR];
    char genero[TAMCHAR];

    cout<<"Ingrese el id"<<endl;
    cin>>id;

    cout<<"Ingrese el nombre"<<endl;
    cin.ignore();
    cin.getline(nombre,TAMCHAR,'\n');

    cout<<"Ingrese el author"<<endl;
    cin.getline(author,TAMCHAR,'\n');

    cout<<"Ingrese el genero"<<endl;
    cin.getline(genero,TAMCHAR,'\n');

    libro.setNombre(nombre);
    libro.setId(id);
    libro.setGenero(genero);
    libro.setAuthor(author);


    biblioteca.insertarLibro(libro);
    system("pause");
}

void Menu::menu(){
    int opc;
    do{
        system("cls");
        cout<<menuInsertar<<" Crear Un Libro"<<endl
            <<menuMostrarLibros<<" Mostrar Todos Los Libros"<<endl
            <<menuMostrarPorGenero<<" Mostrar Por Genero"<<endl
            <<menuInvertida<<" Mostrar Lista Invertida"<<endl
            <<menuSalir<<" Salir"<<endl;
        cin>>opc;
        switch (opc) {
            case menuInsertar:
                insertar();
            break;

            case menuMostrarLibros:
                imprimirTodo();
            break;

            case menuMostrarPorGenero:
                imprimirCategoria();
            break;

            case menuInvertida:
                imprimirLista();
            break;

            case menuSalir:
            break;

        }
    }while(opc != menuSalir);
}

void Menu::imprimirLista()
{
    biblioteca.imprimirLista();
    system("pause");
}

void Menu::imprimirTodo()
{
    biblioteca.mostrar();
    system("pause");
}

void Menu::imprimirCategoria()
{
    char genero[TAMCHAR];

    biblioteca.mostrarGeneros();

    cout<<"Genero A Buscar"<<endl;
    cin.ignore();
    cin.getline(genero,TAMCHAR,'\n');

    biblioteca.mostrarPorGenero(genero);
    system("pause");
}
