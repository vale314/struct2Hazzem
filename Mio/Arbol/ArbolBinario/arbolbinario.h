#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include <nodo.h>

using namespace std;

template <typename T>

class ArbolBinario
{
private:
    Nodo<T> *raiz;

public:
    ArbolBinario();
    ArbolBinario(Nodo<T> *r);
    void Praiz(Nodo<T> *r);
    Nodo<T> *Oraiz();
    Nodo<T> raizArbol();
    bool esVacio();
    Nodo<T> * hijoIzq();
    Nodo<T> * hijoDer();
    Nodo<T> * nuevoArbol(Nodo<T> ramaIzq, T dato, Nodo<T> ramaDer);
};

#endif // ARBOLBINARIO_H

template<typename T>
ArbolBinario<T>::ArbolBinario()
{
    raiz=NULL;
}

template<typename T>
ArbolBinario<T>::ArbolBinario(Nodo<T> *r)
{

}

template<typename T>
void ArbolBinario<T>::Praiz(Nodo<T> *r)
{
    raiz=r;
}

template<typename T>
Nodo<T> *ArbolBinario<T>::Oraiz()
{
    return raiz;
}

template<typename T>
Nodo<T> ArbolBinario<T>::raizArbol()
{
    if(raiz)
        return *raiz;
    else
        throw "Arbol Vacio";
}

template<typename T>
bool ArbolBinario<T>::esVacio()
{
    return raiz==NULL;
}

template<typename T>
Nodo<T> *ArbolBinario<T>::hijoIzq()
{
    if(raiz)
        return raiz->subArbolIzq();
    else
        throw "Arbol Vacio";
}

template<typename T>
Nodo<T> *ArbolBinario<T>::hijoDer()
{
    if(raiz)
        return raiz->subArbolDer();
    else
        throw "Arbol Vacio";
}

template<typename T>
Nodo<T> *ArbolBinario<T>::nuevoArbol(Nodo<T> ramaIzq, T dato, Nodo<T> ramaDer)
{
    return new Nodo<T>(ramaIzq,dato,ramaDer);
}
