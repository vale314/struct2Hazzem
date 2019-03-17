#ifndef LIBRO_H
#define LIBRO_H
#include <string.h>
#include <iostream>
#define TAMCHAR 30
using namespace std;

class Libro
{
private:
    int id;
    char nombre[TAMCHAR];
    char author[TAMCHAR];
    char genero[TAMCHAR];

public:
    Libro();

    int getId();
    void setId(int value);

    void setNombre(char[TAMCHAR]);
    char *getNombre();

    void setAuthor(char[TAMCHAR]);
    char *getAuthor();

    void setGenero(char[TAMCHAR]);
    char *getGenero();

    friend ostream& operator<<(ostream& os, const Libro& dt1);

};

#endif // LIBRO_H
