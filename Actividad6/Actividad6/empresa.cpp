#include "empresa.h"

Empresa::Empresa()
{
    cargarVector();

}

Empresa::~Empresa()
{
    guardarVector();
}

void Empresa::menu()
{
    int opc;
    do{
        system("cls");
        cout<<menuAgregar<<".- Agregar"<<endl
            <<menuConsultar<<".- Consultar"<<endl
            <<menuImprimir<<".- Imprimir"<<endl
            <<menuSalir<<".- Salir"<<endl;
        cin>>opc;
        switch (opc) {
            case menuAgregar:
                pedirDatos();
            break;
            case menuConsultar:
                consultar();
            break;
            case menuImprimir:
            break;
            case menuSalir:
            break;

        }
    }while(opc!=menuSalir);
}

void Empresa::pedirDatos()
{
    cin.ignore();
    cout<<"Ingrese El Nombre"<<endl;
    getline(cin,aspiranteStruct.nombre);
    cout<<"Ingrese El Curp"<<endl;
    getline(cin,aspiranteStruct.curp);
    cout<<"Ingrese La Edad"<<endl;
    getline(cin,aspiranteStruct.edad);
    cout<<"Ingrese El Puesto"<<endl;
    getline(cin,aspiranteStruct.puesto);
    llenarDatos();
}

void Empresa::llenarDatos()
{
    aspirante.setNombre(aspiranteStruct.nombre);
    aspirante.setCurp(aspiranteStruct.curp);
    aspirante.setEdad(aspiranteStruct.edad);
    aspirante.setPuesto(aspiranteStruct.puesto);
    aspirante.setBandera(1);
    escribirDatos();
}


void Empresa::escribirDatos()
{
    Indice indice;
    fstream escrAspirante("aspirantes.txt",ios::out|ios::app);
    escrAspirante<<aspirante.getNombre()<<"#"<<aspirante.getCurp()<<"#"<<aspirante.getEdad()<<"#"<<aspirante.getPuesto()<<"#"<<aspirante.getBandera()<<";";

    if(indicesVector.empty()){
        indice.setId(aspirante.getCurp());
        indice.setPos(0);
        indicesVector.push_back(indice);
        indice.setId("-1");

        indice.setPos(escrAspirante.tellp());
        indicesVector.push_back(indice);
    }else{
        indice.setId(aspirante.getCurp());
        indice.setPos(indicesVector.back().getPos());
        indicesVector.pop_back();
        indicesVector.push_back(indice);

        indice.setId("-1");
        indice.setPos(indicesVector.back().getPos()+escrAspirante.tellp());
        indicesVector.push_back(indice);
    }

    escrAspirante.close();
}



void Empresa::cargarVector()
{
    Indice indiceAux;
    leerIndice.open("indices.txt",ios::binary|ios::in|ios::app);
    if(!leerIndice.good()){
        cerr<<"Error Al leer"<<endl;
        exit(1);
    }
    while(!leerIndice.eof()){
        leerIndice.read(reinterpret_cast<char*>(&indiceAux),sizeof(indiceAux));
        if(leerIndice.eof())
            break;
        cout<<indiceAux.getPos()<<endl;
//        indicesVector.push_back(indiceAux);
    }
   leerIndice.close();
   getch();
}

void Empresa::guardarVector()
{
    escrIndice.open("indices.txt",ios::binary|ios::out|ios::app);
    for(size_t i=0;i<indicesVector.size();i++){
        escrIndice.write(reinterpret_cast<const char*>(&indicesVector[i]), sizeof (indicesVector[i]));
        cout<<indicesVector[i].getId()<<endl<<indicesVector[i].getPos()<<endl;
    }
    escrIndice.close();
    getch();
}



//void Empresa::cargarVector()
//{
//    leer.open("aspirantes.txt",ios::in|ios::app);
//    if(!leer.good())
//        return;
//    while(!leer.eof()){
//        getline(leer,aspiranteStruct.nombre,'#');
//        getline(leer,aspiranteStruct.curp,'#');
//        getline(leer,aspiranteStruct.edad,'#');
//        getline(leer,aspiranteStruct.puesto,'#');
//        getline(leer,aspiranteStruct.bandera,';');
//        if(leer.eof())
//            break;
//        }
//    leer.close();
//}

void Empresa::consultar()
{

}

