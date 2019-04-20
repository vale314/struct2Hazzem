#include <iostream>
#include "abb.h"

using namespace std;

int main()
{
    /*ABB<int> arbol(52);
    arbol.insert(28);
    arbol.insert(74);
    arbol.insert(13);
    arbol.insert(40);
    arbol.insert(63);
    arbol.insert(86);
    arbol.insert(4);
    arbol.insert(21);
    arbol.insert(32);
    arbol.insert(46);
    arbol.insert(57);
    arbol.insert(71);
    arbol.insert(93);
    arbol.insert(2);
    arbol.insert(7);
    arbol.insert(16);
    arbol.insert(24);
    arbol.insert(29);
    arbol.insert(37);
    arbol.insert(50);
    arbol.insert(54);
    cout<<"Dato: " <<arbol.getData() <<endl;
    */
    ABB<int> arbol(10);
    arbol.insert(5);
    arbol.insert(3);
    arbol.insert(8);
    arbol.insert(6);
    arbol.insert(9);
    arbol.insert(7);
    arbol.insert(15);
    arbol.insert(12);
    arbol.insert(20);
    arbol.insert(30);

    arbol.mostrar();
    arbol.erase(5);
    arbol.erase(20);
    arbol.erase(9);
    arbol.erase(3);
    cout<<endl<<endl;
    arbol.mostrar();

    system("pause");
    /*

    cout <<"Vacío: " <<arbol.isNull() <<endl
        <<"Hoja: " <<arbol.isLeaf() <<endl
       <<"Dato: " <<arbol.getData() <<endl;
    arbol.inOrder();
*/
    return 0;
}
