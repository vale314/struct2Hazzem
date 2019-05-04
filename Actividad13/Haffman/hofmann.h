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
        void push(const T &elem,const int,NodoHFF* izq=nullptr,NodoHFF* der=nullptr);
        void createTree();
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
void LDL<T>::push(const T &elem,const int frec,NodoHFF* izq,NodoHFF* der)
{
    //pasamos los caracteres a int
    int data=int(elem);

    //si esta vacio solo agregamos
    if(empty())
    {
        listFront = new NodoHFF(elem,frec,nullptr,nullptr,izq,der);
        listBack = listFront;
    }
    else
    {
        /*Comprobamos que la frecuencia sea menor que el primero o
            que el primero tenga la misma frecuencia y sea menor nuestro new caracter
        */
        if((frec<listFront->frecuencia)||(frec==listFront->frecuencia&&data<int(listFront->dato))){
            NodoHFF* nuevo =new NodoHFF(elem,frec,nullptr,listFront,izq,der);
            listFront->anterior=nuevo;
            listFront=nuevo;
            listSize++;
            return;
        }

        NodoHFF* aux;
        aux=listFront;

        /*
            Recorremos la lista mientras el siguiente elemento sea diferente de NULL
                si frecuencia es mayor aumentamos
                si no, si la frecuencia es igual y el dato es mas grande o igual (en su conversion int) aumentamos
                si no rompemos
        */
        while(aux->siguiente!=NULL){
            if(frec>aux->frecuencia)
                aux=aux->siguiente;
            else if(frec==aux->frecuencia&&data>=int(aux->dato)){
                aux=aux->siguiente;
            }
            else
                break;
        }

        /*
         * MAYOR
            si el elemento fue el ultimo que se verifico tenemos 2 posibilidades:
                que sea mayor a ese elemento o menor|| ya sea su frecuencia o su data
           si es mayor entramos
        */
        if(aux->siguiente==NULL){
            if(frec>aux->frecuencia||(frec==aux->frecuencia&&data>=int(aux->dato))){
                NodoHFF* nuevo =new NodoHFF(elem,frec,aux,nullptr,izq,der);
                aux->siguiente=nuevo;
            }
        }
        /*
         * MENOR
            si el elemento no fue el ultimo elemento
            validamos que sea menor a el actual  y lo ingresaremos en la parte de la izquierda
            configuramos los nodos
        */
        if((frec<aux->frecuencia)||(frec==aux->frecuencia&&data<=int(aux->dato))){
            NodoHFF* nuevo =new NodoHFF(elem,frec,aux->anterior,aux,izq,der);
            nuevo->anterior->siguiente=nuevo;
            nuevo->siguiente->anterior=nuevo;
        }
    }
    listSize++;
}

template<typename T>
void LDL<T>::createTree()
{
    if(empty()){
        cout<<"No Se Encuentran Elementos"<<endl;
        return;
    }

    int frecuencia=0;

    NodoHFF* aux = listFront;
    frecuencia=aux->frecuencia;
    frecuencia=frecuencia+aux->siguiente->frecuencia;

    NodoHFF* izq=listFront;
    NodoHFF* der=listFront->siguiente;

    listFront->anterior=nullptr;
    listFront->siguiente=nullptr;

    listFront=der->siguiente;

    der->anterior=nullptr;
    der->siguiente=nullptr;

    if(listFront!=NULL)
        listFront->anterior=nullptr;

    listSize=listSize-2;

    push('\x01',frecuencia,izq,der);

    if(listFront->siguiente!=NULL)
        createTree();

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
