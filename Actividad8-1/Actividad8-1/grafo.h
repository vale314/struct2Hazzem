#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <ldl.h>

#include "arista.h"
#include "vertice.h"


#include <string.h>

using namespace std;

class Grafo
{
private:
    Vertice vertice[10];
    Arista aristas[10][10];
    LDL<Vertice> vectoresNombres;
    int counter;
    string nameArchivoVertices;
    string nameArchivoAristas;
    bool visitado [10];
    LDL<int> aux;
    LDL<int> aux1;

    LDL<int> pilaO;
    LDL<int> pilaD;

public:
    Grafo();

    void resetGrafo();
    int name_to_int(const char[10]);
    int validarIdExistenteVector(int);
    int generateId(int,bool);
    void insertarArista(const char[10],const char[10],bool,bool,int);
    void mostrarLogico();
    void mostrarLogicoCabeceras();
    void mostrarFisico();
    void mostrarFiscoCabeceras();
    void guardar(string,string);
    void cargar(string,string);

    bool editarVertice(const char[10],const char[10]);
    bool editarArista(const char[10],const char[10],int,bool);

    bool eliminarArista(const char[10],const char[10]);
    bool eliminarVertice(const char[10]);

    void impresionVertice(int);
    void int_to_posName(int);
    void swap(int *xp, int *yp);
    const char* getNombre();
    void ordenar();
    bool buscarEnVisitado(int);

    void impresionAnchura(int origen);
    void impresionProfundidad(int origen);

    void rutaAnchura(int origen,int destino);
    void rutaProfundidad(int origen,int destino);

    void imprimirRuta(int destino);
};

#endif // GRAFO_H
