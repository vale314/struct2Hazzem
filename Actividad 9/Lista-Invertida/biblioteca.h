#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "libro.h"
#include "list.h"
#include "administrador.h"
#include <string>

using namespace std;

class Biblioteca
{
private:
    enum{
        menuCrear=1,
        menuMostrar,
        menuMostrarPorGenero,
        menuMostrariInvertida,
        menuModificar,
        menuEliminar,
        menuSalir
    };
    Administrador admin;
public:
    Biblioteca();

    void menu();
    void crearLibro();
    void mostrar();
    void mostrarPorGenero();
    void mostrarInvertida();
    void modificar();
    void eliminar();
};

#endif // BIBLIOTECA_H
