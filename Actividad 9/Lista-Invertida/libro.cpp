#include "libro.h"

Libro::Libro()
{

}

int Libro::getCodigo() const
{
    return codigo;
}

void Libro::setCodigo(int value)
{
    codigo = value;
}

char *Libro::getNombre()
{
    return  nombre;
}

void Libro::setNombre(char nombre[TAM])
{
    strcpy(this->nombre,nombre);
}

char *Libro::getGenero()
{
    return  genero;
}

void Libro::setGenero(char genero[TAM])
{
    strcpy(this->genero,genero);
}

char *Libro::getAutor()
{
    return autor;
}

char Libro::setAutor(char autor[TAM])
{
    strcpy(this->autor,autor);
}

ostream& operator<<(ostream& os,const Libro& libro){
    os<<"Codigo: "<<libro.codigo<<'\n'
      <<"Nombre: "<<libro.nombre<<'\n'
      <<"Autor: "<<libro.autor<<'\n'
      <<"Genero: "<<libro.genero<<'\n';
    return os;
}
