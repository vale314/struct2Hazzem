#include "persona.h"

Persona::Persona()
{
    strcpy(nombre,"null");
    strcpy(domicilio,"null");
    strcpy(RFC,"000");
    strcpy(telefono,"000");
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
    unsigned long long int suma=1;
    int num;
    for(int i=0;i<6;i++)
        suma=suma*static_cast<int>(RFC[i]);

    return (suma%100);
}

long long Persona::posicion()
{
    long long suma=0;
    suma=generateAscii();

    suma=suma*sizeof(Persona);

    return suma;
}

bool Persona::compareRFC(const char RFCAUX[7])
{
    return !strcmp(RFC,RFCAUX);
}

bool Persona::vacio()
{
    return !strcmp(nombre,"null");
}



ostream& operator<<(ostream& os,Persona& p)
{
    os<<"Nombre: "<<p.nombre<<" RFC: "<<p.RFC<<" Domicilio: "<<p.domicilio<<" Telefono: "<<p.telefono<<endl;
    return os;
}//sobre cargado  de <<
