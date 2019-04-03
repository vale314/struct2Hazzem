#ifndef PERSONA_H
#define PERSONA_H
#include <string.h>
#include <iostream>

#define TAMNOMBRE 50
#define TAMDOMI 50
#define TAMRFC 7

using namespace std;

class Persona
{
private:
    char RFC[7];
    char nombre[50];
    char domicilio[50];
    char telefono[30];
public:
    Persona();

    void setDomicilio(const char[50]);
    char *getDomicilio();

    void setRFC(const char[7]);
    char *getRFC();

    void setNombre(const char[50]);
    char *getNombre();

    char* getTelefono();
    void setTelefono(const char [30]);

    int generateAscii();
    long long posicion();

    friend ostream& operator<<(ostream& os,Persona& p);
};



#endif // PERSONA_H
