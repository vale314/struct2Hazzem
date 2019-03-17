#ifndef CATEGORIA_H
#define CATEGORIA_H
#include "lista_invertida.h"
#include "string.h"
#include <iostream>
#define TAMCHAR 30

using namespace std;

class Categoria
{
private:
    char nombre[30];

public:
    Lista_Invertida *origen;
    Categoria * siguiente;

    Categoria();

    void setNombre(char nombreNuevo[TAMCHAR]);
    char *getNombre();

    friend ostream& operator<<(ostream& os, const Categoria& dt1);
};

#endif // CATEGORIA_H
