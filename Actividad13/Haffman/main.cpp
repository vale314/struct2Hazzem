#include <iostream>
#include <hofmann.h>
#define SOH "\x01"


using namespace std;

int main()
{

    HFF<char> aux;

    string var="papas#a la francesa#13.00#0#1;hamburguesa#con tocino#37.00#1#1;";
    aux.encrypt(var);

    aux.descryptText("Mandamos el texto");

    return 0;
}
