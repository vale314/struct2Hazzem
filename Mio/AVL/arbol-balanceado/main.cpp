#include <iostream>
#include <avltree.h>
#include <ldl.h>

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
    cout<<"duplicado el 16: "<<arbol.insert(16)<<endl;

    cout<<*arbol.find(17)<<endl;

    arbol.mostrar();

    arbol.deleteKey(16);

    cout<<endl<<endl;

    arbol.mostrar();

    arbol.inOrder();

    cout<<"Cantidad: "<<arbol.cantidad()<<endl;

    Ldl<int> tree(arbol.getAllItems());

    for(size_t i=0;i<tree.size();i++)
        cout<<"Elemento: "<<tree[i]<<endl;

    return 0;
}
