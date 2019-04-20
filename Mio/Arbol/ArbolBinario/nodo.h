#ifndef NODO_H
#define NODO_H
#include <iostream>

using namespace std;

template <typename T>
class Nodo
{
public:
    Nodo();
protected:
    T dato;
    Nodo *izq;
    Nodo *der;


public:
    Nodo(T valor){
        dato=valor;
        izq=der=NULL;
    }
    Nodo(T valor,Nodo *ramaIzq, Nodo* ramaDer){
        dato=valor;
        izq=ramaIzq;
        der=ramaDer;
    }
    //operaciones de acceso
    T valorNodo(){ return dato;}
    Nodo * subArbolIzq(){return izq;}
    Nodo * subArbolDer(){ return  der;}

    //operaciones de modificacion
    void nuevoValor(T d){ dato=d;}
    void ramaIzq(Nodo * n){izq=n;}
    void ramaDer(Nodo * n){der=n;}
};

#endif // NODO_H
