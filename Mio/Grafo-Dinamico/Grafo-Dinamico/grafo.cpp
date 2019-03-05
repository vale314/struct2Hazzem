#include "grafo.h"

Grafo::Grafo()
{
    vertice=NULL;
}

int Grafo::tamano()
{
    int i=0;
    Vertice *aux;
    aux=vertice;
    while(aux != NULL){
        i++;
        aux = aux->siguiente;
    }
    return i;
}

bool Grafo::empty()
{
    if(vertice==NULL)
        return true;
    else
        return false;
}

Vertice *Grafo::getVertice(char nombre[10])
{
    Vertice *aux;
    aux=vertice;
    while(aux !=NULL){
        if(!strcmp(aux->getNombre(),nombre))
            return aux;
        aux=aux->siguiente;
    }
    return NULL;
}


void Grafo::insertarArista(Vertice *origen, Vertice *destino, int peso)
{
    Arista *nuevo= new Arista;
    nuevo->setPeso(peso);
    nuevo->adyacencia=NULL;
    nuevo->siguiente=NULL;


    Arista *aux;

    aux=origen->adyacencia;

    if(aux==NULL){
        origen->adyacencia=nuevo;
        nuevo->adyacencia=destino;
    }else{
        while (aux->siguiente !=NULL) {
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
        nuevo->adyacencia=destino;
    }
}

void Grafo::listaAdyacencia()
{
    Vertice *verticeAux;
    Arista *aristaAux;

    verticeAux=vertice;
    while (verticeAux!=NULL) {
        cout<<verticeAux->getNombre()<<"->";

        aristaAux= verticeAux->adyacencia;
        while (aristaAux!=NULL) {
            cout<<aristaAux->getPeso()<<"->"<<aristaAux->adyacencia->getNombre()<<"->";
            aristaAux=aristaAux->siguiente;
        }
        verticeAux=verticeAux->siguiente;
        cout<<""<<endl;
    }
}

void Grafo::insertarVertice(char nombre[10])
{
    Vertice *nuevo=new Vertice;
    nuevo->setNombre(nombre);
    nuevo->siguiente=NULL;
    nuevo->adyacencia=NULL;

    cout<<empty()<<endl;
    if(empty()){
        vertice=nuevo;
    }
    else{
        Vertice *aux;
        aux=vertice;
        while(aux->siguiente != NULL){
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
    }

}
