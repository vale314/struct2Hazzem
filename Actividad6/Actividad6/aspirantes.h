#ifndef ASPIRANTES_H
#define ASPIRANTES_H
#include <string>

using namespace std;

class Aspirantes
{
private:
    string curp;
    string nombre;
    string edad;
    string puesto;
    int bandera;
public:
    Aspirantes();

    string getCurp() const;
    void setCurp(const string &value);
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
