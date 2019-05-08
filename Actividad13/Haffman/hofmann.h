#ifndef HOFMANN_H
#define HOFMANN_H
#include <iostream>
#include <string.h>
#include <stdexcept>
#include <bits/stdc++.h>
#include <string>
#include "ldl.h"

#include <conio.h>

using namespace std;

template <typename T>


class HFF
{

private:
        struct structDiccionario{
            char caracter;
            string num;
        }d;

        #include <nodo.h>
        size_t listSize;
        NodoHFF* listFront;
        NodoHFF* listBack;
        NodoHFF* hijo;
        int tamArchivoOriginal;
        Ldl<char> H;
        Ldl<structDiccionario> diccionario;
        string textoOriginal;

public:
        HFF()
        {
            listSize=0;
            listFront= nullptr;
            listBack= nullptr;
            hijo=nullptr;
            textoOriginal="";
        }
        ~HFF(){
            clear();
        }

        void clear();
        bool empty() const;
        void push(const T &elem,const int,NodoHFF* izq=nullptr,NodoHFF* der=nullptr,bool padre=false);
        void createTree();
        void tree();
        void showTree();
        void showTree(NodoHFF*,int);
        void add(string);
        void llenarDiccionario();
        int binarioToDecimal(string n);
        void createBinary();
        string findInDictionary(char);
        void busqueda(NodoHFF *localRoot,char elemento);
        T& operator[](size_t idx) const;
        size_t  size()const;
};

#endif // HOFMANN_H

template<typename T>
size_t HFF<T>::size() const
{
    return listSize;
}

template<typename T>
void HFF<T>::showTree()
{
    int contador=0;
    if(listFront==nullptr)
        return;
    showTree(listFront,contador);
}

template<typename T>
void HFF<T>::showTree(NodoHFF *localRoot, int contador)
{
    if(localRoot==nullptr)
        return;
    showTree(localRoot->der,contador+1);
    for(int i=0;i<contador;i++)
        cout<<"   ";
    if(localRoot->dato!='\x01')
        cout<<localRoot->dato<<"-"<<localRoot->frecuencia<<endl;
    else
        cout<<localRoot->frecuencia<<endl;
    showTree(localRoot->izq,contador+1);
}

template<typename T>
void HFF<T>::add(string var)
{
    textoOriginal=var;

    struct a{
        char caracter;
        int num;
    }structChar;

    Ldl<char> caracteres;

    char auxC[var.size()];
    strcpy(auxC,var.c_str());

    for(size_t i=0;i<var.size();i++)
        caracteres.push_back(auxC[i]);

    Ldl<char> old;
    Ldl<a> elem;

    for(size_t i=0;i<caracteres.size();i++){
        if(!old.find(caracteres[i])){
            size_t find=caracteres.find(caracteres[i]);
            old.push_back(caracteres[i]);
            structChar.caracter=caracteres[i];
            structChar.num=find;
            elem.push_back(structChar);
        }
    }

    for(size_t i = 0;i<elem.size();i++)
        push(elem[i].caracter,elem[i].num);
}


template<typename T>
void HFF<T>::llenarDiccionario()
{
    diccionario.clear();

    NodoHFF* aux=listFront;

    while(H.empty()==false){
        char actual=H.front();

        H.pop_front();

        busqueda(listFront,actual);

        if(hijo!=nullptr){
            d.caracter=hijo->dato;
            while(hijo->padre!=NULL){
                d.num+=hijo->tipo;
                hijo=hijo->padre;
            }
            reverse(d.num.begin(),d.num.end());
            diccionario.push_back(d);
            d.num="";
        }
    }

//    for(size_t i=0; i<diccionario.size();i++)
    //            cout<<diccionario[i].caracter<<endl<<diccionario[i].num<<endl;
}

template<typename T>
int HFF<T>::binarioToDecimal(string s)
{
        int value = 0;
        int indexCounter = 0;
        for(int i = s.length()-1; i >= 0; i--)
        {

          if(s[i] == '1')
            {
            value += pow(2, indexCounter);
            }
        indexCounter++;
        }
        return value;
}

