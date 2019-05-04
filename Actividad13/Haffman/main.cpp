#include <iostream>
#include <hofmann.h>

using namespace std;

int main()
{
    LDL<char> aux;

    aux.push('a',30);
    aux.push('b',20);
    aux.push('c',10);

    cout<<"Size: "<<aux.size()<<endl;

    for(size_t i=0;i<aux.size();i++){
        cout<<aux[i]<<endl;
    }
    return 0;
}
