#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "libro.h"
#include "categoria.h"
#include "lista_invertida.h"
#include "direccion.h"

#include <iostream>
#include <fstream>
#define TAMCHAR 30

using namespace std;

class Biblioteca
{
private:
    Lista_Invertida *listaInvertida;
    Categoria *categoria;
    Direccion *direccion;
    int cantidadDireccion;
public:
    Biblioteca();
    ~Biblioteca();

    void initializate();

    /*Categoria*/
    bool emptyCategoria();
    bool buscarCategoria(char nombre[TAMCHAR]);
    Categoria *retornarCategoria(char nombre[TAMCHAR]);
    int posCategoria(Categoria*);

    //Lista
    bool validaId(int);
    void insertarLibro(Libro);
    int posLista(Lista_Invertida*);
    void imprimirLista();

    //Arhivo
    void guardar();
    void guardarListaInvertida();
    void guardarCategoria();
    void guardarDireccion();
    void guardarBook(Libro);
};

#endif // BIBLIOTECA_H
