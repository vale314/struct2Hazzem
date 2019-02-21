#ifndef MENU_H
#define MENU_H
#include "ldl.h"
#include <string>
#include <iomanip>
#include <fstream>

class Menu
{

private:
    enum{
        menuAgregar=1,
        menuMostrar,
        menuGuardar,
        menuCargar,
        menuSalir
    };
    int V;
    int adj[10][10];
    LDL<string> nombres;

public:
    Menu();
    void addEdge(int u,int v, int wt,int doble,int pond);
    int searchNombre(string nombresBuscar);
    void printGraph();
    void printList();
    void reset();

    void agregar();
    void guardar();
    void guardarNombres();
    void cargar();
    void cargarNombres();
    void menu();
};

#endif // MENU_H
