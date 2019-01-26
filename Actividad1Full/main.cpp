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
    menuEliminarLogica,
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
            getline(leer,oldPlatillo.bandera,'#');
            if(leer.eof())
                break;

        }
        cout<<oldPlatillo.bandera<<endl;
        system("pause");
        return stoi(oldPlatillo.id);
}

void escribirFunc(estrPlatillo newPlatillo,ofstream &escribir,ifstream &leer){
    if(vacioFunc()|| leer.peek()==EOF){
        escribir.seekp(ios::beg);
        escribir <<newPlatillo.nombre <<"#"<<newPlatillo.descripcion<<"#"<<newPlatillo.precio<<"#"<<"0"<<"#"<<newPlatillo.bandera<<";";
    }else{
        escribir.seekp(ios::beg);
        escribir <<newPlatillo.nombre <<"#"<<newPlatillo.descripcion<<"#"<<newPlatillo.precio<<"#"<<numerosId()+1<<"#"<<newPlatillo.bandera<<";";
    }
}

void imprimirFunc(ifstream &leer){
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
                if(stoi(oldPlatillo.bandera)){
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
        system("cls");
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
                encontrado=true;
                return true;
            }
        }
        cout<<endl<<endl;
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
    cout<<newPlatillo.descripcion<<endl;

    cout<<"Ingrese Precio"<<endl;
    getline(cin,newPlatillo.precio);
    cout<<newPlatillo.precio<<endl;

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

    ofstream escribirAux("PlatillosNew.txt",ios::out);

    cout<<"Ingrese El Nombre Ha Buscar"<<endl;
    cin.ignore();
    getline(cin,nombre);

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
                escribirAux <<searchPlatillo.nombre <<"#"<<searchPlatillo.descripcion<<"#"<<searchPlatillo.precio<<"#"<<searchPlatillo.id<<";";
        }
        if(encontrado){
            leer.close();
            escribir.close();
            remove("Platillos.txt");
            escribirAux.close();
            rename("PlatillosNew.txt","Platillos.txt");
            remove("PlatillosnNew.txt");
        }
        return encontrado;
    }

}

void elimniarLogicamente(ifstream &leer,ofstream &escribir) {
    estrPlatillo platillo;

    leer.seekg(ios::beg);
    escribir.seekp(ios::beg);

    string nombre;
    bool encontrado;

    cout<<"Ingrese El Nombre Ha Buscar"<<endl;
    cin.ignore();
    getline(cin,nombre);

    if(vacioFunc()){
        cout<<"No Se Encuentra Archivo"<<endl;
        return;
    }else{
        system("cls");
        encontrado=false;
        while(!leer.eof()){
            getline(leer,platillo.nombre,'#');
            getline(leer,platillo.descripcion,'#');
            getline(leer,platillo.precio,'#');
            getline(leer,platillo.id,'#');
            getline(leer,platillo.bandera,';');
            if(leer.eof())
                break;
            if(!nombre.compare(platillo.nombre) && stoi(platillo.bandera)){
                encontrado=true;
                long long pos=leer.tellg();
                pos=pos-2;
                cout<<pos<<endl;
                escribir.clear();
                escribir.seekp(pos,ios::beg);
                escribir<<"0";
                return;
            }
        }
        cout<<endl<<endl;
    }
    return;
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
        ofstream escribir("Platillos.txt",ios::app);
        ifstream leer("Platillos.txt",ios::app);

        cout<<menuPlatillo<<"- Crear Platillo"<<endl
            <<menuVer<<"- Ver Todos Los Platillos"<<endl
            <<menuBuscar<<"- Buscar"<<endl
            <<menuEliminar<<"- Eliminar Fisicamente"<<endl
            <<menuEliminarLogica<<"- Eliminar Logicamente"<<endl
            <<menuSalir<<"- Salir"<<endl;
            cin>>opc;
        switch (opc) {

            case menuPlatillo:
                escribirFunc(registrarFunc(),escribir,leer);
            break;
            case menuVer:
                imprimirFunc(leer);
            break;
            case menuBuscar:
                if(buscarFunc(&newPlatillo,leer))
                    imprimirPlatillo(newPlatillo);
                else
                    cout<<"El Platillo No Se Encontro"<<endl<<endl;
                break;
            case menuEliminar:
                if(eliminarPlatillo(leer,escribir))
                    cout<<"Eliminado"<<endl;
                else
                    cout<<"No Se Encuentra"<<endl;
            break;
            case menuEliminarLogica:
                elimniarLogicamente(leer,escribir);
            break;
            case menuSalir:
            break;

        }
    }while (opc != menuSalir);

}
