#include "menu.h"

Menu::Menu()
{
    ofstream fileOut("vectoresNombres.txt",ios::app);
    fileOut.close();
    ofstream fileOut2("vectores.txt",ios::app);
    fileOut2.close();
}


void Menu::menu(){
    int opc;
    do{
        system("cls");
        cout<<menuInsertar<<"Ingresar Grafo"<<endl
            <<menuMostrar<<"Mostrar Grafo"<<endl
            <<menuGuardar<<"Menu Guardar"<<endl
            <<menuCargar<<"Menu Cargar"<<endl
            <<menuDescargar<<"Menu Descargar"<<endl
            <<menuEditar<<"Menu Editar"<<endl
            <<menuSalir<<"Salir"<<endl;
        cin>>opc;
        switch (opc) {
            case menuInsertar:
                insertar();
            break;
            case menuMostrar:
                mostrar();
            break;
            case menuGuardar:
                guardar();
            break;
            case menuCargar:
                cargar();
            break;
            case menuDescargar:
                descargar();
            break;
            case menuEditar:
                editar();
            break;
            case menuSalir:
            break;
        }
    }while(opc!=menuSalir);
}

void Menu::insertar()
{
    char nombreOrigen[10];
    char nombreDestino[10];
    bool dirigido,ponderado;
    int ponNum=1;

    cout<<"Ingrese el nombre De Origen"<<endl;
    cin.ignore();
    cin.getline(nombreOrigen,10);

    cout<<"Ingrese el nombre De Destino"<<endl;
        cin.getline(nombreDestino,10);

    cout<<"El Vertice es Dirigido 1-Si 0-No"<<endl;
    cin>>dirigido;
    cout<<"El Vertice es Ponderado 1-Si 0-No"<<endl;
    cin>>ponderado;

    if(ponderado){
        cout<<"El Valor De la ponderacion"<<endl;
        cin>>ponNum;
    }

    grafo.insertarArista(nombreOrigen,nombreDestino,dirigido,ponderado,ponNum);
}

void Menu::mostrar()
{
    int opc;
    cout<<"1-Logico 0 Fisico"<<endl;
    cin>>opc;
    if(opc)
        grafo.mostrarLogico();
    if(!opc)
        grafo.mostrarFisico();
    getch();
}


void Menu::guardar(){
    string nameFileAristas;

    cout<<"Ingrese El Nombre Del Archivo"<<endl;
    cin>>nameFileAristas;

    grafo.guardar(nameFileAristas+"Name.txt",nameFileAristas+".txt");
}

void Menu::cargar(){
    string nameFileAristas;

    cout<<"Ingrese El Nombre Del Archivo"<<endl;
    cin>>nameFileAristas;

    grafo.cargar(nameFileAristas+"Name.txt",nameFileAristas+".txt");
}

void Menu::descargar()
{
    grafo.resetGrafo();
}


void Menu::editar()
{
    int opc=0;
    do{
        system("cls");
        cout<<menuEVertice<<"Editar Vertice"<<endl
            <<menuEArista<<"Editar Arista"<<endl
            <<menuESalir<<"Salir"<<endl;
        cin>>opc;
        switch (opc) {
            case menuEVertice:
                editarVertice();
            break;
            case menuEArista:
                editarArista();
            break;
            case menuESalir:
            break;
        }
    }while(opc!=menuESalir);
}

void Menu::editarVertice()
{
    char nombre[10];
    char nombreNew[10];
    cin.ignore();
    cout<<"Ingrese el nombre de su vertice:"<<endl;
    cin.getline(nombre,10);

    cout<<"Ingrese el nombre nuevo"<<endl;
    cin.getline(nombreNew,10);

    if(grafo.editarVertice(nombre,nombreNew))
        cout<<"Cambio Hecho Con Exito"<<endl;
    else
        cout<<"No Se Encontro El Vertice"<<endl;

    getch();
}

void Menu::editarArista()
{
    char nombreOrigen[10];
    char nombreDestino[10];
    int ponderacion;
    bool dirigido;

    cin.ignore();
    cout<<"Ingrese El Origen"<<endl;
    cin>>nombreOrigen;

    cout<<"Ingrese El Destino"<<endl;
    cin>>nombreDestino;

    cout<<"Ingrese Su Ponderacion"<<endl;
    cin>>ponderacion;

    cout<<"Es Dirigido-1 No Dirigido-0"<<endl;
    cin>>dirigido;

    if(grafo.editarArista(nombreOrigen,nombreDestino,ponderacion,dirigido))
        cout<<"Se Cambio Con Exito"<<endl;
    else
        cout<<"Error Al Realizar Cambio"<<endl;
    getch();
}
