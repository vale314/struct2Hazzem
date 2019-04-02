#ifndef ADMINISTRACION_H
#define ADMINISTRACION_H
#include <iostream>
#include <fstream>
#include "persona.h"

#define TAM 100
#define TAMNOMBRE 50
#define TAMDOMI 50
#define TAMRFC 7

using namespace std;


class Administracion
{
private:
    enum{
        menuInsertar=1,
        menuMostrar,
        menuActualizar,
        menuEliminar,
        menuSalir,
    };
public:
    Administracion();
    void menu();

    void insertar();

    void crearArchivo();
    bool validarArchivo();
};

#endif // ADMINISTRACION_H
