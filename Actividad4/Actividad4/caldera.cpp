#include "caldera.h"

Caldera::Caldera()
{

}

int Caldera::getCodigo() const
{
    return codigo;
}

void Caldera::setCodigo(int value)
{
    codigo = value;
}

double Caldera::getTemperatura() const
{
    return temperatura;
}

void Caldera::setTemperatura(double value)
{
    temperatura = value;
}

int Caldera::getNumEmpleado() const
{
    return numEmpleado;
}

void Caldera::setNumEmpleado(int value)
{
    numEmpleado = value;
}

int Caldera::getContador() const
{
    return contador;
}

void Caldera::setContador(int value)
{
    contador = value;
}

int Caldera::getBandera() const
{
    return bandera;
}

void Caldera::setBandera(int value)
{
    bandera = value;
}
