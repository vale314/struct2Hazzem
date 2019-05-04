#include <iostream>
#include <hofmann.h>

using namespace std;

int main()
{
    LDL<char> aux;

    aux.push('a',30);
    aux.push('b',20);
    aux.push('s',35);
    aux.push('c',10);
    aux.push('d',40);
    aux.push('f',35);
    aux.push('g',45);
    aux.push('i',1);
    aux.push('e',35);

    cout<<"Size: "<<aux.size()<<endl;

    for(size_t i=0;i<aux.size();i++){
        cout<<aux[i]<<endl;
    }
    return 0;
}
