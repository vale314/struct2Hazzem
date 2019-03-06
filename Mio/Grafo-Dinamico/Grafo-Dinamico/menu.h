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
        menuModificarArista,
        menuModificarVertice,
        menuRecorridoAnchura,
        menuRecorridoProfundidad,
        menuRutaAnchura,
        menuRutaProfundidad,
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
    void modificarArista();
    void modificarVertice();
    void recorridoAnchura();
    void recorridoProfundidad();
    void rutaAnchura();
    void rutaProfundidad();
    void menu();
};

#endif // MENU_H
