#include "aspirantes.h"

string Aspirantes::getCurp() const
{
    return curp;
}

void Aspirantes::setCurp(const string &value)
{
    curp = value;
}

string Aspirantes::getNombre() const
{
    return nombre;
}

void Aspirantes::setNombre(const string &value)
{
    nombre = value;
}

string Aspirantes::getEdad() const
{
    return edad;
}

void Aspirantes::setEdad(const string &value)
{
    edad = value;
}

string Aspirantes::getPuesto() const
{
    return puesto;
}

void Aspirantes::setPuesto(const string &value)
{
    puesto = value;
}

int Aspirantes::getBandera() const
{
    return bandera;
}

void Aspirantes::setBandera(int value)
{
    bandera=value;
}

Aspirantes::Aspirantes()
{

}
