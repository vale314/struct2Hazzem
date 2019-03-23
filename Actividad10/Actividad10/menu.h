#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <biblioteca.h>
#include <libro.h>

#define TAMCHAR 30

using namespace std;

enum{
    menuInsertar=1,
    menuMostrarLibros,
    menuMostrarPorGenero,
    menuInvertida,
    menuEliminar,
    menuSalir,
};

class Menu
{
private:
    Biblioteca biblioteca;
public:
    Menu();

    void insertar();

    void menu();

    void imprimirLista();

    void imprimirTodo();

    void imprimirCategoria();

    void eliminar();
};
#endif // MENU_H
