#include "categoria.h"

Categoria::Categoria()
{

}

void Categoria::setNombre(char nombreNuevo[30])
{
    strcpy(nombre,nombreNuevo);
}

char *Categoria::getNombre()
{
    return nombre;
}
