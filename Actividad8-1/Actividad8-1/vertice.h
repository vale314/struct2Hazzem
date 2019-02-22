#ifndef VERTICE_H
#define VERTICE_H
#include <string>

using namespace std;

class Vertice
{
private:
    string nombre;
    int numVertice;
public:
    Vertice();
    Vertice(string,int);


    string getNombre() const;
    void setNombre(const string &value);

    int getNumVertice() const;
    void setNumVertice(int value);

    bool compareNombre() const;
    bool compareNumVertice() const;
};

#endif // VERTICE_H
