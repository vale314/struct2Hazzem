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
public:
    Grafo();

    void resetGrafo();
    int name_to_int(const char[10]);
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

};

#endif // GRAFO_H
