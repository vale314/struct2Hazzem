#ifndef NODOLDL_H
#define NODOLDL_H

struct NodoLdl
{
    T dato;
    NodoLdl* siguiente;
    NodoLdl* anterior;

    NodoLdl(const T& elem,
            NodoLdl* ant = nullptr,
            NodoLdl* sig= nullptr):
        dato(elem),
        siguiente(sig),
        anterior(ant)
    {}
};

#endif // NODOLDL_H
