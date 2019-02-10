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
                imprimirAll();
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
    cin.getline(aspiranteStruct.curp,4);
    if(validateCurp(aspiranteStruct.curp)){
        cout<<"Error Curp DUPLICADO"<<endl;
        getch();
        return;
    }
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
        indicesVector.push_back(indiceAux);
    }
   leerIndice.close();
}

void Empresa::guardarVector()
{
    remove("indices.txt");
    escrIndice.open("indices.txt",ios::binary|ios::out|ios::app);
    for(size_t i=0;i<indicesVector.size();i++){
        escrIndice.write(reinterpret_cast<const char*>(&indicesVector[i]), sizeof (indicesVector[i]));
        cout<<indicesVector[i].getId()<<endl<<indicesVector[i].getPos()<<endl;
    }
    escrIndice.close();
    getch();
}

void Empresa::consultar()
{
    if(indicesVector.empty()){
        cout<<"Se Encuentra Vacio"<<endl;
        getch();
        return;
    }

    char curp[4];
    size_t i;
    int encontrado=0;
    cout<<"Ingrese el id a buscar"<<endl;
    cin.ignore();
    cin.getline(curp,4);

    for(i=0;i<indicesVector.size()-1;i++){
        if(!strncmp(curp,indicesVector[i].getId(),4)){
            encontrado=1;
            break;
        }
    }

    Aspirantes aspirante;
    leerAspirante.open("aspirantes.txt",ios::binary);
    if(encontrado){
        long long pos= indicesVector[i].getPos();
        leerAspirante.clear();
        leerAspirante.seekg(pos);
        getline(leerAspirante,aspiranteStruct.nombre,'#');
        getline(leerAspirante,aspiranteStruct.curpS,'#');
        getline(leerAspirante,aspiranteStruct.edad,'#');
        getline(leerAspirante,aspiranteStruct.puesto,'#');
        getline(leerAspirante,aspiranteStruct.bandera,';');
        if(aspiranteStruct.bandera=="1")
            imprimirStruct();
        else
            cout<<"No Se Encuentra"<<endl;
    }else{
        cout<<"No Se Encuentra"<<endl;
    }
    leerAspirante.seekg(0);
    leerIndice.close();
    getch();
}

void Empresa::imprimirStruct()
{
    cout<<setw(15)<<aspiranteStruct.nombre
        <<setw(15)<<aspiranteStruct.curpS
        <<setw(15)<<aspiranteStruct.edad
        <<setw(15)<<aspiranteStruct.puesto
       <<setw(15)<<aspiranteStruct.bandera<<endl;
}

void Empresa::imprimir(size_t i)
{
    Aspirantes aspirante;
    leerAspirante.open("aspirantes.txt",ios::binary);

        long long pos= indicesVector[i].getPos();
        leerAspirante.clear();
        leerAspirante.seekg(pos);
        getline(leerAspirante,aspiranteStruct.nombre,'#');
        getline(leerAspirante,aspiranteStruct.curpS,'#');
        getline(leerAspirante,aspiranteStruct.edad,'#');
        getline(leerAspirante,aspiranteStruct.puesto,'#');
        getline(leerAspirante,aspiranteStruct.bandera,';');
        if(aspiranteStruct.bandera=="1")
            imprimirStruct();

    leerAspirante.seekg(0);
    leerIndice.close();
}

void Empresa::imprimirAll()
{
    if(indicesVector.empty()){
        cout<<"El Index Se Encuentra Solo"<<endl;
        getch();
        return;
    }
    for(size_t i=0;i<indicesVector.size()-1;i++)
        imprimir(i);
    getch();
}

int Empresa::validateCurp(const char curp[4])
{
    int encontrado=0;
    for(size_t i=0;i<indicesVector.size()-1;i++){
        if(!strncmp(curp,indicesVector[i].getId(),4)){
            encontrado=1;
            break;
        }
    }
    return encontrado;
}

