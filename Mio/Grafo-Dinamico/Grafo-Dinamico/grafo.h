#ifndef GRAFO_H
#define GRAFO_H
#include <string.h>
#include <iostream>
#include <fstream>
#include <new.h>
#include <iomanip>
#include<new>

class Vertice;
#include "vertice.h"
using namespace std;

class Grafo
{
private:

    Vertice *vertice;
public:
    Grafo();
    int tamano();
    bool empty();

    void initialize();
    Vertice *getVertice(char nombre[10]);
    void insertarVertice(char nombre[10]);
    void insertarArista(Vertice *origen, Vertice *destino,int peso);
    void listaAdyacencia();
    void guardar();
    void cargar();

    int posVertice(char nombre[10]);
    void matrizAdyacencias();

    void eliminarArista(Vertice *origen,Vertice *destino);

    void eliminarVertice(Vertice *eliminar);

    void modificarArista(Vertice *origen,Vertice *destino,int ponderacion);
    void modificarVertice(Vertice *origen);
};

#endif // GRAFO_H
