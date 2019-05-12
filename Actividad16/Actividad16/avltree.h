#ifndef AVLTREE_H
#define AVLTREE_H
#include <algorithm>
#include <iostream>
#include "nodoavl.h"
#include <ldl.h>
#include <iostream>

/* AVL tree */
template <class T>
class AVLtree {
public:
    AVLtree(void);
    ~AVLtree(void);
    bool insert(T key);
    void deleteKey(const T key);
    void printBalance();
    void mostrar();
    void inOrder();
    int cantidad();
    Ldl<T> getAllItems();
    const T* find(const T& elem) const;


private:
    AVLnode<T> *root;
    AVLnode<T>* rotateLeft          ( AVLnode<T> *a );
    AVLnode<T>* rotateRight         ( AVLnode<T> *a );
    AVLnode<T>* rotateLeftThenRight ( AVLnode<T> *n );
    AVLnode<T>* rotateRightThenLeft ( AVLnode<T> *n );
    void rebalance                  ( AVLnode<T> *n );
    int height                      ( AVLnode<T> *n );
    void setBalance                 ( AVLnode<T> *n );
    void printBalance               ( AVLnode<T> *n );
    void clearNode                  ( AVLnode<T> *n );
    void getAllItems                ( AVLnode<T> *n );
    int cantidad                    (AVLnode<T>*);
    void mostrar                    (AVLnode<T>* localRoot,int contador);
    const T* find                   (AVLnode<T>* ,const T& elem) const;
    void inOrder                    (AVLnode<T> *localRoot);
    int cant=0;
    Ldl<T> allItems;

};

/* AVL class definition */
template <class T>
void AVLtree<T>::rebalance(AVLnode<T> *n) {
    setBalance(n);

    if (n->balance == -2) {
        if (height(n->left->left) >= height(n->left->right))
            n = rotateRight(n);
        else
            n = rotateLeftThenRight(n);
    }
    else if (n->balance == 2) {
        if (height(n->right->right) >= height(n->right->left))
            n = rotateLeft(n);
        else
            n = rotateRightThenLeft(n);
    }

    if (n->parent != NULL) {
        rebalance(n->parent);
    }
    else {
        root = n;
    }
}

template <class T>
AVLnode<T>* AVLtree<T>::rotateLeft(AVLnode<T> *a) {
    AVLnode<T> *b = a->right;
    b->parent = a->parent;
    a->right = b->left;

    if (a->right != NULL)
        a->right->parent = a;

    b->left = a;
    a->parent = b;

    if (b->parent != NULL) {
        if (b->parent->right == a) {
            b->parent->right = b;
        }
        else {
            b->parent->left = b;
        }
    }

    setBalance(a);
    setBalance(b);
    return b;
}

template <class T>
AVLnode<T>* AVLtree<T>::rotateRight(AVLnode<T> *a) {
    AVLnode<T> *b = a->left;
    b->parent = a->parent;
    a->left = b->right;

    if (a->left != NULL)
        a->left->parent = a;

    b->right = a;
    a->parent = b;

    if (b->parent != NULL) {
        if (b->parent->right == a) {
            b->parent->right = b;
        }
        else {
            b->parent->left = b;
        }
    }

    setBalance(a);
    setBalance(b);
    return b;
}

template <class T>
AVLnode<T>* AVLtree<T>::rotateLeftThenRight(AVLnode<T> *n) {
    n->left = rotateLeft(n->left);
    return rotateRight(n);
}

template <class T>
AVLnode<T>* AVLtree<T>::rotateRightThenLeft(AVLnode<T> *n) {
    n->right = rotateRight(n->right);
    return rotateLeft(n);
}

template <class T>
int AVLtree<T>::height(AVLnode<T> *n) {
    if (n == NULL)
        return -1;
    return 1 + std::max(height(n->left), height(n->right));
}

template <class T>
void AVLtree<T>::setBalance(AVLnode<T> *n) {
    n->balance = height(n->right) - height(n->left);
}

