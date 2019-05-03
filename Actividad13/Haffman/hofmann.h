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
};

#endif // HOFMANN_H


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
        listFront = new NodoHFF(elem);
        listBack = listFront;
    }
    else
    {
        //buscar la posicion de nuevo elemento toando en cuenta su frecuencia y su ascii y mandarle en ates y el despues
        NodoHFF* nuevo =new NodoHFF(elem,frec,listBack);

        //solo si el elemento es posicionado al fin de la lista hacer esta linea de codigo
        listBack->siguiente = nuevo;
        listBack=nuevo;
    }
    listSize++;
}
