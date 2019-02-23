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
        cout<<menuInsertar<<"Ingresar Grafo"<<endl
            <<menuMostrar<<"Mostrar Grafo"<<endl
            <<menuSalir<<"Salir"<<endl;
        cin>>opc;
        switch (opc) {
            case menuInsertar:
                insertar();
            break;
            case menuMostrar:
                mostrar();
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
    cin.ignore();
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
    grafo.mostrar();
    getch();
}
