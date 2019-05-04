#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdexcept>
#include <iomanip>
#include <string.h>
#include "hofmann.h"

using namespace std;

enum{
    menuPlatillo=1,
    menuVer,
    menuVerBorrados,
    menuBuscar,
    menuEliminar,
    menuModificar,
    menuEliminarLogica,
    menuActivarLogica,
    menuEncriptacion,
    menuSalir
};

struct estrPlatillo{
    string nombre;
    string descripcion;
    string precio;
    string id;
    string bandera;
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
            getline(leer,oldPlatillo.id,'#');
            getline(leer,oldPlatillo.bandera,';');
            if(leer.eof())
                break;
        }

        return stoi(oldPlatillo.id);
}

void escribirFunc(estrPlatillo newPlatillo,ofstream &escribir,ifstream &leer){
    if(vacioFunc()|| leer.peek()==EOF){
        escribir.seekp(0,ios::end);
        escribir <<newPlatillo.nombre <<"#"<<newPlatillo.descripcion<<"#"<<newPlatillo.precio<<"#"<<"0"<<"#"<<newPlatillo.bandera<<";";
    }else{
        escribir.seekp(0,ios::end);
        escribir <<newPlatillo.nombre <<"#"<<newPlatillo.descripcion<<"#"<<newPlatillo.precio<<"#"<<numerosId()+1<<"#"<<newPlatillo.bandera<<";";
    }
}

void imprimirFunc(ifstream &leer,bool activos){
    estrPlatillo oldPlatillo;
    bool vacio;
    leer.seekg(ios::beg);
    vacio=true;
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
                getline(leer,oldPlatillo.id,'#');
                getline(leer,oldPlatillo.bandera,';');
                if(leer.eof())
                    break;
                if((stoi(oldPlatillo.bandera)&& activos)||(!stoi(oldPlatillo.bandera)&&!activos)){
                    cout<<setw(20)<<oldPlatillo.nombre<<setw(20)<<oldPlatillo.descripcion<<setw(20)<<oldPlatillo.precio<<setw(29)<<oldPlatillo.id<<endl;
                    vacio=false;
                }
            }
            if(vacio)
                cout<<"No Se Encuentarn Platillos"<<endl;

        cout<<endl<<endl;
    }
}

bool buscarFunc(estrPlatillo *oldPlatillo,ifstream &leer){
    string nombre;
    bool encontrado;

    leer.seekg(ios::beg);

    cout<<"Ingrese El Nombre Ha Buscar"<<endl;
    cin.ignore();
    getline(cin,nombre);
    if(vacioFunc()){
        cout<<"No Se Encuentra Archivo"<<endl;
        return false;
    }else{
        encontrado=false;
        while(!leer.eof()){
            getline(leer,oldPlatillo->nombre,'#');
            getline(leer,oldPlatillo->descripcion,'#');
            getline(leer,oldPlatillo->precio,'#');
            getline(leer,oldPlatillo->id,'#');
            getline(leer,oldPlatillo->bandera,';');
            if(leer.eof())
                break;
            if(!nombre.compare(oldPlatillo->nombre) && stoi(oldPlatillo->bandera)){
                system("cls");
                cout<<setw(20)<<"NOMBRE"<<setw(20)<<"DESCRIPCION"<<setw(20)<<"PRECIO"<<setw(29)<<"ID"<<endl<<endl<<endl;
                encontrado=true;
                return true;
            }
        }
        system("cls");
    }
    return false;
}


estrPlatillo registrarFunc(){
    estrPlatillo newPlatillo;

    cout<<"Ingrese el nombre"<<endl;
    cin.ignore();
    getline(cin,newPlatillo.nombre);
    cout<<"Ingrse la descripcion"<<endl;
    getline(cin,newPlatillo.descripcion);
    cout<<"Ingrese Precio"<<endl;
    getline(cin,newPlatillo.precio);
    newPlatillo.bandera="1";

    return newPlatillo;
}

void imprimirPlatillo(estrPlatillo platillo){

    cout<<setw(20)<<platillo.nombre<<setw(20)<<platillo.descripcion<<setw(20)<<platillo.precio<<setw(29)<<platillo.id<<endl<<endl;
}

