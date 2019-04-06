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
    long long endPos;
public:
    Administracion();
    void menu();

    void insertar();
    long long regresarPosicion(long long,char[7]);

    void crearArchivo();
    bool validarArchivo();
    void insertarEnArchivo(Persona,long long);

    bool validarPersona(long long,char[7]);

    void mostrar();
    void imprimirArchivo(long long ,char[7]);
};

#endif // ADMINISTRACION_H
