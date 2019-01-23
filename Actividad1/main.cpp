#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdexcept>
#include <iomanip>


using namespace std;


enum{
    menuPlatillo=1,
    menuVer,
    menuSalir
};

struct estrPlatillo{
    string nombre;
    string descripcion;
    string precio;
    string id;
};

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
            getline(leer,oldPlatillo.id,';');
            if(leer.eof())
                break;

        }
        return stoi(oldPlatillo.id);
}

void escribirFunc(estrPlatillo newPlatillo){
    if(vacioFunc()){
        ofstream escribir("Platillos.txt",ios::app);
        escribir <<newPlatillo.nombre <<"#"<<newPlatillo.descripcion<<"#"<<newPlatillo.precio<<"#"<<"0"<<";";
    }else{
        ofstream escribir("Platillos.txt",ios::app);
        escribir <<newPlatillo.nombre <<"#"<<newPlatillo.descripcion<<"#"<<newPlatillo.precio<<"#"<<numerosId()+1<<";";
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
            getline(leer,oldPlatillo.id,';');
            if(leer.eof())
                break;
            cout<<setw(20)<<oldPlatillo.nombre<<setw(20)<<oldPlatillo.descripcion<<setw(20)<<oldPlatillo.precio<<setw(29)<<oldPlatillo.id<<endl;
        }
        cout<<endl<<endl;
    }
}




int main()
{
    size_t opc;
    opc=0;
    estrPlatillo newPlatillo;
    cout <<"Restaurante"<<endl;
    do{
        cout<<menuPlatillo<<"- Crear Platillo"<<endl
            <<menuVer<<"- Ver Todos Los Platillos"<<endl
            <<menuSalir<<"- Salir"<<endl;
            cin>>opc;
        switch (opc) {

            case menuVer:
            imprimirFunc();
            break;

            case menuSalir:
            break;

            case menuPlatillo:
                cout<<"Ingrese el nombre"<<endl;
                cin>>newPlatillo.nombre;
                cout<<"Ingrse la descripcion"<<endl;
                cin>>newPlatillo.descripcion;
                cout<<"Ingrese Precio"<<endl;
                cin>>newPlatillo.precio;
                escribirFunc(newPlatillo);
                break;

        }
    }while (opc != 3);

}
