#include "archivo.h"

Archivo::Archivo()
{
    //escribir.open("datos.txt",ios::out|ios::app|ios::binary);
    //leer.open("datos.txt",ios::binary|ios::in|ios::app);
}

Archivo::~Archivo()
{

}

void Archivo::menu()
{
    int opc;
    if(!leer){
        cerr<<"No Se Pudo Abrir El Archivo"<<endl;
        exit(1);
    }
    do{
        system("cls");
        cout<<menuLectura<<"-. Crear"<<endl
            <<menuMostrar<<"-. Mostrar"<<endl
            <<menuModificar<<"-. Modificar"<<endl
            <<menuEliminarLogico<<".- Eliminar Logico"<<endl
            <<menuActivarLogica<<".- Activar Logica"<<endl
            <<menuSalir<<"-. Salir"<<endl;
        cin>>opc;
        switch (opc) {
            case menuLectura:
                lectura();
            break;
            case menuMostrar:
                mostrar(1);
            break;
            case menuModificar:
                modificar();
            break;
            case menuEliminarLogico:
                cambioLogica(1);
            break;
            case menuActivarLogica:
                cambioLogica(0);
            break;
            case menuSalir:

            break;
        }
    }while(opc!=menuSalir);
}

void Archivo::lectura()
{
    system("cls");
    escribir.open("datos.txt",ios::binary|ios::out|ios::app);

    ingresoDatos(1);

    endFileLeer();

    escribir.write(reinterpret_cast<const char*>(&caldera), sizeof (caldera));
    escribir.close();
}

int Archivo::mostrar(int bandera)
{
    system("cls");
    leer.open("datos.txt",ios::binary|ios::in|ios::app);

    if(emptyFile()||!leer.good()){
        cout<<"Archivo Vacio"<<endl;
        system("pause");
        return 1;
    }

    resetFileLeer();
    imprimirCabecera();
    while(!leer.eof()){
        leer.read(reinterpret_cast<char*>(&caldera),sizeof(Caldera));
        if(leer.eof())
            break;
        if(caldera.getBandera()&&bandera)
            imprimir(caldera);
        if(!caldera.getBandera()&&!bandera)
            imprimir(caldera);
    }
    getch();
    leer.close();
    return 0;
}

void Archivo::imprimir(Caldera calderaImpresion)
{
    cout<<setw(15)<<calderaImpresion.getCodigo()
        <<setw(15)<<calderaImpresion.getTemperatura()
        <<setw(15)<<calderaImpresion.getNumEmpleado()
        <<setw(15)<<calderaImpresion.getContador()<<endl;

}

void Archivo::imprimirCabecera()
{
    cout<<setw(15)<<"Codigo"<<setw(15)<<"Temperatura"<<setw(15)<<"NumEmpleado"<<setw(15)<<"Contador"<<endl<<endl<<endl;
}

void Archivo::modificar()
{
    system("cls");
    unsigned int x,x1;

    if(!validateBusqueda(&x,1))
        return;

    leer.open("datos.txt",ios::binary|ios::in|ios::app);

    leer.seekg((x-1)*sizeof(Caldera),leer.beg);
    leer.read(reinterpret_cast<char*>(&caldera),sizeof(Caldera));
    if(!caldera.getBandera()){
        cout<<"El Archivo No Se Encuentra"<<endl;
        getch();
        return;
    }

    imprimirCabecera();
    imprimir(caldera);

    cout<<"Desea Modificar 1-SI"<<endl;
    cin>>x1;
    if (x1!=1)
        return;
    leer.close();

    ingresoDatos(0);

    leer.close();

    escribir.open("datos.txt",ios::in|ios::out|ios::ate);
    escribir.seekp((x-1)*sizeof(Caldera),escribir.beg);
    escribir.write(reinterpret_cast<const char*>(&caldera), sizeof (Caldera));
    escribir.close();
}


