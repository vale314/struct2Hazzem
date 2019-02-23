#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <grafo.h>
#include <conio.h>

using namespace std;

class Menu
{
private:
    enum {
        menuInsertar=1,
        menuMostrar,
        menuGuardar,
        menuCargar,
        menuSalir
    };
    Grafo grafo;
public:
    Menu();

    void menu();

    void insertar();
    void mostrar();
    void guardar();
    void cargar();
};

#endif // MENU_H
