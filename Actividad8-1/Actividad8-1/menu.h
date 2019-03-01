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
        menuDescargar,
        menuEditar,
        menuEliminar,
        menuImpresionAnchura,
        menuImpresionProfundidad,
        menuSalir
    };

    enum{
        menuEVertice=1,
        menuEArista,
        menuESalir
    };

    enum{
        menuElVertice=1,
        menuElArista,
        menuElSalir
    };
    Grafo grafo;
public:
    Menu();

    void menu();

    void insertar();
    void mostrar();
    void guardar();
    void cargar();
    void descargar();
    void editar();
    void editarVertice();
    void editarArista();

    void eliminar();
    void eliminarVertice();
    void eliminarArista();

    void impresionAnchura();
    void impresionProfundidad();
};

#endif // MENU_H
