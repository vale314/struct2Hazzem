#ifndef INDICE_H
#define INDICE_H
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

class Indice
{
private:
    char id[5];
    long long pos;
    int contador;
public:
    Indice();

    long long getPos() const;
    void setPos(long long value);
    const char* getId() const;
    void setId(const char value[5]);


    bool operator <(const Indice& d) {
             if(strcmp(id,d.id)==-1&&strcmp(d.id,"-1")!=0)
                return true;
             return false;
          }
    bool operator >(const Indice& d) {
             if((strcmp(id,d.id)==1))
                return true;
             return false;
          }
    friend bool operator ==(const Indice& lhs, const Indice& rhs)
    {
        return !(strcmp(lhs.getId(),rhs.getId()));
    }

    friend ostream& operator<<(std::ostream& os, const Indice& indice) {
              os<<indice.getId()<<"   "<<indice.getPos()<<endl;
              return os;
    }
};

#endif // INDICE_H
