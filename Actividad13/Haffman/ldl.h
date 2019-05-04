
#ifndef LDL_H
#define LDL_H
#include <iostream>
#include <stdexcept>
#include <conio.h>


template <typename A>


class Ldl
{

private:
        struct NodoLdl
        {
            A dato;
            NodoLdl* siguiente;
            NodoLdl* anterior;

            NodoLdl(const A& elem,
                    NodoLdl* ant = nullptr,
                    NodoLdl* sig= nullptr):
                dato(elem),
                siguiente(sig),
                anterior(ant)
            {}
        };

        size_t listSize;
        NodoLdl* listFront;
        NodoLdl* listBack;

public:
        Ldl(const Ldl<A> &other){
            listFront=nullptr;
            listBack=nullptr;
            listSize=0;
            for(size_t i=0;i<other.size();i++)
                push_back(other[i]);
        }

        Ldl()
        {
            listSize=0;
            listFront= nullptr;
            listBack= nullptr;
        }
        ~Ldl(){
            clear();
        }
        void partition(NodoLdl*,NodoLdl*);
        void _quickSort(NodoLdl*,NodoLdl*);
        bool empty() const;
        size_t  size()const;
        void push_front(const A &elem);
        void push_back(const A &elem);
//        void push_back_seleccion(const T &elem);
        const A& front()const;
        const A& back()const;
        void pop_front();
        void pop_back();
        A& operator[](size_t idx) const;

        void insert(size_t position, const A &elem);
        void erease(size_t position);
        void clear();
        void remove(const A &value);

        void cambio(A&a,A&b);
        void bubbleSort();

        void quickSort();

        void radixSort();

        size_t find(const A);
};


template <typename A>
size_t Ldl<A>::find(const A a){
    NodoLdl* aux = listFront;

    size_t cont=0;

    while (aux!=NULL) {
        if(aux->dato==a)
            cont++;
        aux=aux->siguiente;
    }
    return cont;
}

template <typename A>
bool Ldl<A>::empty() const
{
    return  listSize == 0;
}

template<typename A>
size_t Ldl<A>::size() const
{
    return listSize;
}

template<typename A>
void Ldl<A>::push_front(const A &elem)
{
    if(empty()){
        listFront = new NodoLdl(elem);
        listBack = listFront;
    }else{
        NodoLdl* nuevo = new NodoLdl(elem,nullptr,listFront);
        listFront->anterior= nuevo;
        listFront=nuevo;
    }
    listSize++;
}

