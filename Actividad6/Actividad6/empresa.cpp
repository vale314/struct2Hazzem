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
            <<menuEliminarLogico<<".- Eliminar Logico"<<endl
            <<menuActivar<<".- Activar"<<endl
            <<menuEliminar<<".- Eliminar Fisico"<<endl
            <<menuModificar<<".- Modificar"<<endl
            <<menuSalir<<".- Salir"<<endl;
        cin>>opc;
        switch (opc) {
            case menuAgregar:
                pedirDatos(1);
            break;
            case menuConsultar:
                consultar();
            break;
            case menuImprimir:
                imprimirAll(1);
            break;
            case menuActivar:
                activar(1);
            break;
            case menuEliminarLogico:
                activar(0);
            break;
            case menuEliminar:
                eliminarFisico();
            break;
            case menuModificar:
                modificar();
            break;
            case menuSalir:
            break;

        }
    }while(opc!=menuSalir);
}

void Empresa::pedirDatos(int a)
{
    cin.ignore();
    cout<<"Ingrese El Nombre"<<endl;
    getline(cin,aspiranteStruct.nombre);
    if(a){
        cout<<"Ingrese El Curp"<<endl;
        cin.getline(aspiranteStruct.curp,10,'\n');
        if(int i= validateCurp(aspiranteStruct.curp)){
            if(i==1)
                cout<<"Error Curp DUPLICADO"<<endl;
            else
                cout<<"Error Curp Incorrecto"<<endl;
            getch();
            return;
        }
    }
    cout<<"Ingrese La Edad"<<endl;
    getline(cin,aspiranteStruct.edad);
    cout<<"Ingrese El Puesto"<<endl;
    getline(cin,aspiranteStruct.puesto);
    llenarDatos(a);
}

