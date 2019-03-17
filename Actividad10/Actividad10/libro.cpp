
#include "libro.h"

Libro::Libro()
{

}

int Libro::getId()
{
    return id;
}

void Libro::setId(int value)
{
    id = value;
}

void Libro::setNombre(char nombre[TAMCHAR])
{
    strcpy(this->nombre,nombre);
}

char *Libro::getNombre()
{
    return nombre;
}

void Libro::setAuthor(char author[TAMCHAR])
{
    strcpy(this->author,author);
}

char *Libro::getAuthor()
{
    return  author;
}

void Libro::setGenero(char genero[TAMCHAR])
{
    strcpy(this->genero,genero);
}

char *Libro::getGenero()
{
    return  genero;
}

ostream& operator<<(ostream& os, const Libro& dt1)
{
    os <<"Nombre: "<< dt1.nombre
       << '\n' <<"Author: "<< dt1.author
       << '\n' <<"Genero: "<< dt1.genero
       <<'\n' << "Id: "<< dt1.id<<'\n';
    return os;
}
