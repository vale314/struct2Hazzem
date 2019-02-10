#ifndef ASPIRANTES_H
#define ASPIRANTES_H
#include <string>
#include <iostream>

using namespace std;

class Aspirantes
{
private:
    char curp[4];
    string nombre;
    string edad;
    string puesto;
    int bandera;
public:
    Aspirantes();
    const char* getCurp()const;
    void setCurp(const char value[4]);
    string getNombre() const;
    void setNombre(const string &value);
    string getEdad() const;
    void setEdad(const string &value);
    string getPuesto() const;
    void setPuesto(const string &value);
    int getBandera() const;
    void setBandera(int value);
};

#endif // ASPIRANTES_H
