#include "menu.h"

Menu::Menu()
{
    V=10;
    reset();
}


// To add an edge
void Menu::addEdge(int u,int v, int wt,int doble,int pond)
{
    //aqui se doble enlaza
    if(!pond)
        wt=1;
    adj[u][v]=wt;
    if(doble)
        adj[v][u]=wt;
}

void Menu::reset(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            adj[i][j]=0;
        }
    }
}

int Menu::searchNombre(string nombresBuscar){
    string nombre;
    int encontrado=0;
    int i;
    if(nombres.size()>=10){
        cout<<"Lleno"<<endl;
        return 10;
    }
    for(i=0;i<nombres.size();i++){
        if(nombres[i].compare(nombresBuscar)==0){
            encontrado=1;
            break;
        }
    }
    if(encontrado)
        return i;
    if(!encontrado)
        nombres.push_back(nombresBuscar);
        return nombres.size()-1;
}

// Print adjacency list representaion ot graph
void Menu::printGraph()
{
    printList();
    for (int u = 0; u < 10; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
            for (int it2 = 0; it2<10; it2++){
                if(adj[u][it2]!=0){
                    cout << "\tNode " << it2 << " with edge weight =";
                    if(adj[u][it2]==1)
                        cout<< "conectado" << "\n";
                    else
                        cout<< adj[u][it2] << "\n";

                }
            }
            cout << "\n";
        }
        cout << "\n";
        getch();
}

void Menu::printList()
{
    for(int i = 0;i<10;i++){
        cout<<setw(10)<<i;
    }
    cout<<endl;
    if(nombres.empty())
        return;
    for(int i = 0;i<nombres.size();i++){
        cout<<setw(10)<<nombres[i];
    }
    cout<<endl<<endl;
}

void Menu::agregar()
{
    string nombre;
    int nodoOrigen,nodoDestino,nodoP,doble,pond=1;

    cout<<"Es doble Enalzado: 1-Si 0-No"<<endl;
    cin>>doble;

    cout<<"Tiene Ponderacion 1-Si 0-No"<<endl;
    cin>>pond;

    cin.ignore();
    cout<<"Ingrese el nombre del origen"<<endl;
    getline(cin,nombre);
    nodoOrigen=searchNombre(nombre);

    cout<<"Ingrese el nombre de destino"<<endl;
    getline(cin,nombre);
    nodoDestino=searchNombre(nombre);

    if(pond){
        cout<<"Ponderacion"<<endl;
        cin>>nodoP;
    }
    addEdge(nodoOrigen, nodoDestino, nodoP,doble,pond);

}

void Menu::menu()
{
    int opc;
    do{
        system("cls");
        cout<<menuAgregar<<".- Agregar"<<endl
            <<menuMostrar<<".- Mostrar"<<endl
            <<menuSalir<<".- Salir"<<endl;
        cin>>opc;
        switch (opc) {
            case menuAgregar:
                agregar();
            break;
            case menuMostrar:
                printGraph();
            break;
        }
    }while(opc!=menuSalir);
}
