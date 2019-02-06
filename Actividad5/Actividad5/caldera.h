#ifndef CALDERA_H
#define CALDERA_H
#include <iostream>

using namespace std;


class Caldera
{
public:
    Caldera();
    int getCodigo() const;
    void setCodigo(int value);

    double getTemperatura() const;
    void setTemperatura(double value);

    int getNumEmpleado() const;
    void setNumEmpleado(int value);

    int getContador() const;
    void setContador(int value);

    int getBandera() const;
    void setBandera(int value);

    bool operator >(const Caldera& d) {
             if(codigo > d.codigo)
                return true;
             return false;
          }

    bool operator <=(const Caldera& d) {
             if(codigo <= d.codigo)
                return true;
             return false;
          }

    friend ostream& operator<<(ostream& os, const Caldera& dt){
        os <<"Codigo: "<< dt.codigo <<" Temperatura: "<< dt.temperatura <<" NumEm: "<<dt.numEmpleado<< " Contador: " << dt.contador;
           return os;
    }
private:
    int codigo;
    double temperatura;
    int numEmpleado;
    int contador;
    int bandera;
};

#endif // CALDERA_H
