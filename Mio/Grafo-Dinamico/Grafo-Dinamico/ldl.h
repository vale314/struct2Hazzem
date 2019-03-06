
#ifndef LDL_H
#define LDL_H
#include <iostream>
#include <stdexcept>
#include <conio.h>

using namespace std;

template <typename T>


class LDL
{

private:
        #include <nodoldl.h>
        size_t listSize;
        NodoLDL* listFront;
        NodoLDL* listBack;

public:
        LDL(const LDL<T> &other){
            listFront=nullptr;
            listBack=nullptr;
            listSize=0;
            for(size_t i=0;i<other.size();i++)
                push_back(other[i]);
        }

        LDL()
        {
            listSize=0;
            listFront= nullptr;
            listBack= nullptr;
        }
        ~LDL(){
            clear();
        }
        void partition(NodoLDL*,NodoLDL*);
        void _quickSort(NodoLDL*,NodoLDL*);
        bool empty() const;
        size_t  size()const;
        void push_front(const T &elem);
        void push_back(const T &elem);
//        void push_back_seleccion(const T &elem);
        const T& front()const;
        const T& back()const;
        void pop_front();
        void pop_back();
        T& operator[](size_t idx) const;

        void insert(size_t position, const T &elem);
        void erease(size_t position);
        void clear();
        void remove(const T &value);

        void cambio(T&a,T&b);
        void bubbleSort();

        void quickSort();

        void radixSort();

};


template <typename T>
bool LDL<T>::empty() const
{
    return  listSize == 0;
}

template<typename T>
size_t LDL<T>::size() const
{
    return listSize;
}

template<typename T>
void LDL<T>::push_front(const T &elem)
{
    if(empty()){
        listFront = new NodoLDL(elem);
        listBack = listFront;
    }else{
        NodoLDL* nuevo = new NodoLDL(elem,nullptr,listFront);
        listFront->anterior= nuevo;
        listFront=nuevo;
    }
    listSize++;
}

template<typename T>
void LDL<T>::push_back(const T &elem)
{
    if(empty())
    {
        listFront = new NodoLDL(elem);
        listBack = listFront;
    }
    else
    {
        NodoLDL* nuevo =new NodoLDL(elem,listBack);
        listBack->siguiente = nuevo;
        listBack=nuevo;
    }
    listSize++;
}

//template<typename T>
//void LDL<T>::push_back_seleccion(const T &elem)
//{
//    if(empty())
//    {
//        listFront = new NodoLDL(elem);
//        listBack = listFront;
//    }
//    else
//    {
//        NodoLDL* temp= listFront;
//        NodoLDL* nuevo =new NodoLDL(elem,listBack);
//        while((nuevo->dato > temp->siguiente->dato))
//            temp=temp->siguiente;

//        temp->siguiente = nuevo;
//        listBack=nuevo;
//    }
//    listSize++;
//}

template<typename T>
const T &LDL<T>::front() const
{
    if(empty())
        throw invalid_argument("front() on empty list");
    return listFront->dato;
}

template<typename T>
const T &LDL<T>::back() const
{
    if(empty())
         throw invalid_argument("front() on empty list");
    return listBack->dato;
}

template<typename T>
void LDL<T>::pop_front()
{
    if(empty())
         throw invalid_argument("popFront() on empty list");

    NodoLDL* eliminar= listFront;
    listFront= listFront->siguiente;
    if(listFront != nullptr)
        listFront->anterior = nullptr;
    delete  eliminar;
    eliminar = nullptr;
    listSize--;

}

template<typename T>
void LDL<T>::pop_back()
{
    if(empty())
         throw invalid_argument("popBack() on empty list");
    NodoLDL *eliminar = listBack;
    listBack= listBack ->anterior;
    if(listBack != nullptr)
        listBack-> siguiente = nullptr;
    delete eliminar;
    eliminar = nullptr;
    listSize--;
}

template<typename T>
T &LDL<T>::operator[](size_t idx) const
{
    if(empty())
         throw invalid_argument("operator() on empty list");
    else if(idx >= listSize)
        throw invalid_argument("index out of range");
    NodoLDL* temp = listFront;
    for(size_t i=0; i< idx; i++)
        temp = temp->siguiente;
    return temp->dato;
}


