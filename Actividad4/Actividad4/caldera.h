#ifndef CALDERA_H
#define CALDERA_H


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

private:
    int codigo;
    double temperatura;
    int numEmpleado;
    int contador;
    int bandera;
};

#endif // CALDERA_H
