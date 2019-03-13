#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#define TAM 30
#define TAMCHAR 20
#include <fstream>
#include "tdaindice.h"
#include "tdageneros.h"
#include "tdalistainvertida.h"
#include "libro.h"

using namespace std;

class Administrador
{
private:
    TdaGeneros tdaGenero[TAM];
    TdaIndice tdaIndice[TAM];
    TdaListaInvertida tdaInvertida[TAM];
    int contadorIndice;
    int contadorGenero;
    int contadorInvertida;
public:
    Administrador();
    ~Administrador();

    void agregarLibro(Libro);

    void mostrar();

    //tdaIndice
    bool validarId(int);
    long long posicionId(int);
    void nuevoIndice(int,long long);

    //tdaGeneros
    bool validarGenero(char[TAMCHAR]);
    int posicionGenero(char[TAMCHAR]);
    void nuevoGenero(char[TAMCHAR],int);

    //tdaListaInvertida
    int posicionInvertida(int);
    void nuevoDato(int key,int pos);

    //archivo
    long long escribirArchivo(Libro);
    void escribirIndice();
    void escribirGenero();
    void escribirInvertida();

    void leerIndice();
    void leerGenero();
    void leerInvertida();
};

#endif // ADMINISTRADOR_H