template<typename A>
void Ldl<A>::push_back(const A &elem)
{
    if(empty())
    {
        listFront = new NodoLdl(elem);
        listBack = listFront;
    }
    else
    {
        NodoLdl* nuevo =new NodoLdl(elem,listBack);
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

template<typename A>
const A &Ldl<A>::front() const
{
    if(empty())
        throw std::invalid_argument("front() on empty list");
    return listFront->dato;
}

template<typename A>
const A &Ldl<A>::back() const
{
    if(empty())
         throw std::invalid_argument("front() on empty list");
    return listBack->dato;
}

template<typename A>
void Ldl<A>::pop_front()
{
    if(empty())
         throw std::invalid_argument("popFront() on empty list");

    NodoLdl* eliminar= listFront;
    listFront= listFront->siguiente;
    if(listFront != nullptr)
        listFront->anterior = nullptr;
    delete  eliminar;
    eliminar = nullptr;
    listSize--;

}

template<typename A>
void Ldl<A>::pop_back()
{
    if(empty())
         throw std::invalid_argument("popBack() on empty list");
    NodoLdl *eliminar = listBack;
    listBack= listBack ->anterior;
    if(listBack != nullptr)
        listBack-> siguiente = nullptr;
    delete eliminar;
    eliminar = nullptr;
    listSize--;
}

template<typename A>
A &Ldl<A>::operator[](size_t idx) const
{
    if(empty())
         throw std::invalid_argument("operator() on empty list");
    else if(idx >= listSize)
        throw std::invalid_argument("index out of range");
    NodoLdl* temp = listFront;
    for(size_t i=0; i< idx; i++)
        temp = temp->siguiente;
    return temp->dato;
}


/*****************************************/




template<typename A>
void Ldl<A>::insert(size_t position, const A &elem)
{
    if(empty())
        throw  std::invalid_argument("Insert() on empty list");
    else if(position > listSize)
        throw std::invalid_argument("Insert() on non valid position");
    else if(position == 0)
        push_front(elem);
    else if(position == listSize)
        push_back(elem);
    else{
        NodoLdl* temp = listFront;
        for(size_t i=0; i< position-1; i++)
            temp= temp->siguiente;
        NodoLdl* nuevo = new NodoLdl(elem, temp,temp->siguiente);
        NodoLdl* aux;
        aux=temp->siguiente;
        aux->anterior=nuevo;
        temp->siguiente=nuevo;
        listSize++;
    }
}



template<typename A>
void Ldl<A>::erease(size_t position)
{
    if(empty())
        throw std::invalid_argument("Erease() on empty list");
    else if(position >= listSize)
        throw std::invalid_argument("Erease() on no valid position");
    else  if(position == 0)
        pop_front();
    else if(position == listSize -1)
        pop_back();
    else{
        NodoLdl* temp = listFront;
        for(size_t i=0; i<position-1; i++)
            temp= temp ->siguiente;
        NodoLdl *eliminar = temp->siguiente;
        NodoLdl *aux = eliminar->siguiente;
        temp->siguiente=eliminar->siguiente;
        aux->anterior=eliminar->anterior;
        delete eliminar;
        eliminar = nullptr;
        listSize--;
    }
}

template<typename A>
void Ldl<A>::clear()
{
    if(!empty()){
        for(size_t i=0; i<listSize; i++)
            Ldl::pop_front();
    }
    listFront=nullptr;
    listBack=nullptr;
    listSize=0;
}

template<typename A>
void Ldl<A>::remove(const A &value)
{
    if(empty())
        throw std::invalid_argument("remove() on empty list");
    NodoLdl* temp = listFront;
    size_t i = 0;
    A dato;
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

template<typename A>
void Ldl<A>::cambio(A &a, A &b)
{
    A x;
    x = a;
    a = b;
    b = x;
}

template<typename A>
void Ldl<A>::bubbleSort()
{
    NodoLdl *start=listFront;
    int swapped, i;
    NodoLdl *ptr1;
    NodoLdl *lptr = NULL;

    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->siguiente != lptr)
        {
            if (ptr1->dato > ptr1->siguiente->dato && ptr1->siguiente->siguiente!=NULL)
            {
                Ldl::cambio(ptr1->dato, ptr1->siguiente->dato);
                swapped = 1;
            }
            ptr1 = ptr1->siguiente;
        }
        lptr = ptr1;
    }
    while (swapped);
}

template <typename T>
void Ldl<T>::partition(NodoLdl *l, NodoLdl *h)
{
       T x  = h->dato;
       NodoLdl *i = l->anterior;

       for (NodoLdl *j = l; j != h; j = j->siguiente)
       {
           if (j->dato < x)
           {
               i = (i == NULL)? l : i->siguiente;
//               cout<<i->dato<<" "<<j->dato<<end;
               Ldl::cambio((i->dato), (j->dato));
           }
       }

       i = (i == NULL)? l : i->siguiente;
       Ldl::cambio((i->dato), (h->dato));

       i=i;
}

template<typename T>
void Ldl<T>::_quickSort(NodoLdl *l, NodoLdl *h)
{
    if (h != NULL && l != h && l != h->siguiente)
        {
            Ldl::partition(l,h);
            Ldl::_quickSort(l, h->anterior);
            Ldl::_quickSort(h->siguiente, h);
    }
}

template<typename T>
void Ldl<T>::quickSort()
{
    NodoLdl *head=listFront;
    NodoLdl *h=listBack;
    Ldl::_quickSort(head, h);
}







#endif // LDL_H
