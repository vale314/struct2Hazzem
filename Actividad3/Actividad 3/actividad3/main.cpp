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
    menuVerBorrados,
    menuBuscar,
    menuEliminar,
    menuModificar,
    menuEliminarLogica,
    menuActivarLogica,
    menuSalir
};

struct estrPlatillo{
    string nombre;
    string descripcion;
    string precio;
    string id;
    string bandera;
};


struct estrPlatilloChar{

    char *nombreBits=new char;
    char *nombrePlatillo=new char;

    char *descripcionBits=new char;
    char *descripcionPlatillo=new char;

    char *precioPlatillo=new char;

    char *idPlatillo=new char;

    char *banderaPlatillo=new char;
};

bool vacioFunc(){
    ifstream leer("Platillos.txt");
    if(!leer.good())
        return true;
    else
        return false;

}


int appendDigit(int base, int append) {
   std::string sBase = std::to_string(base);
   std::string sAppend = std::to_string(append);
   std::string result = sBase + sAppend;
   return std::stoi(result);

}

int change(char* nombreBits){
    int number;

    number=appendDigit(nombreBits[0]-'0',nombreBits[1]-'0');
    number=appendDigit(number,nombreBits[2]-'0');
    number=appendDigit(number,nombreBits[3]-'0');
    return number;
}



int numerosId(){
    ifstream leer("Platillos.txt");
    estrPlatillo oldPlatillo;



    char *nombreBits=new char;
    char *nombrePersona=new char;

    char *descripcionBits=new char;
    char *descripcionPersona=new char;

    char *precioPersona=new char;

    char *idPersona=new char;

    char *banderaPersona=new char;

    if(!leer.good())
        throw invalid_argument("Error No Encontrado");
    else
        while(!leer.eof()){

            leer.read((char*)nombreBits,sizeof (size_t));
            leer.read((char*)nombrePersona,change(nombreBits));

            leer.read((char*)descripcionBits,sizeof(size_t));
            leer.read((char*)descripcionPersona,change(descripcionBits));

            leer.read((char*)precioPersona,sizeof (size_t));
            leer.read((char*)idPersona,sizeof (size_t));
            leer.read((char*)banderaPersona,sizeof (size_t));

            if(leer.eof())
                break;

        }

        leer.close();
        return change(idPersona);
}

int cantidadDigitos(int num){
    int cantidad=0;

      while (num > 0) {
        num = num / 10;
        cantidad++ ;
      }

      return cantidad;
}

string agregarCeros(int num){
    int cantidad=cantidadDigitos(num);
    char c1='0';
    string newNumber=to_string(num);

    while(cantidad!=4){
        if(cantidad==4)
            break;
        newNumber=c1+newNumber;
        cantidad++;
    }
//    static char returnChar=*newNumber.c_str();
    return (newNumber);
}

void escribirFunc(estrPlatillo newPlatillo,ofstream &escribir,ifstream &leer){
    size_t a = strlen(newPlatillo.nombre.c_str());
    size_t b = strlen(newPlatillo.descripcion.c_str());
    size_t c = strlen(newPlatillo.precio.c_str());

    if(vacioFunc()|| leer.peek()==EOF){
        escribir.seekp(0,ios::end);

        escribir.write(agregarCeros(a).c_str(),sizeof (size_t));
        escribir.write((char*)newPlatillo.nombre.c_str(),a);

        escribir.write(agregarCeros(b).c_str(),sizeof (size_t));
        escribir.write((char*)newPlatillo.descripcion.c_str(),b);
        //precio
        escribir.write(agregarCeros(stoi(newPlatillo.precio)).c_str(),sizeof (size_t));
        //id
        escribir.write(agregarCeros(0).c_str(),sizeof(size_t));
        //bandera
        escribir.write(agregarCeros(1).c_str(),sizeof (size_t));
    }else{
        escribir.seekp(0,ios::end);

        escribir.write(agregarCeros(a).c_str(),sizeof (size_t));
        escribir.write((char*)newPlatillo.nombre.c_str(),a);

        escribir.write(agregarCeros(b).c_str(),sizeof (size_t));
        escribir.write((char*)newPlatillo.descripcion.c_str(),b);
        //precio
        escribir.write(agregarCeros(stoi(newPlatillo.precio)).c_str(),sizeof (size_t));
        //id
        escribir.write(agregarCeros(numerosId()+1).c_str(),sizeof(size_t));
        //bandera
        escribir.write(agregarCeros(1).c_str(),sizeof (size_t));

    }
}

