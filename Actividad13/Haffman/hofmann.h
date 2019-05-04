#ifndef HOFMANN_H
#define HOFMANN_H
#include <iostream>
#include <stdexcept>
#include <conio.h>

using namespace std;

template <typename T>


class LDL
{

private:
        #include <nodo.h>
        size_t listSize;
        NodoHFF* listFront;
        NodoHFF* listBack;

public:
        LDL()
        {
            listSize=0;
            listFront= nullptr;
            listBack= nullptr;
        }
        ~LDL(){
            clear();
        }

        void clear();
        bool empty() const;
        void push(const T &elem,const int);
        T& operator[](size_t idx) const;
        size_t  size()const;
};

#endif // HOFMANN_H

template<typename T>
size_t LDL<T>::size() const
{
    return listSize;
}

template<typename T>
void LDL<T>::clear()
{
}


template <typename T>
bool LDL<T>::empty() const
{
    return  listSize == 0;
}


template<typename T>
void LDL<T>::push(const T &elem,const int frec)
{
    if(empty())
    {
        listFront = new NodoHFF(elem,frec,nullptr,nullptr);
        listBack = listFront;
    }
    else
    {

        if(frec<listFront->frecuencia){
            NodoHFF* nuevo =new NodoHFF(elem,frec,nullptr,listFront);
            listFront->anterior=nuevo;
            listFront=nuevo;
            listSize++;
            return;
        }

        NodoHFF* aux;
        aux=listFront;

        while(aux->siguiente!=NULL){
            if(frec>=aux->frecuencia)
                aux=aux->siguiente;
            else
                break;
        }

        if(aux->siguiente==NULL){
            if(frec>=aux->frecuencia){
                NodoHFF* nuevo =new NodoHFF(elem,frec,aux,nullptr);
                aux->siguiente=nuevo;
            }
        }

        if(frec<aux->frecuencia){
            NodoHFF* nuevo =new NodoHFF(elem,frec,aux->anterior,aux);
            nuevo->anterior->siguiente=nuevo;
            nuevo->siguiente->anterior=nuevo;
        }
    }
    listSize++;
}

template<typename T>
T &LDL<T>::operator[](size_t idx) const
{
    if(empty())
         throw invalid_argument("operator() on empty list");
    else if(idx >= listSize)
        throw invalid_argument("index out of range");
    NodoHFF* temp = listFront;
    for(size_t i=0; i< idx; i++)
        temp = temp->siguiente;
    return temp->dato;
}
