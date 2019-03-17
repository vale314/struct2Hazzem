#include "direccion.h"

Direccion::Direccion()
{

}

int Direccion::getId() const
{
    return id;
}

void Direccion::setId(int value)
{
    id = value;
}

long long Direccion::getPos() const
{
    return pos;
}

void Direccion::setPos(long long value)
{
    pos = value;
}

