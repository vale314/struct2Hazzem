#ifndef INDICE_H
#define INDICE_H
#include <string>

using namespace std;

class Indice
{
private:
    string id;
    long long pos;
public:
    Indice();

    long long getPos() const;
    void setPos(long long value);
    string getId() const;
    void setId(const string &value);
};

#endif // INDICE_H