int Archivo::validateBusqueda(unsigned int *buscarPosContador,int bandera)
{
    Caldera CalderaAux;

    if(mostrar(bandera))
        return 0;

    cout<<endl<<"Ingrese El Contador: "<<endl;
    cin>>*buscarPosContador;
    if(!validateContador(*buscarPosContador)){
        cout<<"Valor Ingresado No Valido"<<endl;
        system("pause");
        return 0;
    }
    return 1;
}

void Archivo::cambioLogica(int eliminacion)
{
    unsigned int x,x1;

    if(!validateBusqueda(&x,eliminacion))
        return;

    leer.open("datos.txt",ios::binary|ios::in|ios::app);

    leer.seekg((x-1)*sizeof(Caldera),leer.beg);
    leer.read(reinterpret_cast<char*>(&caldera),sizeof(Caldera));
    if(eliminacion&&!caldera.getBandera()){
        cout<<"El Archivo No Se Encuentra"<<endl;
        getch();
        return;
    }
    if(!eliminacion&&caldera.getBandera()){
        cout<<"El Archivo Se Encuentra Activado"<<endl;
        getch();
        return;
    }
    imprimirCabecera();
    imprimir(caldera);

    cout<<"Desea Eliminar Logicamente 1-SI"<<endl;
    cin>>x1;
    if (x1!=1)
        return;

    leer.close();
    caldera.setBandera(!caldera.getBandera());

    escribir.open("datos.txt",ios::in|ios::out|ios::ate);
    escribir.seekp((x-1)*sizeof(Caldera),escribir.beg);
    escribir.write(reinterpret_cast<const char*>(&caldera), sizeof (Caldera));
    escribir.close();
}

void Archivo::ingresoDatos(int opc)
{

    cout<<"Ingreso De Datos Caldera"<<endl;
    cout<<"Codigo"<<endl;
    cin>>calderaStruct.codigo;
    cout<<"Temperatura"<<endl;
    cin>>calderaStruct.temperatura;
    cout<<"Numero Empleado";
    cin>>calderaStruct.numEmpleado;
    if(!opc)
        calderaStruct.contador=caldera.getContador();

    asignacionDatos(opc);
}

void Archivo::asignacionDatos(int opc)
{
    caldera.setCodigo(calderaStruct.codigo);
    caldera.setTemperatura(calderaStruct.temperatura);
    caldera.setNumEmpleado(calderaStruct.numEmpleado);
    caldera.setBandera(1);
    if(opc)
        contadorIn();
    else
        caldera.setContador(calderaStruct.contador);
}

int Archivo::emptyFile()
{

    endFileLeer();
    int var = (leer.tellg()==0)?1:0;
    leer.clear();
    leer.seekg(0);

    return var;
}

void Archivo::resetFileLeer()
{

    leer.clear();
    leer.seekg(0);
}

void Archivo::endFileLeer()
{
    leer.clear();
    leer.seekg(0,leer.end);
}

int Archivo::validateContador(int x)
{
    leer.open("datos.txt",ios::binary|ios::in|ios::app);

    Caldera calderaAux;

    if(emptyFile())
        return 0;
    else{
        endFileLeer();
        long long pos=leer.tellg();
        pos=pos-sizeof(Caldera);
        leer.clear();
        leer.seekg(0,ios::beg);
        leer.seekg(pos);
        leer.read(reinterpret_cast<char*>(&calderaAux),sizeof(Caldera));
        leer.close();

        return (x>=1&&x<=calderaAux.getContador())?1:0;

    }
}

void Archivo::contadorIn()
{
    leer.open("datos.txt",ios::binary|ios::in|ios::app);

    Caldera calderaAux;

    if(emptyFile())
        caldera.setContador(1);
    else{
        endFileLeer();
        long long pos=leer.tellg();        
        pos=pos-sizeof(Caldera);
        leer.clear();
        leer.seekg(0,ios::beg);
        leer.seekg(pos);
        leer.read(reinterpret_cast<char*>(&calderaAux),sizeof(Caldera));
        caldera.setContador(calderaAux.getContador()+1);
    }
    leer.close();
}
