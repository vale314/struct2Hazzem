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
        menuGuardar,
        menuCargar,
        menuEliminarArista,
        menuEliminarVertice,
        menuSalir
    };
    enum{
        menuMostrarLista=1,
        menuMostrarMatriz,
        menuMostarSalir
    };
public:
    Menu();
    void insertarVertice();
    void insertarArista();
    void mostar();
    void guardar();
    void cargar();
    void eliminarArista();
    void eliminarVertice();
    void menu();
};

#endif // MENU_H
