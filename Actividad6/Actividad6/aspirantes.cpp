#include "aspirantes.h"



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

const char* Aspirantes::getCurp() const
{
   return curp;
}

void Aspirantes::setCurp(const char value[4])
{
    memcpy(curp,value,4);
}
