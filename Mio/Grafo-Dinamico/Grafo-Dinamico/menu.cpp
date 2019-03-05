#include "Menu.h"

Menu::Menu()
{

}

void Menu::insertarVertice()
{
    char origen[10];
    cin.ignore();
    cout<<"Ingrese el Vertice de Origen"<<endl;
    cin.getline(origen,10,'\n');

    grafo.insertarVertice(origen);
}

void Menu::insertarArista()
{
    char origen[10];
    char destino[10];
    int peso=1;
    bool dirigido;
    bool ponderado;

    cout<<"El grafo es dirigido 1-Si 0-No"<<endl;
    cin>>dirigido;

    cout<<"El grafo es ponderado 1-Si 0-No"<<endl;
    cin>>ponderado;

    cin.ignore();
    cout<<"Ingrese el origen"<<endl;
    cin.getline(origen,10,'\n');

    cout<<"Ingrese el destino"<<endl;
    cin.getline(destino,10,'\n');

    if(ponderado){
        cout<<"Ingrese el peso"<<endl;
        cin>>peso;
    }
    if(grafo.getVertice(origen)==NULL||grafo.getVertice(destino)==NULL)
        cout<<"Vertices No Encontrados"<<endl;
    else{
        if(!dirigido){
            grafo.insertarArista(grafo.getVertice(destino),grafo.getVertice(origen),peso);
            grafo.insertarArista(grafo.getVertice(origen),grafo.getVertice(destino),peso);
        }else
            grafo.insertarArista(grafo.getVertice(origen),grafo.getVertice(destino),peso);
        cout<<"Nodo Agregado Con exito"<<endl;
    }
    getch();
}

void Menu::mostar()
{
    grafo.listaAdyacencia();
    getch();
}

void Menu::menu()
{
    int opc;
    do{
        system("cls");
        cout<<menuInsertarVertice<<" Ingresar Vertice"<<endl
            <<menuInsertarArista<<" Ingresar Arista"<<endl
            <<menuMostrar<<" Mostar Tabla Adyacencias"<<endl
            <<menuSalir<<" Salir"<<endl;
        cin>>opc;
        switch (opc) {
            case menuInsertarVertice:
                insertarVertice();
            break;
            case menuInsertarArista:
                insertarArista();
            break;
            case menuMostrar:
                mostar();
            break;
            case menuSalir:
            break;
        }
    }while(opc!=menuSalir);
}