string borrarBasura(char* nombre,int tam){
    int i=0;
    char c1='0';
    string newNumber="";

    while(i!=tam){
        newNumber=newNumber+nombre[i];
        i++;
    }
//    static char returnChar=*newNumber.c_str();
    return (newNumber);
}

void imprimirFunc(ifstream &leer,bool activos){
    estrPlatilloChar oldPlatillo;

    bool vacio;
//    cout<<"EOF: "<<leer.eof()<<endl;
//    system("pause");
    vacio=true;
    if(vacioFunc()){
        cout<<"No Se Encuentra Archivo"<<endl;
        return;
    }else{
        system("cls");
            cout<<setw(20)<<"NOMBRE"<<setw(20)<<"DESCRIPCION"<<setw(20)<<"PRECIO"<<setw(29)<<"ID"<<endl<<endl<<endl;

            while(!leer.eof()){
                leer.read(oldPlatillo.nombreBits,sizeof (size_t));
                leer.read(oldPlatillo.nombrePlatillo,change(oldPlatillo.nombreBits));

                leer.read(oldPlatillo.descripcionBits,sizeof(size_t));
                leer.read(oldPlatillo.descripcionPlatillo,change(oldPlatillo.descripcionBits));

                leer.read(oldPlatillo.precioPlatillo,sizeof (size_t));
                leer.read(oldPlatillo.idPlatillo,sizeof (size_t));
                leer.read(oldPlatillo.banderaPlatillo,sizeof (size_t));
                if(leer.eof())
                    break;
                if((change(oldPlatillo.banderaPlatillo)&& activos)||(!change(oldPlatillo.banderaPlatillo)&&!activos)){
                    cout<<setw(20)<<borrarBasura(oldPlatillo.nombrePlatillo,change(oldPlatillo.nombreBits))
                        <<setw(20)<<borrarBasura(oldPlatillo.descripcionPlatillo,change(oldPlatillo.descripcionBits))
                        <<setw(20)<<change(oldPlatillo.precioPlatillo)
                        <<setw(29)<<change(oldPlatillo.idPlatillo)<<endl;
                    vacio=false;
                }
            }


            if(vacio)
                cout<<"No Se Encuentarn Platillos"<<endl;


    }


    oldPlatillo.nombreBits=nullptr;
    oldPlatillo.nombrePlatillo=nullptr;
    oldPlatillo.descripcionBits=nullptr;
    oldPlatillo.descripcionPlatillo=nullptr;
    oldPlatillo.precioPlatillo=nullptr;
    oldPlatillo.idPlatillo=nullptr;
    oldPlatillo.banderaPlatillo=nullptr;

    delete &oldPlatillo.nombreBits;
    delete &oldPlatillo.nombrePlatillo;
    delete &oldPlatillo.descripcionBits;
    delete &oldPlatillo.descripcionPlatillo;
    delete &oldPlatillo.precioPlatillo;
    delete &oldPlatillo.idPlatillo;
    delete &oldPlatillo.banderaPlatillo;
    leer.close();

}

