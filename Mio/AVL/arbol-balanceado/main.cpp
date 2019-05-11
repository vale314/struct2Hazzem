#include <iostream>
#include <avltree.h>

using namespace std;

int main()
{
    AVLtree<int> arbol;

    arbol.insert(10);
    arbol.insert(5);
    arbol.insert(13);
    arbol.insert(1);
    arbol.insert(6);
    arbol.insert(17);
    arbol.insert(16);


    arbol.mostrar();

    arbol.deleteKey(16);

    arbol.mostrar();



    return 0;
}
