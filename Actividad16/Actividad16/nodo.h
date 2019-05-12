#ifndef NODOLDL_H
#define NODOLDL_H

struct NodoHFF
{
    int frecuencia;
    T dato;
    string tipo;
    NodoHFF* anterior;
    NodoHFF* siguiente;
    NodoHFF* izq;
    NodoHFF* der;
    NodoHFF* padre;
    NodoHFF(const T& elem,
            const int frec=0,
            NodoHFF* ant = nullptr,
            NodoHFF* sig= nullptr,
            NodoHFF* izquierda=nullptr,
            NodoHFF* derecha=nullptr,
            NodoHFF* father=nullptr):
        dato(elem),
        frecuencia(frec),
        anterior(ant),
        siguiente(sig),
        izq(izquierda),
        der(derecha),
        padre(father)
    {tipo="2";}
};

#endif // NODOLDL_H
