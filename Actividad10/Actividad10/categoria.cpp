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

ostream& operator<<(ostream& os, const Categoria& dt1)
{
    os <<"Categoria: "<< dt1.nombre
       <<'\n';

    return os;
}
