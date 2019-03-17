#ifndef DIRECCION_H
#define DIRECCION_H


class Direccion
{
private:
    int id;
    long long pos;
public:
    Direccion();

    Direccion *siguiente;
    int getId() const;
    void setId(int value);

    long long getPos() const;
    void setPos(long long value);
};

#endif // DIRECCION_H
