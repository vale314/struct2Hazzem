#include "persona.h"

Persona::Persona()
{

}

void Persona::setDomicilio(const char domicilio[50])
{
    strcpy(this->domicilio,domicilio);
}

char *Persona::getDomicilio()
{
    return  domicilio;
}

void Persona::setRFC(const char RFC[7])
{
    strcpy(this->RFC,RFC);
}

char *Persona::getRFC()
{
    return RFC;
}

void Persona::setNombre(const char nombre[50])
{
    strcpy(this->nombre,nombre);
}

char *Persona::getNombre()
{
    return nombre;
}

char *Persona::getTelefono()
{
    return  telefono;
}

void Persona::setTelefono(const char telefono[30])
{
    strcpy(this->telefono,telefono);
}

int Persona::generateAscii()
{
    int suma=0;
    for(int i=0;i<7;i++)
        suma=suma+static_cast<int>(RFC[i]);

    return (suma%100);
}

long long Persona::posicion()
{
    long long suma=0;
    suma=generateAscii();

    suma=suma*sizeof(Persona);

    return suma;
}

ostream& operator<<(ostream& os,Persona& p)
{
    os<<"Nombre: "<<p.nombre<<" RFC: "<<p.RFC<<" Domicilio: "<<p.domicilio<<" Telefono: "<<p.telefono<<endl;
    return os;
}//sobre cargado  de <<