template <class T>
void AVLtree<T>::printBalance(AVLnode<T> *n) {
    if (n != NULL) {
        printBalance(n->left);
        std::cout << n->balance << " ";
        printBalance(n->right);
    }
}

template<class T>
void AVLtree<T>::getAllItems(AVLnode<T> *n)
{
    if (n == nullptr)
        return;
    getAllItems(n->left);
    allItems.push_back(n->key);
    getAllItems(n->right);
}

template<class T>
int AVLtree<T>::cantidad(AVLnode<T> * localRoot)
{
    if (localRoot == nullptr)
        return 0;
    cantidad(localRoot->left);
    cant++;
    cantidad(localRoot->right);
}

template<class T>
int AVLtree<T>::cantidad()
{
    cant=0;
    cantidad(root);
    return cant;
}

template<class T>
Ldl<T> AVLtree<T>::getAllItems()
{
    allItems.clear();
    getAllItems(root);
    return allItems;
}

template<class T>
void AVLtree<T>::mostrar(AVLnode<T> *localRoot, int contador)
{
    if(localRoot==nullptr)
        return;
    mostrar(localRoot->right,contador+1);
    for(int i=0;i<contador;i++)
        std::cout<<"   ";
    std::cout<<localRoot->key<<std::endl;
    mostrar(localRoot->left,contador+1);
}


template <class T>
AVLtree<T>::AVLtree(void) : root(NULL) {}

template <class T>
AVLtree<T>::~AVLtree(void) {
    delete root;
}

template <class T>
bool AVLtree<T>::insert(T key) {
    if (root == NULL) {
        root = new AVLnode<T>(key, NULL);
    }
    else {
        AVLnode<T>
            *n = root,
            *parent;

        while (true) {
            if (n->key == key){
                return false;
            }

            parent = n;

            bool goLeft = n->key > key;
            n = goLeft ? n->left : n->right;

            if (n == NULL) {
                if (goLeft) {
                    parent->left = new AVLnode<T>(key, parent);
                }
                else {
                    parent->right = new AVLnode<T>(key, parent);
                }

                rebalance(parent);
                break;
            }
        }
    }

    return true;
}

template <class T>
void AVLtree<T>::deleteKey(const T delKey) {
    if (root == NULL)
        return;

    AVLnode<T>
        *n       = root,
        *parent  = root,
        *delNode = NULL,
        *child   = root;

    while (child != NULL) {
        parent = n;
        n = child;
        child = delKey >= n->key ? n->right : n->left;
        if (delKey == n->key)
            delNode = n;
    }

    if (delNode != NULL) {
        delNode->key = n->key;

        child = n->left != NULL ? n->left : n->right;

        if (root->key == delKey) {
            root = child;
        }
        else {
            if (parent->left == n) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }

            rebalance(parent);
        }
    }
}

template <class T>
void AVLtree<T>::printBalance() {
    printBalance(root);
    std::cout << std::endl;
}

template<class T>
void AVLtree<T>::mostrar()
{
    int contador=0;
    if(root==nullptr)
        return;
    mostrar(root,contador);

}

template<class T>
const T *AVLtree<T>::find(AVLnode<T>* localRoot,const T &elem) const
{
    if (localRoot == nullptr)
        return nullptr;
    else if (elem < localRoot->key)
        return find(localRoot->left, elem);
    else if (elem > localRoot->key)
        return find(localRoot->right, elem);
    else
        return &(localRoot->key);
}

template<class T>
const T *AVLtree<T>::find(const T& elem) const
{
    return find(root,elem);
}


template<typename T>
void AVLtree<T>::inOrder()
{
    inOrder(root);
}


template<typename T>
void AVLtree<T>::inOrder(AVLnode<T> *localRoot)
{
    if (localRoot == nullptr)
        return;
    inOrder(localRoot->left);
    std::cout<< localRoot->key<<std::endl;
    inOrder(localRoot->right);
}


#endif // AVLTREE_H
