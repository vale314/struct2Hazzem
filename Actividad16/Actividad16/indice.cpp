#include "indice.h"



int Indice::getContador() const
{
    return contador;
}

void Indice::setContador(int value)
{
    contador = value;
}

Indice::Indice()
{
    contador=0;
}

long long Indice::getPos() const
{
    return pos;
}

void Indice::setPos(long long value)
{
    pos=value;
}

const char* Indice::getId() const
{
    return id;
}

void Indice::setId(const char value[5])
{
    memcpy(id,value,5);
    cout<<value<<endl;
}
