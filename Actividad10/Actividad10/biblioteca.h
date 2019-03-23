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
    Lista_Invertida *retornarOrigen(char[TAMCHAR]);
    void insertarCargaCategoria(char[TAMCHAR]);
    Categoria * retornarCategoria(int);
    void insertarConexionCategoria(int,int);
    bool verificarPrimero(Lista_Invertida*);
    Categoria *retornarCategoria(Lista_Invertida*);
    void eliminarCategoria(Categoria*);

    //Lista
    bool validaId(int);
    void insertarLibro(Libro);
    int posLista(Lista_Invertida*);
    void imprimirLista();
    void insertarCarga(int);
    void insertarConexionLista(int,int);
    Lista_Invertida *retornarElmento(int);
    Lista_Invertida *buscarElemento(int);
    void eliminarLista(int);

    //Direccion
    long long obtenerPos(int);
    void insertarCargarDireccion(int, long long);

    //Arhivo
    void mostrar();

    void mostrarGeneros();
    void mostrarPorGenero(char genero[TAMCHAR]);

    void mostrarPorPos(long long);

    void guardar();
    void guardarListaInvertida();
    void guardarCategoria();
    void guardarDireccion();
    void guardarBook(Libro);

    void cargar();
    void cargarListaInvertida();
    void cargarCategoria();
    void cargarDireccion();
};

#endif // BIBLIOTECA_H
