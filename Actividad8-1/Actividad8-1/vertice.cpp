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

Vertice::Vertice()
{
    
}

Vertice::Vertice(const char nombre[10], int numVertice)
{
    strcpy(this->nombre,nombre);
    this->numVertice=numVertice;
}
