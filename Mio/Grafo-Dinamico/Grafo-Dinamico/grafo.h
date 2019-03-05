#ifndef GRAFO_H
#define GRAFO_H
#include <string.h>
#include <iostream>
#include <new.h>
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

    Vertice *getVertice(char nombre[10]);
    void insertarVertice(char nombre[10]);
    void insertarArista(Vertice *origen, Vertice *destino,int peso);
    void listaAdyacencia();
};

#endif // GRAFO_H
