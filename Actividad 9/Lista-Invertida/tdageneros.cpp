#include "tdageneros.h"

TdaGeneros::TdaGeneros()
{

}

char *TdaGeneros::getGenero()
{
    return genero;
}

void TdaGeneros::setGenero(char genero[TAM])
{
    strcpy(this->genero,genero);
}

int TdaGeneros::getPos()
{
    return pos;
}

void TdaGeneros::setPos(int pos)
{
    this->pos=pos;
}