bool eliminarPlatillo(ifstream &leer,ofstream &escribir){
    estrPlatillo searchPlatillo;
    string nombre;
    leer.seekg(ios::beg);
    escribir.seekp(ios::beg);

    ofstream escribirAux("PlatillosNew.txt",ios::app);

    cout<<"Ingrese El Nombre Ha Buscar"<<endl;
    cin.ignore();
    getline(cin,nombre);

    if(vacioFunc()){
        cout<<"No Se Encuentra Archivo"<<endl;
        return false;
    }else{
        bool encontrado=false;
        escribirAux.flush();
        while(!leer.eof()){
            getline(leer,searchPlatillo.nombre,'#');
            getline(leer,searchPlatillo.descripcion,'#');
            getline(leer,searchPlatillo.precio,'#');
            getline(leer,searchPlatillo.id,'#');
            getline(leer,searchPlatillo.bandera,';');
            if(leer.eof())
                break;
            if(!nombre.compare(searchPlatillo.nombre) && stoi(searchPlatillo.bandera)){
                encontrado=true;

            }else{
               escribirAux.clear();
                escribirAux <<searchPlatillo.nombre <<"#"<<searchPlatillo.descripcion<<"#"<<searchPlatillo.precio<<"#"<<searchPlatillo.id<<"#"<<searchPlatillo.bandera<<";";
            }

        }
        if(encontrado){
            leer.close();
            escribir.close();
            escribirAux.close();
            remove("Platillos.txt");
            system("pause");
            rename("PlatillosNew.txt","Platillos.txt");
            remove("PlatillosNew.txt");
        }else{
            escribirAux.close();
            remove("PlatillosNew.txt");
        }

        system("cls");
        return encontrado;
    }

}

void cambiarLogicamente(ifstream &leer, ofstream &escribir,bool borrar){
        estrPlatillo platillo;

        leer.seekg(ios::beg);
        escribir.seekp(ios::beg);

        string nombre;

        cout<<"Ingrese El Nombre Ha Buscar"<<endl;
        cin.ignore();
        getline(cin,nombre);

        if(vacioFunc()){
            cout<<"No Se Encuentra Archivo"<<endl;
            return;
        }else{
            system("cls");
            while(!leer.eof()){
                getline(leer,platillo.nombre,'#');
                getline(leer,platillo.descripcion,'#');
                getline(leer,platillo.precio,'#');
                getline(leer,platillo.id,'#');
                getline(leer,platillo.bandera,';');
                if(leer.eof())
                    break;
                if(!nombre.compare(platillo.nombre)){
                    if((stoi(platillo.bandera)&&borrar) || (!stoi(platillo.bandera)&&!borrar)){
                        long long pos=leer.tellg();
                        pos=pos-2;
                        //escribir.clear();
                        escribir.seekp(pos,ios::cur);
                        if(!platillo.bandera.compare("0")){
                            escribir<<"1";
                            system("cls");
                            cout<<"Archivo Activado"<<endl<<endl;
                        }else{
                            escribir<<"0";
                            system("cls");
                            cout<<"Archivo Borrado"<<endl<<endl;
                        }
                        return;
                    }else
                        system("cls");
                        cout<<"No Se Encuentra"<<endl<<endl;
                        return;
                }
            }
            system("cls");
            cout<<"No Se Encuentra"<<endl<<endl;
        }
        return;
}

estrPlatillo cambiarFunc(string id){
    estrPlatillo newPlatillo;

    cout<<"Ingrese el nombre"<<endl;
    getline(cin,newPlatillo.nombre);
    cout<<"Ingrse la descripcion"<<endl;
    getline(cin,newPlatillo.descripcion);
    cout<<"Ingrese Precio"<<endl;
    getline(cin,newPlatillo.precio);
    newPlatillo.bandera="1";
    newPlatillo.id=id;

    return newPlatillo;
}

