#include "arista.h"

int Arista::getOrigen() const
{
    return origen;
}

void Arista::setOrigen(int value)
{
    origen = value;
}

int Arista::getPeso() const
{
    return peso;
}

void Arista::setPeso(int value)
{
    peso = value;
}

int Arista::getDestino() const
{
    return destino;
}

void Arista::setDestino(int value)
{
    destino = value;
}

Arista::Arista()
{
    
}
