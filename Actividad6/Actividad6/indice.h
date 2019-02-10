#ifndef INDICE_H
#define INDICE_H
#include <string>
#include <iostream>

using namespace std;

class Indice
{
private:
    char id[4];
    long long pos;
public:
    Indice();

    long long getPos() const;
    void setPos(long long value);
    const char* getId() const;
    void setId(const char value[4]);
};

#endif // INDICE_H
