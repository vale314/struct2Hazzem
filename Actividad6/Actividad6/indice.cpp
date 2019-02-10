#include "indice.h"



Indice::Indice()
{

}

long long Indice::getPos() const
{
    return pos;
}

void Indice::setPos(long long value)
{
    pos=value;
}

string Indice::getId() const
{
    return id;
}

void Indice::setId(const string &value)
{
    id=value;
}
