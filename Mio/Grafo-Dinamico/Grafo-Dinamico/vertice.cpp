#include "vertice.h"
#include "arista.h"




const char *Vertice::getNombre()
{
    return nombre;
}

void Vertice::setNombre(char nombreNuevo[10])
{
    strcpy(nombre,nombreNuevo);
}

Vertice::Vertice()
{

}
