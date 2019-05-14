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
    Indice(const char[5],long long pos ,int contador);

    long long getPos() const;
    void setPos(long long value);
    const char* getId() const;
    void setId(const char value[5]);

    friend bool operator >=(const Indice& a,const Indice& d) {
             if((strcmp(a.id,d.id)>0)||!(strcmp(a.getId(),d.getId())))
                return true;
             return false;
          }

    friend bool operator <(const Indice& a,const Indice& d) {
//             if(strcmp(a.id,d.id)==-1&&strcmp(d.id,"-1")!=0)
                if(strcmp(a.getId(),d.getId())<0)
                return true;
             return false;
          }
    friend bool operator >(const Indice& a,const Indice& d) {
             if((strcmp(a.id,d.id)>0))
                return true;
             return false;
          }
    friend bool operator ==(const Indice& lhs, const Indice& rhs)
    {
        return !(strcmp(lhs.getId(),rhs.getId()));
    }

    friend ostream& operator<<(std::ostream& os, const Indice& indice) {
              os<<indice.getId()<<"   "<<indice.getContador()<<endl;
              return os;
    }
    int getContador() const;
    void setContador(int value);
};

#endif // INDICE_H
