#ifndef TDAGENEROS_H
#define TDAGENEROS_H
#include <string.h>
#define TAM 20

using namespace std;

class TdaGeneros
{
private:
    char genero[TAM];
    int pos;
public:
    TdaGeneros();

    char *getGenero();
    void setGenero(char genero[TAM]);


    int getPos();
    void setPos(int);
};

#endif // TDAGENEROS_H
