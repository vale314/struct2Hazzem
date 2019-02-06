#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <iostream>
#include <caldera.h>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include "ldl.h"

using namespace std;

class Archivo
{
public:
    Archivo();
    ~Archivo();
    void menu();
private:
    ofstream escribir;
    ifstream leer;


    LDL<Caldera>calderas;

    enum menu{
        menuLectura,
        menuMostrar,
        menuModificar,
        menuEliminarLogico,
        menuActivarLogica,
        menuOrdenarBurbuja,
        menuQuickSort,
        menuSalir
    };
    struct CalderaStruct{
        int codigo;
        double temperatura;
        int numEmpleado;
        int contador;
        int bandera;
    }calderaStruct;

    void lectura();
    int mostrar(int);
    void imprimir(Caldera calderaImpresion);
    void imprimirCabecera();
    void modificar();
    int validateBusqueda(unsigned int*,int);
    void cambioLogica(int);

    void ingresoDatos(int);
    void asignacionDatos(int);

    void contadorIn();

    int emptyFile();
    void resetFileLeer();
    void endFileLeer();

    int validateContador(int);


    void ordenar(int);

    Caldera caldera;
};

#endif // ARCHIVO_H
