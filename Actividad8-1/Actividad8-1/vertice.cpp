#include "vertice.h"

string Vertice::getNombre() const
{
    return nombre;
}

void Vertice::setNombre(const string &value)
{
    nombre = value;
}

int Vertice::getNumVertice() const
{
    return numVertice;
}

void Vertice::setNumVertice(int value)
{
    numVertice = value;
}

Vertice::Vertice()
{
    
}
