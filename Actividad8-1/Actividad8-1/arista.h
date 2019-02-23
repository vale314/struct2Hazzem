#ifndef ARISTA_H
#define ARISTA_H


class Arista
{
private:
    int peso;
    int origen;
    int destino;
public:
    Arista();

    int getOrigen() const;
    void setOrigen(int value);

    int getPeso() const;
    void setPeso(int value);

    int getDestino() const;
    void setDestino(int value);
};

#endif // ARISTA_H
