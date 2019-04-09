#ifndef ADMINISTRACION_H
#define ADMINISTRACION_H
#include <iostream>
#include <fstream>

#include "persona.h"

#define TAM 100

using namespace std;

class Administracion
{
private:
    enum{
        menuInsertar=1,
        menuMostrar,
        menuMostrarTodos,
        menuActualizar,
        menuEliminar,
        menuSalir,
    };
public:
    Administracion();

    void menu();

    void insertar();
    Persona crearPersona();
    void inicia();
    bool validateFile();

    void mostrar();

    void mostrarTodos();

    void actualizar();

    void eliminar();

};

#endif // ADMINISTRACION_H