/*****************************************/




template<typename T>
void LDL<T>::insert(size_t position, const T &elem)
{
    if(empty())
        throw  invalid_argument("Insert() on empty list");
    else if(position > listSize)
        throw invalid_argument("Insert() on non valid position");
    else if(position == 0)
        push_front(elem);
    else if(position == listSize)
        push_back(elem);
    else{
        NodoLDL* temp = listFront;
        for(size_t i=0; i< position-1; i++)
            temp= temp->siguiente;
        NodoLDL* nuevo = new NodoLDL(elem, temp,temp->siguiente);
        NodoLDL* aux;
        aux=temp->siguiente;
        aux->anterior=nuevo;
        temp->siguiente=nuevo;
        listSize++;
    }
}



template<typename T>
void LDL<T>::erease(size_t position)
{
    if(empty())
        throw invalid_argument("Erease() on empty list");
    else if(position >= listSize)
        throw invalid_argument("Erease() on no valid position");
    else  if(position == 0)
        pop_front();
    else if(position == listSize -1)
        pop_back();
    else{
        NodoLDL* temp = listFront;
        for(size_t i=0; i<position-1; i++)
            temp= temp ->siguiente;
        NodoLDL *eliminar = temp->siguiente;
        NodoLDL *aux = eliminar->siguiente;
        temp->siguiente=eliminar->siguiente;
        aux->anterior=eliminar->anterior;
        delete eliminar;
        eliminar = nullptr;
        listSize--;
    }
}

template<typename T>
void LDL<T>::clear()
{
    if(!empty()){
        for(size_t i=0; i<listSize; i++)
            pop_front();
    }
    listFront=nullptr;
    listBack=nullptr;
    listSize=0;
}

template<typename T>
void LDL<T>::remove(const T &value)
{
    if(empty())
        throw invalid_argument("remove() on empty list");
    NodoLDL* temp = listFront;
    size_t i = 0;
    T dato;
    while(temp != nullptr)
    {
        dato = temp -> dato;
        temp = temp -> siguiente;
        if(dato == value)
        {
            erease(i);
            i--;
        }
        i++;
    }
}

template<typename T>
void LDL<T>::cambio(T &a, T &b)
{
    T x;
    x = a;
    a = b;
    b = x;
}

template<typename T>
void LDL<T>::bubbleSort()
{
    NodoLDL *start=listFront;
    int swapped, i;
    NodoLDL *ptr1;
    NodoLDL *lptr = NULL;

    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->siguiente != lptr)
        {
            if (ptr1->dato <= ptr1->siguiente->dato && ptr1->siguiente->siguiente!=NULL)
            {
                cambio(ptr1->dato, ptr1->siguiente->dato);
                swapped = 1;
            }
            ptr1 = ptr1->siguiente;
        }
        lptr = ptr1;
    }
    while (swapped);
}

template <typename T>
void LDL<T>::partition(NodoLDL *l, NodoLDL *h)
{
       T x  = h->dato;
       NodoLDL *i = l->anterior;

       for (NodoLDL *j = l; j != h; j = j->siguiente)
       {
           if (j->dato < x)
           {
               i = (i == NULL)? l : i->siguiente;
//               cout<<i->dato<<" "<<j->dato<<end;
               cambio((i->dato), (j->dato));
           }
       }

       i = (i == NULL)? l : i->siguiente;
       cambio((i->dato), (h->dato));

       i=i;
}

template<typename T>
void LDL<T>::_quickSort(NodoLDL *l, NodoLDL *h)
{
    if (h != NULL && l != h && l != h->siguiente)
        {
            partition(l,h);
            _quickSort(l, h->anterior);
            _quickSort(h->siguiente, h);
    }
}

template<typename T>
void LDL<T>::quickSort()
{
    NodoLDL *head=listFront;
    NodoLDL *h=listBack;
    _quickSort(head, h);
}







#endif // LDL_H
