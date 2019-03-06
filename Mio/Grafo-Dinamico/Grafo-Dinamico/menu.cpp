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
    int opc;
    do{
        system("cls");
        cout<<menuMostrarLista<<" Lista De Adyacencia"<<endl
             <<menuMostrarMatriz<<" Matriz De Adyacencia"<<endl
             <<menuMostarSalir<<" Salir"<<endl;
        cin>>opc;
        switch(opc){
            case menuMostrarLista:
                grafo.listaAdyacencia();
                getch();
            break;
            case menuMostrarMatriz:
                grafo.matrizAdyacencias();
                getch();
            break;
            case menuMostarSalir:
            break;
        }
    }while(opc!=menuMostarSalir);
}

void Menu::guardar()
{
    grafo.guardar();
    getch();
}

void Menu::cargar()
{
    grafo.cargar();
    getch();
}

void Menu::eliminarArista()
{
    char nombreO[10];
    char nombreD[10];

    cin.ignore();
    cout<<"Ingrese el Nombre Origen"<<endl;
    cin.getline(nombreO,10,'\n');

    cout<<"Ingrese el Nombre Destino"<<endl;
    cin.getline(nombreD,10,'\n');

    grafo.eliminarArista(grafo.getVertice(nombreO),grafo.getVertice(nombreD));
    grafo.eliminarArista(grafo.getVertice(nombreD),grafo.getVertice(nombreO));

    getch();
}

void Menu::eliminarVertice()
{
    char nombreO[10];
    cin.ignore();
    cout<<"Ingrese el Nombre"<<endl;
    cin.getline(nombreO,10,'\n');
    grafo.eliminarVertice(grafo.getVertice(nombreO));

    getch();
}

void Menu::modificarArista()
{
    char nombreO[10];
    char nombreD[10];
    int ponderacion;
    int doble;

    cin.ignore();
    cout<<"Ingrese el Nombre Origen"<<endl;
    cin.getline(nombreO,10,'\n');

    cout<<"Ingrese el Nombre Destino"<<endl;
    cin.getline(nombreD,10,'\n');

    cout<<"Ingrese la Ponderacion"<<endl;
    cin>>ponderacion;

    cout<<"Sera Bidireccional 1-SI 0-NO"<<endl;
    cin>>doble;
        grafo.modificarArista(grafo.getVertice(nombreO),grafo.getVertice(nombreD),ponderacion);
    if(doble)
        grafo.modificarArista(grafo.getVertice(nombreD),grafo.getVertice(nombreO),ponderacion);

    getch();
}

void Menu::modificarVertice()
{
    char nombreO[10];
    cin.ignore();
    cout<<"Ingrese El Vector"<<endl;
    cin.getline(nombreO,10,'\n');
    grafo.modificarVertice(grafo.getVertice(nombreO));
    getch();
}

void Menu::recorridoAnchura()
{
    char nombreO[10];
    cin.ignore();
    cout<<"Ingrese El Origen"<<endl;
    cin.getline(nombreO,10,'\n');
    grafo.recorridoAnchura(grafo.getVertice(nombreO));
    getch();
}

void Menu::recorridoProfundidad()
{
    char nombreO[10];
    cin.ignore();
    cout<<"Ingrese El Origen"<<endl;
    cin.getline(nombreO,10,'\n');
    grafo.recorridoProfundidad(grafo.getVertice(nombreO));
    getch();
}

void Menu::menu()
{
    int opc;
    do{
        system("cls");
        cout<<menuInsertarVertice<<" Ingresar Vertice"<<endl
            <<menuInsertarArista<<" Ingresar Arista"<<endl
            <<menuMostrar<<" Mostar"<<endl
            <<menuGuardar<<" Guardar"<<endl
            <<menuCargar<<" Cargar"<<endl
            <<menuEliminarArista<<" Eliminar Arista"<<endl
            <<menuEliminarVertice<<" Eliminar Vertice"<<endl
            <<menuModificarArista<<" Modificar Arista"<<endl
            <<menuModificarVertice<<" Modificar Vertice"<<endl
            <<menuRecorridoAnchura<<" Recorrido En Anchura"<<endl
            <<menuRecorridoProfundidad<<" Recorrido En Profundidad"<<endl
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
            case menuGuardar:
                guardar();
            break;
            case menuCargar:
                cargar();
            break;
            case menuEliminarArista:
                eliminarArista();
            break;
            case menuEliminarVertice:
                eliminarVertice();
            break;
            case menuModificarArista:
                modificarArista();
            break;
            case menuModificarVertice:
                modificarVertice();
            break;
            case menuRecorridoAnchura:
                recorridoAnchura();
            break;
            case menuRecorridoProfundidad:
                recorridoProfundidad();
            break;
            case menuSalir:
            break;
        }
    }while(opc!=menuSalir);
}

