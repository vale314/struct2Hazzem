#ifndef LISTA_INVERTIDA_H
#define LISTA_INVERTIDA_H
#include <string.h>

using namespace std;

class Lista_Invertida
{
private:
    int id;
public:
    Lista_Invertida *siguiente;
    Lista_Invertida *nextCategoria;

    Lista_Invertida();

    int getId();
    void setId(int value);
};

#endif // LISTA_INVERTIDA_H
