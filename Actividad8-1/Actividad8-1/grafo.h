#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
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
public:
    Grafo();

    void resetGrafo();
    int name_to_int(const char[10]);
    void insertarArista(const char[10],const char[10],bool,bool,int);
    void mostrarLogico();
    void mostrarFisico();
    void guardar(string,string);
    void cargar(string,string);

};

#endif // GRAFO_H
