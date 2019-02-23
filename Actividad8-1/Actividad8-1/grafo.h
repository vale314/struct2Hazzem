#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <fstream>
#include <string>

#include "arista.h"
#include "vertice.h"

#include <string.h>

using namespace std;

class Grafo
{
private:
    Vertice vertice[10];
    Arista aristas[10][10];
    int counter;
public:
    Grafo();

    int name_to_int(const char[10]);
    void insertarArista(const char[10],const char[10],bool,bool,int);
};

#endif // GRAFO_H
