#ifndef NODOLDL_H
#define NODOLDL_H

struct NodoLDL
{
    T dato;
    NodoLDL* siguiente;
    NodoLDL* anterior;

    NodoLDL(const T& elem,
            NodoLDL* ant = nullptr,
            NodoLDL* sig= nullptr):
        dato(elem),
        siguiente(sig),
        anterior(ant)
    {}
};

#endif // NODOLDL_H
