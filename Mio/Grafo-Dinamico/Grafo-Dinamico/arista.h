#ifndef ARISTA_H
#define ARISTA_H
class Vertice;
#include "vertice.h"

class Arista
{
private:
    int peso;
public:
    Vertice *adyacencia;
    Arista *siguiente;
    Arista();

    int getPeso() const;
    void setPeso(int value);
};

#endif // ARISTA_H