void Empresa::llenarDatos(int i)
{
    aspirante.setNombre(aspiranteStruct.nombre);
    aspirante.setCurp(aspiranteStruct.curp);
    aspirante.setEdad(aspiranteStruct.edad);
    aspirante.setPuesto(aspiranteStruct.puesto);
    aspirante.setBandera(1);
    if(i)
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

    char curp[5];
    size_t i;
    int encontrado=0;
    cout<<"Ingrese el id a buscar"<<endl;
    cin.ignore();
    cin.getline(curp,10,'\n');

    for(i=0;i<indicesVector.size()-1;i++){
        if(!strncmp(curp,indicesVector[i].getId(),5)){
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
        <<endl;
}

void Empresa::imprimirCabeceras()
{
    cout<<setw(15)<<"Nombre"<<setw(15)<<"Curp"<<setw(15)<<"Edad"<<setw(15)<<"Puesto"<<setw(15)<<endl<<endl<<endl;
}

void Empresa::imprimir(size_t i,int bandera)
{
    Aspirantes aspirante;
    leerAspirante.open("aspirantes.txt",ios::binary);

        long long pos= indicesVectorAux[i].getPos();
        leerAspirante.clear();
        leerAspirante.seekg(pos);
        getline(leerAspirante,aspiranteStruct.nombre,'#');
        getline(leerAspirante,aspiranteStruct.curpS,'#');
        getline(leerAspirante,aspiranteStruct.edad,'#');
        getline(leerAspirante,aspiranteStruct.puesto,'#');
        getline(leerAspirante,aspiranteStruct.bandera,';');
        if((aspiranteStruct.bandera=="1"&&bandera)||(aspiranteStruct.bandera=="0"&&!bandera))
            imprimirStruct();

    leerAspirante.seekg(0);
    leerIndice.close();
}

void Empresa::imprimirAll(int bandera)
{
    if(indicesVector.empty()){
        cout<<"El Index Se Encuentra Solo"<<endl;
        getch();
        return;
    }
    for(size_t i=0;i<=indicesVector.size()-1;i++)
           indicesVectorAux.push_back(indicesVector[i]);

    for(size_t i=0;i<=indicesVectorAux.size()-1;i++)
        cout<<indicesVectorAux[i]<<endl;

    cout<<"--------------LDL--------------------"<<endl<<endl;

    indicesVectorAux.bubbleSort();

    for(size_t i=0;i<=indicesVectorAux.size()-2;i++)
        imprimir(i,bandera);


    indicesVectorAux.clear();

    getch();
}

int Empresa::validateCurp(const char curp[5])
{
    if(strlen(curp)<4 || strlen(curp)>=5)
        return 2;
    if(indicesVector.empty())
        return 0;
    int encontrado=0;
    for(size_t i=0;i<indicesVector.size()-1;i++){
        if(!strncmp(curp,indicesVector[i].getId(),5)){
            encontrado=1;
            break;
        }
    }
    return encontrado;
}

void Empresa::eliminarLogico()
{

}

void Empresa::activar(int d)
{
    system("cls");
    imprimirCabeceras();
    imprimirAll(!d);
    char curp[5];
    if(d)
        cout<<"Ingrese el curp a activar: "<<endl;
    else
        cout<<"Ingrese el curp a desactivar"<<endl;
    cin.ignore();
    cin.getline(curp,10,'\n');

    if(indicesVector.empty()){
        cout<<"Se Encuentra Vacio"<<endl;
        getch();
        return;
    }
    size_t i;
    int encontrado = 0;
    int valido=0;
    for(i=0;i<indicesVector.size()-1;i++){
        if(!strncmp(curp,indicesVector[i].getId(),5)){
            encontrado=1;
            break;
        }
    }

    Aspirantes aspirante;
    long long posR=0;
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
        if((aspiranteStruct.bandera=="0"&&d)||(aspiranteStruct.bandera=="1"&&!d)){
            posR=leerAspirante.tellg();
            posR=posR-2;
            valido=1;
        }else
            cout<<"No Se Encuentra"<<endl;
    }else{
        cout<<"No Se Encuentra"<<endl;
    }
    leerAspirante.seekg(0);
    leerAspirante.close();
    escrAspirante.close();
    if(encontrado&&valido){
        ofstream escrAspirantes("aspirantes.txt",ios::in|ios::out|ios::binary);
        escrAspirantes.seekp(posR);
        if(d)
            escrAspirantes<<"1;";
        else
            escrAspirantes<<"0;";
        escrAspirantes.close();
    }
    getch();
}

void Empresa::eliminarFisico()
{
    system("cls");
    imprimirCabeceras();
    imprimirAll(1);
    char curp[5];
    cout<<"Ingrese el curp a eliminar: "<<endl;

    cin.ignore();
    cin.getline(curp,10,'\n');

    if(indicesVector.empty()){
        cout<<"Se Encuentra Vacio"<<endl;
        getch();
        return;
    }
    size_t i;
    int encontrado = 0;
    for(i=0;i<indicesVector.size()-1;i++){
        if(!strncmp(curp,indicesVector[i].getId(),5)){
            encontrado=1;
            break;
        }
    }

    if(!encontrado){
        cout<<"No Se encuentra"<<endl;
        getch();
        return ;
    }

        Aspirantes aspirante;
        char varA[512];
        char varB[512];
        long long posInicio=0,posFin=0;

        fstream escrAspirantes("aspirantes.txt",ios::in|ios::out|ios::binary);
        escrAspirantes.read(reinterpret_cast<char*>(&varA),indicesVector[i].getPos());
        getline(escrAspirantes,aspiranteStruct.nombre,'#');
        getline(escrAspirantes,aspiranteStruct.curpS,'#');
        getline(escrAspirantes,aspiranteStruct.edad,'#');
        getline(escrAspirantes,aspiranteStruct.puesto,'#');
        getline(escrAspirantes,aspiranteStruct.bandera,';');
        if(!aspiranteStruct.bandera.compare("0")){
            cout<<"No Se Encuentra"<<endl;
            escrAspirantes.close();
            getch();
            return;
        }
        posInicio=escrAspirantes.tellg();
        escrAspirantes.seekg(0,escrAspirantes.end);
        posFin=escrAspirantes.tellg();
        escrAspirantes.close();

        ofstream escrAspirantesAux("aspirantesAux.txt",ios::out|ios::app);
            escrAspirantesAux.write(reinterpret_cast<char*>(&varA),(int)indicesVector[i].getPos());
        escrAspirantesAux.close();

        fstream escrAspirantes1("aspirantes.txt",ios::in|ios::out|ios::binary);
                escrAspirantes1.seekg(posInicio);
                escrAspirantes1.read(reinterpret_cast<char*>(&varB),posFin-posInicio);
        escrAspirantes1.close();

        ofstream escrAspirantesAux1("aspirantesAux.txt",ios::app);
            escrAspirantesAux1.write(reinterpret_cast<char*>(&varB),posFin-posInicio);
        escrAspirantesAux1.close();

        reOrganizarPunteros(indicesVector[i].getPos());

        getch();
}

void Empresa::modificar()
{
    system("cls");
    imprimirCabeceras();
    imprimirAll(1);
    char curp[5];
    cout<<"Ingrese el curp a Modificar: "<<endl;

    cin.ignore();
    cin.getline(curp,10,'\n');

    if(indicesVector.empty()){
        cout<<"Se Encuentra Vacio"<<endl;
        getch();
        return;
    }
    size_t i;
    int encontrado = 0;
    for(i=0;i<indicesVector.size()-1;i++){
        if(!strncmp(curp,indicesVector[i].getId(),5)){
            encontrado=1;
            break;
        }
    }

    if(!encontrado){
        cout<<"No Se encuentra"<<endl;
        getch();
        return ;
    }
        char varA[512];
        char varB[512];
        long long posInicio=0,posFin=0;

        fstream escrAspirantes("aspirantes.txt",ios::in|ios::out|ios::binary);
        escrAspirantes.read(reinterpret_cast<char*>(&varA),indicesVector[i].getPos());
        getline(escrAspirantes,aspiranteStruct.nombre,'#');
        getline(escrAspirantes,aspiranteStruct.curpS,'#');
        getline(escrAspirantes,aspiranteStruct.edad,'#');
        getline(escrAspirantes,aspiranteStruct.puesto,'#');
        getline(escrAspirantes,aspiranteStruct.bandera,';');
        if(!aspiranteStruct.bandera.compare("0")){
            cout<<"No Se Encuentra"<<endl;
            escrAspirantes.close();
            getch();
            return;
        }
        posInicio=escrAspirantes.tellg();
        escrAspirantes.seekg(0,escrAspirantes.end);
        posFin=escrAspirantes.tellg();
        escrAspirantes.close();

        pedirDatos(0);
        ofstream escrAspirantesAux("aspirantesAux.txt",ios::out|ios::app);
            escrAspirantesAux.write(reinterpret_cast<char*>(&varA),(int)indicesVector[i].getPos());
            escrAspirantesAux<<aspirante.getNombre()<<"#"<<aspiranteStruct.curpS<<"#"<<aspirante.getEdad()<<"#"<<aspirante.getPuesto()<<"#"<<aspirante.getBandera()<<";";
        escrAspirantesAux.close();

        fstream escrAspirantes1("aspirantes.txt",ios::in|ios::out|ios::binary);
                escrAspirantes1.seekg(posInicio);
                escrAspirantes1.read(reinterpret_cast<char*>(&varB),posFin-posInicio);
        escrAspirantes1.close();

        ofstream escrAspirantesAux1("aspirantesAux.txt",ios::app);
            escrAspirantesAux1.write(reinterpret_cast<char*>(&varB),posFin-posInicio);
        escrAspirantesAux1.close();
        //MANDARLE LA SIGUIENTE POSICION
        reOrganizarPunteros(indicesVector[i].getPos());

    getch();
}

void Empresa::reOrganizarPunteros(long long posInicio)
{

    do{
        if(indicesVector.back().getPos()>=posInicio)
            indicesVector.pop_back();
        else
            break;
    }while(!indicesVector.empty());


    Indice indiceAux;
    indiceAux.setId("-1");
    indiceAux.setPos(posInicio);
    indicesVector.push_back(indiceAux);

    ifstream leerAspirantesAux("aspirantesAux.txt",ios::in|ios::binary);
    leerAspirantesAux.seekg(posInicio);
    while(!leerAspirantesAux.eof()){
        getline(leerAspirantesAux,aspiranteStruct.nombre,'#');
        getline(leerAspirantesAux,aspiranteStruct.curpS,'#');
        getline(leerAspirantesAux,aspiranteStruct.edad,'#');
        getline(leerAspirantesAux,aspiranteStruct.puesto,'#');
        getline(leerAspirantesAux,aspiranteStruct.bandera,';');
        if(leerAspirantesAux.eof())
             break;
        indiceAux.setId(aspiranteStruct.curpS.c_str());
        indiceAux.setPos(indicesVector.back().getPos());
        indicesVector.pop_back();
        indicesVector.push_back(indiceAux);
        indiceAux.setId("-1");
        indiceAux.setPos(leerAspirantesAux.tellg());
        indicesVector.push_back(indiceAux);
    }
    leerAspirantesAux.close();

    leerAspirante.close();
    escrAspirante.close();
    remove("aspirantes.txt");
    rename("aspirantesAux.txt","aspirantes.txt");
}
