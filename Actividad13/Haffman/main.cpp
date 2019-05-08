#include <iostream>
#include <hofmann.h>
#define SOH "\x01"


using namespace std;

int main()
{

    HFF<char> aux;
//    aux.push('L',1);
//    aux.push('a',6);
//    aux.push(' ',6);
//    aux.push('r',4);
//    aux.push('u',2);
//    aux.push('t',4);
//    aux.push('n',2);
//    aux.push('o',5);
//    aux.push('s',2);
//    aux.push('p',2);
//    aux.push('l',1);
//    aux.push('.',1);
//    aux.push('\xF3',1);

//    aux.push('V',1);
//    aux.push('I',2);
//    aux.push('L',2);
//    aux.push('N',2);
//    aux.push(' ',3);
//    aux.push('A',6);
//    aux.push('T',2);
//    aux.push('.',1);

    // Agrega El Dato
    string var="papas#a la francesa#13.00#0#1;hamburguesa#con tocino#37.00#1#1;";
    aux.add(var);

    cout<<"Size: "<<aux.size()<<endl;

    cout<<endl<<endl<<endl;

    //crea el arbol
    aux.tree();

    cout<<"Size: "<<aux.size()<<endl;

    //muestra el arbol
    aux.showTree();

    aux.createBinary();


    return 0;
}
