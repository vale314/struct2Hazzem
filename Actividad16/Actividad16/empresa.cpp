#include "empresa.h"

Empresa::Empresa()
{
    cant=0;
    cargarVector();
    cargarArbolArchivo();
    cargarArbol20();
}

Empresa::~Empresa()
{
    guardarVector();
    guardarArbolArchivo();
}

void Empresa::menu()
{
    int opc;
    do{
        system("cls");
        cout<<"\t\t\t\t\t\t\t\tElementos En Arbol: "<<indicesAVLTree.cantidad()<<endl;
        cout<<menuAgregar<<".- Agregar"<<endl
            <<menuConsultar<<".- Consultar"<<endl
            <<menuImprimir<<".- Imprimir"<<endl
            <<menuEliminarLogico<<".- Eliminar Logico"<<endl
            <<menuActivar<<".- Activar"<<endl
            <<menuEliminar<<".- Eliminar Fisico"<<endl
            <<menuModificar<<".- Modificar"<<endl
            <<menuMostrarArbol<<".- Mostrar Arbol"<<endl
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
            case menuMostrarArbol:
                mostrarArbol();
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
    Indice indice,indiceAux;
    fstream escrAspirante("aspirantes.txt",ios::out|ios::app);

    escrAspirante<<aspirante.getNombre()<<"#"<<aspirante.getCurp()<<"#"<<aspirante.getEdad()<<"#"<<aspirante.getPuesto()<<"#"<<aspirante.getBandera()<<";";
    if(indicesVector.empty()){
        indice.setId(aspirante.getCurp());
        indice.setPos(0);
        indicesVector.push_back(indice);

        indiceAux.setId(aspirante.getCurp());
        indiceAux.setPos(indice.getPos());

        indice.setId("-1");
        indice.setPos(escrAspirante.tellp());
        indicesVector.push_back(indice);

    }else{
        indice.setId(aspirante.getCurp());
        indice.setPos(indicesVector.back().getPos());
        indicesVector.pop_back();
        indicesVector.push_back(indice);

        indiceAux.setId(aspirante.getCurp());
        indiceAux.setPos(indice.getPos());

        indice.setId("-1");
        indice.setPos(indicesVector.back().getPos()+escrAspirante.tellp());
        indicesVector.push_back(indice);
    }

    escrAspirante.close();
    cant++;

    guardarEnArbol(indiceAux);
}

void Empresa::cargarArbolArchivo()
{
    Indice indiceAux;
    ifstream entrada("ArbolAVL.txt",ios::in);
    if(!entrada.good()){
        cout<<"No Se Encontro Archivo";
        return;
    }
    while(!entrada.eof()){
        entrada.read(reinterpret_cast<char*>(&indiceAux), sizeof (Indice));
        if(entrada.eof())
            break;

        indicesAVLTree.insert(indiceAux);
    }
    entrada.close();
}

void Empresa::guardarArbolArchivo()
{
    Ldl <Indice> elemtento(indicesAVLTree.getAllItems());


    ofstream salida("ArbolAVL.txt",ios::out);
    for(size_t i=0;i<elemtento.size();i++){
        salida.write(reinterpret_cast<const char*>(&elemtento[i]), sizeof (Indice));
    }
    salida.close();

    for(size_t i=0;i<elemtento.size();i++)
        cout<<elemtento[i].getId()<<" "<<elemtento[i].getPos()<<endl<<""<<elemtento[i].getContador();
    getch();

}

bool Empresa::comprobar20()
{
    cout<<"Cantidad: "<<indicesAVLTree.cantidad()<<"Porcentaje: "<<cant*0.2<<endl;
    if(indicesAVLTree.cantidad()+1<(cant*0.2))
        return true;
    return false;
}

void Empresa::guardarEnArbol(Indice indice)
{
    if(comprobar20())
        if(!indicesAVLTree.insert(indice))
            cargarArbol20();
}

void Empresa::cargarArbol20()
{
    if(!comprobar20())
        return;
    Indice indiceAux;
    leerIndice.open("indices.txt",ios::in);
    if(!leerIndice.good()){
        cerr<<"Error Al leer"<<endl;
        exit(1);
    }
    while(!leerIndice.eof()){
        leerIndice.read(reinterpret_cast<char*>(&indiceAux),sizeof(indiceAux));
        if(leerIndice.eof())
            break;
        if(strcmp(indiceAux.getId(),"-1"))
            if(indicesAVLTree.insert(indiceAux))
                if(!comprobar20())
                    break;
    }
    leerIndice.close();
}

void Empresa::mostrarArbol()
{
    Ldl<Indice> elem(indicesAVLTree.getAllItems());
    cout<<"Tam De Arbol: "<<indicesAVLTree.cantidad()<<endl;

    cout<<endl;
    cout<<"Elementos Del Arbol ------------"<<endl;

    for(size_t i=0;i<elem.size();i++)
        cout<<"Indice: "<<elem[i].getId()<<" Pos:"<<elem[i].getPos()<<endl;

    cout<<endl<<endl<<endl<<"Arbol--------"<<endl<<endl;
    indicesAVLTree.mostrar();

    cout<<"InOrder"<<endl;
    indicesAVLTree.inOrder();

    elem.clear();
    getch();
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


   ifstream entrada("cantidad.txt",ios::in);
       entrada.read(reinterpret_cast<char*>(&cant),sizeof (int));
   entrada.close();
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

    ofstream salida("cantidad.txt",ios::out);
        salida.write(reinterpret_cast<char*>(&cant),sizeof (int));
    salida.close();
}

void Empresa::consultar()
{
    Indice indice,indiceAux;
    char curp[5];
    size_t i;
    int encontrado=0;
    cout<<"Ingrese el id a buscar"<<endl;
    cin.ignore();
    cin.getline(curp,10,'\n');

    indiceAux.setId(curp);

    //buscamos el nodo el arbol si lo encuntra aumntamos el contador
    if(indicesAVLTree.find(indiceAux)!=nullptr){
        indice.setId(indicesAVLTree.find(indiceAux)->getId());
        indice.setPos(indicesAVLTree.find(indiceAux)->getPos());
        indice.setContador(indicesAVLTree.find(indiceAux)->getContador());
        indice.setContador(indice.getContador()+1);

        indicesAVLTree.deleteKey(indiceAux);
        indicesAVLTree.deleteKey(indiceAux);

        indicesAVLTree.insert(indice);
        encontrado=1;
    }

    Aspirantes aspirante;
    if(encontrado){
        //si encontro el nodo en el arbol muestra
        leerAspirante.open("aspirantes.txt",ios::binary);

            long long pos= indice.getPos();
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
        leerAspirante.seekg(0);
        leerIndice.close();
    }else{
        //busca el nodo el archivo indices
        bool find=false;
        leerIndice.open("indices.txt",ios::binary|ios::in);
        if(!leerIndice.good()){
            cerr<<"Error Al leer"<<endl;
            exit(1);
        }
        while(!leerIndice.eof()){
            leerIndice.read(reinterpret_cast<char*>(&indiceAux),sizeof(indiceAux));
            if(leerIndice.eof())
                break;
            if(!strcmp(indiceAux.getId(),curp)){
                find=true;
                break;
            }

        }
       leerIndice.close();
       if(find){
           //si lo encontro en el archivo de indices muestra
           leerAspirante.open("aspirantes.txt",ios::binary);

               long long pos= indiceAux.getPos();
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
           leerAspirante.seekg(0);
           leerIndice.close();

           Indice indiceOld;

           indiceOld.setId(indicesAVLTree.findMinor()->getId());

           cout<<"El Indice Menor es: "<<indicesAVLTree.findMinor()->getId()<<endl;
           indicesAVLTree.deleteKey(indiceOld);
           indicesAVLTree.deleteKey(indiceOld);

           indiceAux.setContador(indiceAux.getContador()+1);
           indicesAVLTree.insert(indiceAux);
       }else{
           cout<<"Nodo No Encontrado"<<endl;
       }
    }
    getch();
}

void Empresa::nuevoNodoArbol(Indice)
{

}

//void Empresa::consultar()
//{
//    if(indicesVector.empty()){
//        cout<<"Se Encuentra Vacio"<<endl;
//        getch();
//        return;
//    }

//    char curp[5];
//    size_t i;
//    int encontrado=0;
//    cout<<"Ingrese el id a buscar"<<endl;
//    cin.ignore();
//    cin.getline(curp,10,'\n');

//    for(i=0;i<indicesVector.size()-1;i++){
//        if(!strncmp(curp,indicesVector[i].getId(),5)){
//            encontrado=1;
//            break;
//        }
//    }

//    Aspirantes aspirante;
//    leerAspirante.open("aspirantes.txt",ios::binary);
//    if(encontrado){
//        long long pos= indicesVector[i].getPos();
//        leerAspirante.clear();
//        leerAspirante.seekg(pos);
//        getline(leerAspirante,aspiranteStruct.nombre,'#');
//        getline(leerAspirante,aspiranteStruct.curpS,'#');
//        getline(leerAspirante,aspiranteStruct.edad,'#');
//        getline(leerAspirante,aspiranteStruct.puesto,'#');
//        getline(leerAspirante,aspiranteStruct.bandera,';');
//        if(aspiranteStruct.bandera=="1")
//            imprimirStruct();
//        else
//            cout<<"No Se Encuentra"<<endl;
//    }else{
//        cout<<"No Se Encuentra"<<endl;
//    }
//    leerAspirante.seekg(0);
//    leerIndice.close();
//    getch();
//}

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

//void Empresa::imprimir(size_t i,int bandera)
//{
//    Aspirantes aspirante;
//    leerAspirante.open("aspirantes.txt",ios::binary);

//        long long pos= indicesVectorAux[i].getPos();
//        leerAspirante.clear();
//        leerAspirante.seekg(pos);
//        getline(leerAspirante,aspiranteStruct.nombre,'#');
//        getline(leerAspirante,aspiranteStruct.curpS,'#');
//        getline(leerAspirante,aspiranteStruct.edad,'#');
//        getline(leerAspirante,aspiranteStruct.puesto,'#');
//        getline(leerAspirante,aspiranteStruct.bandera,';');
//        if((aspiranteStruct.bandera=="1"&&bandera)||(aspiranteStruct.bandera=="0"&&!bandera))
//            imprimirStruct();

//    leerAspirante.seekg(0);
//    leerIndice.close();
//}

//void Empresa::imprimirAll(int bandera)
//{
//    if(indicesVector.empty()){
//        cout<<"El Index Se Encuentra Solo"<<endl;
//        getch();
//        return;
//    }
//    for(size_t i=0;i<=indicesVector.size()-1;i++)
//           indicesVectorAux.push_back(indicesVector[i]);

////    for(size_t i=0;i<=indicesVectorAux.size()-1;i++)
////        cout<<indicesVectorAux[i]<<endl;

//    cout<<"--------------ALL--------------------"<<endl<<endl;

//    indicesVectorAux.bubbleSort();

//    for(size_t i=0;i<=indicesVectorAux.size()-2;i++)
//        imprimir(i,bandera);


//    indicesVectorAux.clear();

//    getch();
//}

void Empresa::imprimir(long long pos,int bandera)
{
    Aspirantes aspirante;
    leerAspirante.open("aspirantes.txt",ios::binary);

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
    leerAspirante.close();
}

void Empresa::imprimirAll(int bandera)
{

    cout<<"--------------ALL--------------------"<<endl<<endl;
    imprimirCabeceras();
    Indice indiceAux;
    leerIndice.open("indices.txt",ios::binary|ios::in);
    if(!leerIndice.good()){
        cerr<<"Error Al leer"<<endl;
        exit(1);
    }
    while(!leerIndice.eof()){
        leerIndice.read(reinterpret_cast<char*>(&indiceAux),sizeof(indiceAux));
        if(leerIndice.eof()){
            break;
        }else
            imprimir(indiceAux.getPos(),bandera);
    }
   leerIndice.close();
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