template<typename T>
void HFF<T>::createBinary()
{
    string newText="";
    tamArchivoOriginal=textoOriginal.size();

    llenarDiccionario();

    for(size_t i=0;i<textoOriginal.size();i++)
        newText=newText+findInDictionary(textoOriginal[i]);

    cout<<textoOriginal<<endl;

    cout<<newText<<endl;

    while(newText.size()%8!=0)
            newText=newText+'0';

    cout<<newText<<endl<<endl;

    string cifrado="";
    string tempTA="";
    while(newText.size()>0){
        tempTA=newText.substr(0,8);
        newText=newText.substr(8,newText.size());
        cout<<tempTA<<"---"<<binarioToDecimal(tempTA)<<"---"<<string(1, char(binarioToDecimal(tempTA)))<<endl;
        cifrado=cifrado+string(1, char(binarioToDecimal(tempTA)));
    }

    cout<<cifrado<<endl;
}

template<typename T>
string HFF<T>::findInDictionary(char elem)
{
    for(size_t i=0;i<diccionario.size();i++)
        if(diccionario[i].caracter==elem)
            return(diccionario[i].num);
    return ("");
}

template<typename T>
void HFF<T>::busqueda(NodoHFF *localRoot,char elemento)
{
    if (localRoot == nullptr)
        return;
    if(localRoot->dato==elemento){
        hijo=localRoot;
        return;
    }
    busqueda(localRoot->izq,elemento);
    busqueda(localRoot->der,elemento);
}

template <typename T>
void HFF<T>::clear()
{
}


template <typename T>
bool HFF<T>::empty() const
{
    return  listSize == 0;
}


template<typename T>
void HFF<T>::push(const T &elem,const int frec,NodoHFF* izq,NodoHFF* der,bool padre)
{
    //pasamos los caracteres a int
    int data=int(elem);

    //si esta vacio solo agregamos
    if(empty())
    {
        NodoHFF* nuevo = new NodoHFF(elem,frec,nullptr,nullptr,izq,der,nullptr);
        listFront = nuevo;

        listBack = listFront;
        if(padre){
            izq->padre=nuevo;
            der->padre=nuevo;
            izq->tipo="0";
            der->tipo="1";
        }
    }
    else
    {
        /*Comprobamos que la frecuencia sea menor que el primero o
            que el primero tenga la misma frecuencia y sea menor nuestro new caracter
        */
        if((frec<listFront->frecuencia)||(frec==listFront->frecuencia&&data<int(listFront->dato))){
            NodoHFF* nuevo =new NodoHFF(elem,frec,nullptr,listFront,izq,der);
            if(padre){
                izq->padre=nuevo;
                der->padre=nuevo;
                izq->tipo="0";
                der->tipo="1";
            }
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
            if(padre){
                izq->padre=nuevo;
                der->padre=nuevo;
                izq->tipo="0";
                der->tipo="1";
            }
            listSize++;
            return;
        }
        if(aux->siguiente==NULL){
            if(frec>aux->frecuencia||(frec==aux->frecuencia&&data>=int(aux->dato))){
                NodoHFF* nuevo =new NodoHFF(elem,frec,aux,nullptr,izq,der);
                aux->siguiente=nuevo;
                if(padre){
                    izq->padre=nuevo;
                    der->padre=nuevo;
                    izq->tipo="0";
                    der->tipo="1";
                }
            }
        }

    }
    listSize++;
}

template<typename T>
void HFF<T>::createTree()
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

    listSize=listSize-2;

    push('\x01',frecuencia,izq,der,true);

    if(listFront->siguiente!=nullptr)
        createTree();

}

template<typename T>
void HFF<T>::tree()
{
    H.clear();

    NodoHFF* aux=listFront;

    while(aux!=NULL){
        H.push_back(aux->dato);
        aux=aux->siguiente;
    }

    for(size_t i=0;i<H.size();i++)
        cout<<H[i]<<" ";
    cout<<endl;

    createTree();

}

template<typename T>
T &HFF<T>::operator[](size_t idx) const
{
    if(empty())
         throw invalid_argument("operator() on empty list");
    else if(idx >= listSize)
        throw invalid_argument("index out of range");
    NodoHFF* temp = listFront;
    for(size_t i=0; i< idx; i++)
        temp = temp->siguiente;
    cout<<temp->dato<<" "<<temp->frecuencia<<endl;
    return temp->dato;
}