bool buscarFunc(estrPlatilloChar *searchPlatillo,ifstream &leer){
    int id;
    bool encontrado;

    leer.seekg(ios::beg);

    cout<<"Ingrese El Id Ha Buscar"<<endl;
    cin>>id;
    if(vacioFunc()){
        cout<<"No Se Encuentra Archivo"<<endl;
        return false;
    }else{
        encontrado=false;
        while(!leer.eof()){
                leer.read((char*)searchPlatillo->nombreBits,sizeof (size_t));
                leer.read((char*)searchPlatillo->nombrePlatillo,change(searchPlatillo->nombreBits));

                leer.read((char*)searchPlatillo->descripcionBits,sizeof(size_t));
                leer.read((char*)searchPlatillo->descripcionPlatillo,change(searchPlatillo->descripcionBits));

                leer.read((char*)searchPlatillo->precioPlatillo,sizeof (size_t));
                leer.read((char*)searchPlatillo->idPlatillo,sizeof (size_t));
                leer.read((char*)searchPlatillo->banderaPlatillo,sizeof (size_t));
            if(leer.eof())
                break;
            if(id==change(searchPlatillo->idPlatillo) && change(searchPlatillo->banderaPlatillo)){
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

void imprimirPlatillo(estrPlatilloChar platillo){

    cout<<setw(20)<<borrarBasura(platillo.nombrePlatillo,change(platillo.nombreBits))
        <<setw(20)<<borrarBasura(platillo.descripcionPlatillo,change(platillo.descripcionBits))
        <<setw(20)<<change(platillo.precioPlatillo)
        <<setw(29)<<change(platillo.idPlatillo)<<endl;
}

bool eliminarPlatillo(ifstream &leer,ofstream &escribir){
    int id;
    leer.seekg(ios::beg);
    escribir.seekp(ios::beg);
    estrPlatilloChar searchPlatillo;


    ofstream escribirAux("PlatillosNew.txt",ios::app);

    cout<<"Ingrese El Id Ha Buscar"<<endl;
    cin.ignore();
    cin>>id;

    if(vacioFunc()){
        cout<<"No Se Encuentra Archivo"<<endl;
        return false;
    }else{
        bool encontrado=false;
        escribirAux.flush();
        while(!leer.eof()){

            leer.read((char*)searchPlatillo.nombreBits,sizeof (size_t));
            leer.read((char*)searchPlatillo.nombrePlatillo,change(searchPlatillo.nombreBits));

            leer.read((char*)searchPlatillo.descripcionBits,sizeof(size_t));
            leer.read((char*)searchPlatillo.descripcionPlatillo,change(searchPlatillo.descripcionBits));

            leer.read((char*)searchPlatillo.precioPlatillo,sizeof (size_t));
            leer.read((char*)searchPlatillo.idPlatillo,sizeof (size_t));
            leer.read((char*)searchPlatillo.banderaPlatillo,sizeof (size_t));

            if(leer.eof())
                break;
            if(id==change(searchPlatillo.idPlatillo) && change(searchPlatillo.banderaPlatillo)){
                encontrado=true;

            }else{
               escribirAux.clear();
               escribirAux.clear();
               escribirAux.write(searchPlatillo.nombreBits,sizeof (size_t));
               escribirAux.write(borrarBasura(searchPlatillo.nombrePlatillo,change(searchPlatillo.nombreBits)).c_str(),change(searchPlatillo.nombreBits));

               escribirAux.write(searchPlatillo.descripcionBits,sizeof (size_t));
               escribirAux.write(borrarBasura(searchPlatillo.descripcionPlatillo,change(searchPlatillo.descripcionBits)).c_str(),change(searchPlatillo.descripcionBits));
               //precio
               escribirAux.write(searchPlatillo.precioPlatillo,sizeof (size_t));
               //id
               escribirAux.write(searchPlatillo.idPlatillo,sizeof(size_t));
               //bandera
               escribirAux.write(searchPlatillo.banderaPlatillo,sizeof (size_t));
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
        estrPlatilloChar searchPlatillo;

        leer.seekg(ios::beg);
        escribir.seekp(ios::beg);
        cout<<"Here"<<endl;

        int id;

        cout<<"Ingrese El id Ha Buscar"<<endl;
        cin.ignore();
        cin>>id;

        if(vacioFunc()){
            cout<<"No Se Encuentra Archivo"<<endl;
            return;
        }else{
            system("cls");
            while(!leer.eof()){
                leer.read(searchPlatillo.nombreBits,sizeof (size_t));
                leer.read(searchPlatillo.nombrePlatillo,change(searchPlatillo.nombreBits));

                leer.read(searchPlatillo.descripcionBits,sizeof(size_t));
                leer.read(searchPlatillo.descripcionPlatillo,change(searchPlatillo.descripcionBits));

                leer.read(searchPlatillo.precioPlatillo,sizeof (size_t));
                leer.read(searchPlatillo.idPlatillo,sizeof (size_t));
                leer.read(searchPlatillo.banderaPlatillo,sizeof (size_t));
                if(leer.eof())
                    break;
                if(id==change(searchPlatillo.idPlatillo)){
                    if((change(searchPlatillo.banderaPlatillo)&&borrar) || (!change(searchPlatillo.banderaPlatillo)&&!borrar)){
                        long long pos=leer.tellg();
                        pos=pos-4;
                        //escribir.clear();
                        escribir.seekp(pos,ios::cur);
                        if(!change(searchPlatillo.banderaPlatillo)){
                            escribir.write("0001",4);
                            system("cls");
                            cout<<"Archivo Activado"<<endl<<endl;
                        }else{
                            escribir.write("0000",4);
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
    estrPlatilloChar searchPlatillo;
    int id;

    ofstream escribirAux("PlatillosNew.txt",ios::app);

    cout<<"Ingrese El id Ha Buscar"<<endl;
    cin>>id;

    if(vacioFunc()){
        cout<<"No Se Encuentra Archivo"<<endl;
        return false;
    }else{
        bool encontrado=false;
        while(!leer.eof()){
            leer.read(searchPlatillo.nombreBits,sizeof (size_t));
            leer.read(searchPlatillo.nombrePlatillo,change(searchPlatillo.nombreBits));

            leer.read(searchPlatillo.descripcionBits,sizeof(size_t));
            leer.read(searchPlatillo.descripcionPlatillo,change(searchPlatillo.descripcionBits));

            leer.read(searchPlatillo.precioPlatillo,sizeof (size_t));
            leer.read(searchPlatillo.idPlatillo,sizeof (size_t));
            leer.read(searchPlatillo.banderaPlatillo,sizeof (size_t));
            if(leer.eof())
                break;
            if(id==change(searchPlatillo.idPlatillo) && change(searchPlatillo.banderaPlatillo)){
                cin.ignore();
                estrPlatillo newPlatillo=cambiarFunc(searchPlatillo.idPlatillo);

                size_t a = strlen(newPlatillo.nombre.c_str());
                size_t b = strlen(newPlatillo.descripcion.c_str());
                size_t c = strlen(newPlatillo.precio.c_str());

                //**************Aqui Nos Quedamos recorrer el seekp para sobre escribir el archivo*****************///////////////////

                    escribirAux.write(agregarCeros(a).c_str(),sizeof (size_t));
                    escribirAux.write((char*)newPlatillo.nombre.c_str(),a);

                    escribirAux.write(agregarCeros(b).c_str(),sizeof (size_t));
                    escribirAux.write((char*)newPlatillo.descripcion.c_str(),b);
                    //precio
                    escribirAux.write(agregarCeros(stoi(newPlatillo.precio)).c_str(),sizeof (size_t));
                    //id
                    escribirAux.write(agregarCeros(change(searchPlatillo.idPlatillo)).c_str(),sizeof(size_t));
                    //bandera
                    escribirAux.write(agregarCeros(1).c_str(),sizeof (size_t));

                encontrado=true;

            }else{

                escribirAux.clear();
                escribirAux.write(searchPlatillo.nombreBits,sizeof (size_t));
                escribirAux.write(borrarBasura(searchPlatillo.nombrePlatillo,change(searchPlatillo.nombreBits)).c_str(),change(searchPlatillo.nombreBits));

                escribirAux.write(searchPlatillo.descripcionBits,sizeof (size_t));
                escribirAux.write(borrarBasura(searchPlatillo.descripcionPlatillo,change(searchPlatillo.descripcionBits)).c_str(),change(searchPlatillo.descripcionBits));
                //precio
                escribirAux.write(searchPlatillo.precioPlatillo,sizeof (size_t));
                //id
                escribirAux.write(searchPlatillo.idPlatillo,sizeof(size_t));
                //bandera
                escribirAux.write(searchPlatillo.banderaPlatillo,sizeof (size_t));

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


int main()
{
    size_t opc;
    opc=0;
    estrPlatilloChar searchPlatillo;

    cout <<"Restaurante"<<endl;
    do{
        ofstream escribir1("Platillos.txt",ios::app);
        ifstream leer;leer.open("Platillos.txt");
        ofstream escribir;escribir.open("Platillos.txt",ios::in| ios::out);
        //app no permite mover el puntero con seekp pero los otros modos de apertura dañan el archivo
        //posible solucion crear un metodo que cargue los archivos guardados con app a archivos
        //out e in

        cout<<menuPlatillo<<"- Crear Platillo"<<endl
            <<menuVer<<"- Ver Todos Los Platillos"<<endl
            <<menuVerBorrados<<"- Ver Todos Los Borrados"<<endl
            <<menuBuscar<<"- Buscar"<<endl
            <<menuEliminar<<"- Eliminar Fisicamente"<<endl
            <<menuModificar<<"- Modificar"<<endl
            <<menuEliminarLogica<<"- Eliminar Logicamente"<<endl
            <<menuActivarLogica<<"- Activar Logica"<<endl
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
                if(buscarFunc(&searchPlatillo,leer))
                    imprimirPlatillo(searchPlatillo);
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
            case menuSalir:
            break;

        }
        escribir.close();
        escribir1.close();
        leer.close();
    }while (opc != menuSalir);

}
