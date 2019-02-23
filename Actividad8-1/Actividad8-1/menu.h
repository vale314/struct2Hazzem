#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <grafo.h>

using namespace std;

class Menu
{
private:
    enum {
        menuInsertar=1,
        menuMostrar,
        menuSalir
    };
    Grafo grafo;
public:
    Menu();

    void menu();

    void insertar();
    void mostrar();
};

#endif // MENU_H
