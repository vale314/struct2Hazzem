#ifndef EMPRESA_H
#define EMPRESA_H
#include <iostream>
#include <string>
#include <string.h>
#include "aspirantes.h"
#include <fstream>
#include <conio.h>
#include "ldl.h"
#include "indice.h"
#include "avltree.h"
#include <iomanip>

using namespace std;

class Empresa
{
private:
    Aspirantes aspirante;
    Ldl<Indice> indicesVector;
    Ldl<Indice> indicesVectorAux;
    AVLtree<Indice> indicesAVLTree;

    ofstream escrAspirante;
    ifstream leerAspirante;

    ofstream escrIndice;
    ifstream leerIndice;

    int cant;

    struct{
      char curp[5];
      string curpS;
      string nombre;
      string edad;
      string puesto;
      string bandera;

    }aspiranteStruct;

    enum menu{
        menuAgregar=1,
        menuConsultar,
        menuImprimir,
        menuEliminarLogico,
        menuActivar,
        menuEliminar,
        menuModificar,
        menuMostrarArbol,
        menuSalir
    };
public:
    Empresa();
    ~Empresa();

    void menu();

    void pedirDatos(int);
    void llenarDatos(int);
    void escribirDatos();

    void cargarArbolArchivo();
    void guardarArbolArchivo();
    bool comprobar20();
    void guardarEnArbol(Indice);
    void cargarArbol20();

    void mostrarArbol();


    void cargarVector();
    void guardarVector();
    bool consultar();

    void nuevoNodoArbol(Indice);

    void imprimirStruct();
    void imprimirCabeceras();

    void imprimir(size_t,int);
//    void imprimir(long long,int);
    void imprimirAll(int);

    int validateCurp(const char[5]);

    void eliminarLogico();
    void activar(int);

    void eliminarFisico();

    void modificar();
    void reOrganizarPunteros(long long);

};

#endif // EMPRESA_H
