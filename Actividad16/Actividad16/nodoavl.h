#ifndef NODOAVL_H
#define NODOAVL_H

//struct AVLnode
//{
//    T key;
//    int balance;
//    AVLnode *left, *right, *parent;

//    AVLnode(const T& k,int b=0,AVLnode *p=nullptr, AVLnode *l=nullptr, AVLnode* r=nullptr) :
//        key(k), balance(b), parent(p),left(l), right(r) {}

//    ~AVLnode() {
//        delete left;
//        delete right;
//    }
//};

template <class T>
class AVLnode {
public:
    T key;
    int contador;
    int balance;
    AVLnode *left, *right, *parent;

    AVLnode(T k, AVLnode *p) : key(k), balance(0), parent(p),left(NULL), right(NULL) {
        contador=0;
    }

    ~AVLnode() {
        delete left;
        delete right;
    }
};

#endif // NODOAVL_H
