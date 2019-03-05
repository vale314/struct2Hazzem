#ifndef MENU_H
#define MENU_H
#include <grafo.h>
#include <iostream>
#include <conio.h>
#include <vertice.h>

class Menu
{
private:
    Grafo grafo;
    enum{
        menuInsertarVertice=1,
        menuInsertarArista,
        menuMostrar,
        menuSalir
    };
public:
    Menu();
    void insertarVertice();
    void insertarArista();
    void mostar();
    void menu();
};

#endif // MENU_H
