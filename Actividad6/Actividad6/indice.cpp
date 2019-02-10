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

const char* Indice::getId() const
{
    return id;
}

void Indice::setId(const char value[5])
{
    memcpy(id,value,5);
    cout<<value<<endl;
}
