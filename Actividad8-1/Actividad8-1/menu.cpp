#include "menu.h"

Menu::Menu()
{

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
            <<menuEliminar<<"Menu Eliminar"<<endl
            <<menuImpresionAnchura<<"Impresion Anchura"<<endl
            <<menuImpresionProfundidad<<"Impresion Profundidad"<<endl
            <<menuRutaAnchura<<"Ruta Anchura"<<endl
            <<menuRutaProfundidad<<"Rota Profundidad"<<endl
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
            case menuEliminar:
                eliminar();
            break;
            case menuImpresionAnchura:
                impresionAnchura();
            break;
            case menuImpresionProfundidad:
                impresionProfundidad();
            break;
            case menuRutaAnchura:
                rutaAnchura();
            break;
            case menuRutaProfundidad:
                rutaProfundidad();
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

void Menu::eliminar()
{
    int opc=0;
    do{
        system("cls");
        cout<<menuElVertice<<"Eliminar Vertice"<<endl
            <<menuElArista<<"Eliminar Arista"<<endl
            <<menuElSalir<<"Salir"<<endl;
        cin>>opc;
        switch (opc) {
            case menuElVertice:
                eliminarVertice();
            break;
            case menuElArista:
                eliminarArista();
            break;
            case menuElSalir:
            break;
        }
    }while(opc!=menuElSalir);
}

void Menu::eliminarVertice()
{
    char nombre[10];
    cin.ignore();
    cout<<"Ingrese El Vertice"<<endl;
    cin.getline(nombre,10);
    if(grafo.eliminarVertice(nombre))
        cout<<"Eliminado Con Exito"<<endl;
    else
        cout<<"No Se Elimino"<<endl;
    getch();
}

void Menu::eliminarArista()
{
    char nombreOrigen[10];
    char nombreDestino[10];

    cin.ignore();
    cout<<"Ingrese El Vertice De Origen"<<endl;
    cin>>nombreOrigen;

    cout<<"Ingrese El Vertice De Destino"<<endl;
    cin>>nombreDestino;

    if(grafo.eliminarArista(nombreOrigen,nombreDestino))
        cout<<"Eliminado Con Exito"<<endl;
    else
        cout<<"No Se Pudo Eliminar"<<endl;
    getch();
}

void Menu::impresionAnchura()
{
    int origen;
    cout<<"Ingrese el origen"<<endl;
    cin>>origen;
    grafo.impresionAnchura(origen);
    getch();
}

void Menu::impresionProfundidad()
{
    int origen;
    cout<<"Ingrese el origen"<<endl;
    cin>>origen;
    grafo.impresionProfundidad(origen);
    getch();
}

void Menu::rutaAnchura()
{
    int origen;
    int destino;
    cout<<"Ingrese el origen"<<endl;
    cin>>origen;
    cout<<"Ingrese el destino"<<endl;
    cin>>destino;
    grafo.rutaAnchura(origen,destino);
    getch();
}

void Menu::rutaProfundidad()
{
    int origen;
    int destino;
    cout<<"Ingrese el origen"<<endl;
    cin>>origen;
    cout<<"Ingrese el destino"<<endl;
    cin>>destino;
    grafo.rutaProfundidad(origen,destino);
    getch();

}
