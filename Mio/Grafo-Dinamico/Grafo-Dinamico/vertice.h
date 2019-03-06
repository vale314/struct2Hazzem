#ifndef VERTICE_H
#define VERTICE_H
class Arista;
#include "arista.h"
#include <string.h>
#include <iostream>

using namespace std;



class Vertice
{
private:
    char nombre[10];
public:
    Vertice *siguiente;
    Arista *adyacencia;

    char *getNombre();
    void setNombre(char nombreNuevo[10]);
    Vertice();

};

#endif // VERTICE_H
