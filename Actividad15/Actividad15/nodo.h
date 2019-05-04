#ifndef NODOLDL_H
#define NODOLDL_H

struct NodoHFF
{
    int frecuencia;
    T dato;
    NodoHFF* anterior;
    NodoHFF* siguiente;
    NodoHFF* izq;
    NodoHFF* der;

    NodoHFF(const T& elem,
            const int frec=0,
            NodoHFF* ant = nullptr,
            NodoHFF* sig= nullptr,
            NodoHFF* izquierda=nullptr,
            NodoHFF* derecha=nullptr):
        dato(elem),
        frecuencia(frec),
        anterior(ant),
        siguiente(sig),
        izq(izquierda),
        der(derecha)
    {}
};

#endif // NODOLDL_H
