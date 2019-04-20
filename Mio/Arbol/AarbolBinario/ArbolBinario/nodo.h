#ifndef NODO_H
#define NODO_H

struct Nodo
{
    T dato;
    Nodo* izq;
    Nodo* der;

    Nodo(const T& element,
            Nodo* i = nullptr,
            Nodo* d = nullptr) :
        dato(element),
        izq(i),
        der(d) {}
};

#endif // NODO_H
