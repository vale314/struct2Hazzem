#include "vertice.h"


int Vertice::getNumVertice() const
{
    return numVertice;
}

void Vertice::setNumVertice(int value)
{
    numVertice = value;
}

const char *Vertice::getNombre() const
{
    return nombre;
}

void Vertice::setNombre(const char nombre [10])
{
    strcpy(this->nombre,nombre);
}

Vertice::Vertice()
{
    
}

Vertice::Vertice(const char nombre[10], int numVertice)
{
    strcpy(this->nombre,nombre);
    this->numVertice=numVertice;
}
