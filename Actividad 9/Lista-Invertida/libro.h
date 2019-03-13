#ifndef LIBRO_H
#define LIBRO_H
#include <string.h>
#include <string>
#include <iostream>
#define TAM 20

using namespace std;

class Libro
{
private:
    int codigo;
    char nombre[TAM];
    char genero[TAM];
    char autor[TAM];

public:
    Libro();
    int getCodigo() const;
    void setCodigo(int value);

    char *getNombre();
    void setNombre(char nombre[TAM]);

    char *getGenero();
    void setGenero(char genero[TAM]);

    char *getAutor();
    char setAutor(char[TAM]);

    friend ostream& operator<<(ostream& os,const Libro& libro);
};

#endif // LIBRO_H