int modificar(ifstream &leer,ofstream &escribir){
    estrPlatillo searchPlatillo;
    string nombre;

    ofstream escribirAux("PlatillosNew.txt",ios::app);

    cout<<"Ingrese El Nombre Ha Buscar"<<endl;
    cin.ignore();
    getline(cin,nombre);

    if(vacioFunc()){
        cout<<"No Se Encuentra Archivo"<<endl;
        return false;
    }else{
        bool encontrado=false;
        escribirAux.flush();
        while(!leer.eof()){
            getline(leer,searchPlatillo.nombre,'#');
            getline(leer,searchPlatillo.descripcion,'#');
            getline(leer,searchPlatillo.precio,'#');
            getline(leer,searchPlatillo.id,'#');
            getline(leer,searchPlatillo.bandera,';');
            if(leer.eof())
                break;
            if(!nombre.compare(searchPlatillo.nombre) && stoi(searchPlatillo.bandera)){
                estrPlatillo newPlatillo=cambiarFunc(searchPlatillo.id);
                escribirAux <<newPlatillo.nombre <<"#"<<newPlatillo.descripcion<<"#"<<newPlatillo.precio<<"#"<<newPlatillo.id<<"#"<<newPlatillo.bandera<<";";
                encontrado=true;

            }else{
               escribirAux.clear();
                escribirAux <<searchPlatillo.nombre <<"#"<<searchPlatillo.descripcion<<"#"<<searchPlatillo.precio<<"#"<<searchPlatillo.id<<"#"<<searchPlatillo.bandera<<";";
            }

        }
        if(encontrado){
            leer.close();
            escribir.close();
            escribirAux.close();
            remove("Platillos.txt");
            system("pause");
            rename("PlatillosNew.txt","Platillos.txt");
            remove("PlatillosNew.txt");
        }else{
            escribirAux.close();
            remove("PlatillosNew.txt");
        }

        system("cls");
        return encontrado;
    }
}


void encriptar(){
    HFF<char> hff;

    string aux;
    ifstream entrada("Platillos.txt",ios::in);
    while(getline(entrada,aux)) {
        if(entrada.eof())
            break;
        aux += aux;
    }
    entrada.close();

    hff.add(aux);

    cout<<"Size: "<<hff.size()<<endl;

    for(size_t i=0;i<hff.size();i++){
        cout<<hff[i]<<endl;
    }

    cout<<endl<<endl<<endl;

    hff.createTree();

    cout<<"Size: "<<hff.size()<<endl;


    hff.showTree();

    system("pause");
}

int main()
{
    size_t opc;
    opc=0;
    estrPlatillo newPlatillo;

    cout <<"Restaurante"<<endl;
    do{
        //app no permite mover el puntero con seekp pero los otros modos de apertura dañan el archivo
        //posible solucion crear un metodo que cargue los archivos guardados con app a archivos
        //out e in
        ofstream escribir1("Platillos.txt",ios::app);
        ifstream leer;leer.open("Platillos.txt",ios::app);
        ofstream escribir;escribir.open("Platillos.txt",ios::in| ios::out);

        cout<<menuPlatillo<<"- Crear Platillo"<<endl
            <<menuVer<<"- Ver Todos Los Platillos"<<endl
            <<menuVerBorrados<<"- Ver Todos Los Borrados"<<endl
            <<menuBuscar<<"- Buscar"<<endl
            <<menuEliminar<<"- Eliminar Fisicamente"<<endl
            <<menuModificar<<"- Modificar"<<endl
            <<menuEliminarLogica<<"- Eliminar Logicamente"<<endl
            <<menuActivarLogica<<"- Activar Logica"<<endl
            <<menuEncriptacion<<"- Encriptar"<<endl
            <<menuSalir<<"- Salir"<<endl;
            cin>>opc;
        switch (opc) {

            case menuPlatillo:
                escribirFunc(registrarFunc(),escribir1,leer);
            break;
            case menuVer:
                imprimirFunc(leer,true);
            break;
            case menuVerBorrados:
                imprimirFunc(leer,false);
            break;
            case menuBuscar:
                if(buscarFunc(&newPlatillo,leer))
                    imprimirPlatillo(newPlatillo);
                else
                    cout<<"El Platillo No Se Encontro"<<endl<<endl;
                break;
            case menuEliminar:
                escribir1.close();
                if(eliminarPlatillo(leer,escribir))
                    cout<<"Eliminado"<<endl<<endl;
                else
                    cout<<"No Se Encuentra"<<endl<<endl;
            break;
            case menuModificar:
                escribir1.close();
                if(modificar(leer,escribir))
                    cout<<"Modificado"<<endl<<endl;
                else
                    cout<<"No Se Encuentra"<<endl<<endl;

            break;
            case menuEliminarLogica:
                cambiarLogicamente(leer,escribir,true);
            break;
            case menuActivarLogica:
                cambiarLogicamente(leer,escribir,false);
            break;
            case menuEncriptacion:
                encriptar();
            break;
            case menuSalir:
            break;

        }
    }while (opc != menuSalir);

}
