#include <iostream>
#include <hofmann.h>
#define SOH "\x01"


using namespace std;

int main()
{

    LDL<char> aux;

    aux.push('L',1);
    aux.push('a',6);
    aux.push(' ',6);
    aux.push('r',4);
    aux.push('u',2);
    aux.push('t',4);
    aux.push('n',2);
    aux.push('o',5);
    aux.push('s',2);
    aux.push('p',2);
    aux.push('l',1);
    aux.push('.',1);

    /*
    aux.push('\x01',10);
    aux.push('\x01',10);*/

    cout<<"Size: "<<aux.size()<<endl;

    for(size_t i=0;i<aux.size();i++){
        cout<<aux[i]<<endl;
    }
    return 0;
}
