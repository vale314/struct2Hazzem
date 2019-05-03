#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <cstring>


using namespace std;


enum{
    menuPlatillo=1,
    menuVer,
    menuCifradoCesar,
    menuCifradoXor,
    menuDesifradoCesar,
    menuDesifradoXor,
    menuSalir
};

struct estrPlatillo{
    string nombre;
    string descripcion;
    string precio;
    string id;
};

int tam=0;

bool vacioFunc(){
    ifstream leer("Platillos.txt");
    if(!leer.good())
        return true;
    else
        return false;

}

int numerosId(){
    ifstream leer("Platillos.txt");
    estrPlatillo oldPlatillo;
    if(!leer.good())
        throw invalid_argument("Error No Encontrado");
    else
        while(!leer.eof()){
            getline(leer,oldPlatillo.nombre,'#');
            getline(leer,oldPlatillo.descripcion,'#');
            getline(leer,oldPlatillo.precio,'#');
            getline(leer,oldPlatillo.id,'$');
            if(leer.eof())
                break;

        }
        return stoi(oldPlatillo.id);
}

void escribirFunc(estrPlatillo newPlatillo){
    if(vacioFunc()){
        ofstream escribir("Platillos.txt",ios::app);
        escribir <<newPlatillo.nombre <<"#"<<newPlatillo.descripcion<<"#"<<newPlatillo.precio<<"#"<<"0"<<"$";
    }else{
        ofstream escribir("Platillos.txt",ios::app);
        escribir <<newPlatillo.nombre <<"#"<<newPlatillo.descripcion<<"#"<<newPlatillo.precio<<"#"<<numerosId()+1<<"$";
    }
}

void imprimirFunc(){
    estrPlatillo oldPlatillo;
    ifstream leer("Platillos.txt");
    if(vacioFunc()){
        cout<<"No Se Encuentra Archivo"<<endl;
        return;
    }else{
        system("cls");
        cout<<setw(20)<<"NOMBRE"<<setw(20)<<"DESCRIPCION"<<setw(20)<<"PRECIO"<<setw(29)<<"ID"<<endl<<endl<<endl;
        while(!leer.eof()){
            getline(leer,oldPlatillo.nombre,'#');
            getline(leer,oldPlatillo.descripcion,'#');
            getline(leer,oldPlatillo.precio,'#');
            getline(leer,oldPlatillo.id,'$');
            if(leer.eof())
                break;
            cout<<setw(20)<<oldPlatillo.nombre<<setw(20)<<oldPlatillo.descripcion<<setw(20)<<oldPlatillo.precio<<setw(29)<<oldPlatillo.id<<endl;
        }
        cout<<endl<<endl;
    }
}

void cifradoCesar(){
    string aux;
    ifstream entrada("Platillos.txt",ios::in);
    while(getline(entrada,aux)) {
        if(entrada.eof())
            break;
        aux += aux;
    }
    entrada.close();

    char auxC[aux.size()];
    strcpy(auxC,aux.c_str());

    char auxFraseNew[aux.size()];
    for (size_t i = 0; i < aux.size(); i++)
           auxFraseNew[i]=aux[i]+3;

    for (size_t i = 0; i < aux.size(); i++)
           cout<<auxFraseNew[i];

    cout<<endl;
    remove("Platillos.txt");

    ofstream escribir("Platillos.txt",ios::app);
    escribir <<auxFraseNew;
    escribir.close();
}

void desifradoCesar(){
    string aux;
    ifstream entrada("Platillos.txt",ios::in);
    while(getline(entrada,aux)) {
        if(entrada.eof())
            break;
        aux += aux;
    }
    entrada.close();

    char auxC[aux.size()+1];
    strcpy(auxC,aux.c_str());

    char auxFraseNew[aux.size()+1];
    for (size_t i = 0; i < aux.size(); i++)
           auxFraseNew[i]=aux[i]-3;

    for (size_t i = 0; i < aux.size(); i++)
           cout<<auxFraseNew[i];

    remove("Platillos.txt");

    cout<<endl;
    ofstream escribir("Platillos.txt",ios::app);
    escribir <<auxFraseNew;
    escribir.close();
}

void cifradoXor(){
    string aux;
    ifstream entrada("Platillos.txt",ios::in);
    while(getline(entrada,aux)) {
        if(entrada.eof())
            break;
        aux += aux;
    }
    entrada.close();

    char auxC[aux.size()+1];
    strcpy(auxC,aux.c_str());

    char auxFraseNew[aux.size()+1];
    for (size_t i = 0; i < aux.size(); i++)
        auxFraseNew[i]=aux[i]^'@';

    for (size_t i = 0; i < aux.size(); i++)
           cout<<auxFraseNew[i];

    cout<<endl;
    remove("Platillos.txt");

    ofstream escribir("Platillos.txt",ios::app);
    escribir <<auxFraseNew;
    escribir.close();
}

int main()
{
    size_t opc;
    opc=0;
    estrPlatillo newPlatillo;
    cout <<"Restaurante"<<endl;
    do{
        system("cls");
        cout<<menuPlatillo<<"- Crear Platillo"<<endl
            <<menuVer<<"- Ver Todos Los Platillos"<<endl
            <<menuCifradoCesar<<"- Cifrado Cesar"<<endl
            <<menuCifradoXor<<"- Cifrado Xor"<<endl
            <<menuDesifradoCesar<<"- Desifrado Cesar"<<endl
            <<menuDesifradoXor<<"- Desifrado Xor"<<endl
            <<menuSalir<<"- Salir"<<endl;
            cin>>opc;
        switch (opc) {

            case menuVer:
            imprimirFunc();
            break;

            case menuSalir:
            break;

            case menuCifradoCesar:
                cifradoCesar();
            break;

            case menuCifradoXor:
                cifradoXor();
            break;

            case menuDesifradoCesar:
                desifradoCesar();
            break;

            case menuDesifradoXor:
                cifradoXor();
            break;

            case menuPlatillo:
                cin.ignore();
                cout<<"Ingrese el nombre"<<endl;
                getline(cin,newPlatillo.nombre);
                cout<<"Ingrse la descripcion"<<endl;
                getline(cin,newPlatillo.descripcion);
                cout<<"Ingrese Precio"<<endl;
                getline(cin,newPlatillo.precio);
                escribirFunc(newPlatillo);
                break;

        }
    system("pause");
    }while (opc != menuSalir);

}
