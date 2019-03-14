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

    void mostrarGenero();
    void mostarPosicion(long long);
    void keyToPos(int);
    void mostrarPorGenero(char[TAMCHAR]);

    void modificar(int,Libro);
    void sobrescribir(long long,Libro);


    void mostrarListaInvertida();

    //tdaIndice
    bool validarId(int);
    long long posicionId(int);
    void nuevoIndice(int,long long);
    void reset();

    //tdaGeneros
    bool validarGenero(char[TAMCHAR]);
    int posicionGenero(int);
    int posicionGenero(char[TAMCHAR]);
    void nuevoGenero(char[TAMCHAR],int);

    //tdaListaInvertida
    void eliminar(int);
    void desasociarGeneroInvertida(int);
    void actualizarGeneroInvertida(int);
    void quitarDeLaListaGenero(int);
    void quitarDeLaLista(int);
    void reposisionar(int);
    int posicionInvertida(int);
    int posicionInvertidaArray(int);
    void nuevoDato(int key,int pos);

    //archivo
    void eliminarFisico(int);
    void reposicionarPunturos();
    long long escribirArchivo(Libro);
    void escribirIndice();
    void escribirGenero();
    void escribirInvertida();

    void leerIndice();
    void leerGenero();
    void leerInvertida();
};

#endif // ADMINISTRADOR_H
