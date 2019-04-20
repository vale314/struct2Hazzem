#ifndef ABB_H
#define ABB_H
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class ABB
{
public:
    ABB<T>() : root(nullptr) {}
    ABB<T>(const T& elem,
           const ABB& left = ABB(),
           const ABB& right = ABB()) :
        root(new Nodo(elem, left.root, right.root)) {}

    bool isNull() const;
    bool isLeaf() const;
    ABB<T> getLeftSubtree() const;
    ABB<T> getRightSubtree() const;
    const T& getData() const;
    const T* find(const T& elem) const;
    bool insert(const T& elem);
    void inOrder();
    bool erase(const T& elem);
    void mostrar();

private:
#include "nodo.h"
    ABB<T>(Nodo* newRoot) : root(newRoot) {}

    const T* find(Nodo* localRoot, const T& elem) const;
    bool insert(Nodo*& localRoot, const T& elem);
    void inOrder(Nodo *localRoot);
    bool erase(Nodo*& localRoot, const T& elem);
    void mostrar(Nodo* localRoot,int);
    void replaceParent(Nodo*& oldRoot, Nodo*& localRoot);
    Nodo* root;
};

template<typename T>
bool ABB<T>::isNull() const
{
    return root == nullptr;
}

template<typename T>
bool ABB<T>::isLeaf() const
{
    if (!isNull())
        return root->izq == nullptr && root->der == nullptr;

    return true;
}

template<typename T>
ABB<T> ABB<T>::getLeftSubtree() const
{
    if (isNull())
        throw invalid_argument("getLeftSubtree() on empty tree");

    return ABB(root->izq);
}

template<typename T>
ABB<T> ABB<T>::getRightSubtree() const
{
    if (isNull())
        throw invalid_argument("getRightSubtree() on empty tree");

    return ABB(root->der);
}

template<typename T>
const T& ABB<T>::getData() const
{
    if (isNull())
        throw invalid_argument("getData() on empty tree");

    return root->dato;
}

template<typename T>
const T* ABB<T>::find(const T &elem) const
{
    return find(root, elem);
}

template<typename T>
const T* ABB<T>::find(Nodo *localRoot, const T &elem) const
{
    if (localRoot == nullptr)
        return nullptr;
    else if (elem < localRoot->dato)
        return find(localRoot->izq, elem);
    else if (elem > localRoot->dato)
        return find(localRoot->der, elem);
    else
        return &(localRoot->dato);
}

template<typename T>
bool ABB<T>::insert(const T &elem)
{
    return insert(root, elem);
}

template<typename T>
bool ABB<T>::insert(Nodo *&localRoot, const T &elem)
{
    if (localRoot == nullptr)
    {
        localRoot = new Nodo(elem);
        return true;
    }
    else if (elem < localRoot->dato)
        return insert(localRoot->izq, elem);
    else if (elem > localRoot->dato)
        return insert(localRoot->der, elem);
    else
        return false;
}

template<typename T>
void ABB<T>::inOrder()
{
    inOrder(root);
}

template<typename T>
void ABB<T>::inOrder(Nodo *localRoot)
{
    if (localRoot == nullptr)
        return;
    inOrder(localRoot->izq);
    cout<< localRoot->dato <<endl;
    inOrder(localRoot->der);
}

template<typename T>
bool ABB<T>::erase(const T &elem)
{
    return erase(root, elem);
}

template<typename T>
void ABB<T>::mostrar()
{
    int contador=0;
    if(root==nullptr)
        return;
    mostrar(root,contador);
}

template<typename T>
void ABB<T>::mostrar(Nodo *localRoot, int contador)
{
    if(localRoot==nullptr)
        return;
    mostrar(localRoot->der,contador+1);
    for(int i=0;i<contador;i++)
        cout<<"   ";
    cout<<localRoot->dato<<endl;
    mostrar(localRoot->izq,contador+1);
}

template<typename T>
bool ABB<T>::erase(Nodo *&localRoot, const T &elem)
{
    if (localRoot == nullptr)
        return false;
    else if (elem < localRoot->dato)
        return erase(localRoot->izq, elem);
    else if (elem > localRoot->dato)
        return erase(localRoot->der, elem);
    else
    {
        Nodo* oldRoot = localRoot;
        if (localRoot->izq == nullptr)
            localRoot = localRoot->der;
        else if (localRoot->der == nullptr)
            localRoot = localRoot->izq;
        else
            replaceParent(oldRoot, oldRoot->izq);
        delete oldRoot;
        return true;
    }
}

template<typename T>
void ABB<T>::replaceParent(Nodo *&oldRoot, Nodo *&localRoot)
{
    if (localRoot->der != nullptr)
        replaceParent(oldRoot, localRoot->der);
    else
    {
        oldRoot->dato = localRoot->dato;
        //oldRoot=oldRoot->der
        //oldRoot->iz
        oldRoot = localRoot;
        localRoot = localRoot->izq;
    }
}

#endif // ABB_H
