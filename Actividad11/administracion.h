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
        menuMostrarTodos,
        menuActualizar,
        menuEliminar,
        menuSalir,
    };
    long long endPos;
    long long sizeOfPersona;
public:
    Administracion();
    void menu();

    void insertar();
    long long regresarPosicion(long long,char[7]);

    void crearArchivo();
    bool validarArchivo();
    void insertarEnArchivo(Persona,long long);

    void mostrar();
    void imprimirArchivo(long long ,char[7]);

    void mostrarTodos();

    void eliminar();
    void eliminarDeArchivo(char[7],long long);
};

#endif // ADMINISTRACION_H
