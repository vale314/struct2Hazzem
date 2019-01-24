#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdexcept>
#include <iomanip>
#include <string.h>

using namespace std;


enum{
    menuPlatillo=1,
    menuVer,
    menuBuscar,
    menuEliminar,
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

bool buscarFunc(estrPlatillo *oldPlatillo){
    string nombre;
    bool encontrado;


    ifstream leer("Platillos.txt");

    cout<<"Ingrese El Nombre Ha Buscar"<<endl;
    cin>>nombre;

    if(vacioFunc()){
        cout<<"No Se Encuentra Archivo"<<endl;
        return false;
    }else{
        system("cls");
        encontrado=false;
        while(!leer.eof()){
            getline(leer,oldPlatillo->nombre,'#');
            getline(leer,oldPlatillo->descripcion,'#');
            getline(leer,oldPlatillo->precio,'#');
            getline(leer,oldPlatillo->id,';');
            if(leer.eof())
                break;
            if(!nombre.compare(oldPlatillo->nombre)){
                encontrado=true;
                return true;
            }
        }
        cout<<endl<<endl;
    }
}


estrPlatillo registrarFunc(){
    estrPlatillo newPlatillo;

    cout<<"Ingrese el nombre"<<endl;
    cin>>newPlatillo.nombre;
    cout<<"Ingrse la descripcion"<<endl;
    cin>>newPlatillo.descripcion;
    cout<<"Ingrese Precio"<<endl;
    cin>>newPlatillo.precio;

    return newPlatillo;
}

void imprimirPlatillo(estrPlatillo platillo){
    cout<<setw(20)<<platillo.nombre<<setw(20)<<platillo.descripcion<<setw(20)<<platillo.precio<<setw(29)<<platillo.id<<endl;
}

bool eliminarPlatillo(){
    estrPlatillo searchPlatillo;
    string nombre;

    ifstream leer("Platillos.txt");
    ofstream escribir("PlatillosNew.txt");

    cout<<"Ingrese El Nombre Ha Buscar"<<endl;
    cin>>nombre;

    if(vacioFunc()){
        cout<<"No Se Encuentra Archivo"<<endl;
        return false;
    }else{
        bool encontrado=false;
        while(!leer.eof()){
            getline(leer,searchPlatillo.nombre,'#');
            getline(leer,searchPlatillo.descripcion,'#');
            getline(leer,searchPlatillo.precio,'#');
            getline(leer,searchPlatillo.id,';');
            if(leer.eof())
                break;
            if(!nombre.compare(searchPlatillo.nombre))
                encontrado=true;
            else
                escribir <<searchPlatillo.nombre <<"#"<<searchPlatillo.descripcion<<"#"<<searchPlatillo.precio<<"#"<<searchPlatillo.id<<";";
        }
        if(encontrado){
            leer.close();
            remove("Platillos.txt");
            escribir.close();
            rename("PlatillosNew.txt","Platillos.txt");
        }
        return encontrado;
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
            <<menuBuscar<<"- Buscar"<<endl
            <<menuEliminar<<"- Eliminar"<<endl
            <<menuSalir<<"- Salir"<<endl;
            cin>>opc;
        switch (opc) {

            case menuVer:
            imprimirFunc();
            break;
            case menuBuscar:
                if(buscarFunc(&newPlatillo))
                    imprimirPlatillo(newPlatillo);
                break;
            case menuEliminar:
                if(eliminarPlatillo())
                    cout<<"Eliminado"<<endl;
                else
                    cout<<"No Se Encuentra"<<endl;
            break;
            case menuSalir:
            break;

            case menuPlatillo:

                escribirFunc(registrarFunc());
                break;

        }
    }while (opc != menuSalir);

}
