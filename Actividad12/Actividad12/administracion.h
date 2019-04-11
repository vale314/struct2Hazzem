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
        menuMostarTodosSeccion,
        menuActualizar,
        menuEliminar,
        menuSalir,
    };
    char RFCR[7];
public:
    Administracion();

    void menu();

    void insertar();
    void insertarPersonaEnArchivo(long long,Persona);
    Persona crearPersona();
    void inicia();
    bool validateFile();

    long long mostrar();

    void mostrarTodosSeccion();

    void mostrarTodos();

    void actualizar();

    int eliminar(bool);

    bool validateRFC(char[7]);

};

#endif // ADMINISTRACION_H
