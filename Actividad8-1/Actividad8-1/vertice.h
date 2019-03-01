#ifndef VERTICE_H
#define VERTICE_H
#include <string>
#include <string.h>

using namespace std;

class Vertice
{
private:
    char nombre[20];
    int numVertice;
public:
    Vertice();
    Vertice(const char[10],int);
    Vertice(string,int);

    int getNumVertice() const;
    void setNumVertice(int value);

    bool compareNombre() const;
    bool compareNumVertice() const;

    const char *getNombre()const;
    void setNombre(const char[10]);

    bool operator <=(const Vertice& d) {
              if(strcmp(nombre, d.nombre))
                 return true;
              return false;
           }
};

#endif // VERTICE_H
