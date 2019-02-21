#include "menu.h"

Menu::Menu()
{
    V=10;
    reset();
    ofstream fileOut("vectoresNombres.txt",ios::app);
    fileOut.close();
    ofstream fileOut2("vectores.txt",ios::app);
    fileOut2.close();
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
    int i=0;

    ifstream fileIn("vectoresNombres.txt",ios::in);
    while(!fileIn.eof()){
        getline(fileIn,nombre,'|');
        if(fileIn.eof())
            break;
        if(nombre.compare(nombresBuscar)==0){
            encontrado=1;
            break;
        }
        i++;
    }
    fileIn.close();

    if(encontrado)
        return i;
    if(!encontrado&&i<9){
        ofstream fileOut("vectoresNombres.txt",ios::app);
           fileOut<<nombresBuscar<<"|";
        fileOut.close();
        return i;
//        nombres.push_back(nombresBuscar);
//        return i+nombres.size()-1;
    }
    return -1;
}

// Print adjacency list representaion ot graph
void Menu::printGraph()
{
    cargarNombres();
    printList();

        int num,i;
        i=0;
        cout<<setw(5);
        ifstream fileIn("vectores.txt",ios::in);
        while(!fileIn.eof()){
            if(i==10){
                cout<<endl;
                i=0;
            }
            fileIn.read(reinterpret_cast<char*>(&num),sizeof(int));
            if(fileIn.eof())
                break;
            cout<<num<<setw(5);
            i++;
        }
        fileIn.close();
        getch();
}

void Menu::printList()
{
    for(int i = 0;i<10;i++){
        cout<<setw(10)<<i;
    }
    cout<<endl;

    string nombre;
    ifstream fileIn("vectoresNombres.txt",ios::in);
    while(!fileIn.eof()){
        getline(fileIn,nombre,'|');
        if(fileIn.eof())
            break;
        cout<<setw(10)<<nombre;
    }
    fileIn.close();
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

void Menu::guardar()
{
    ofstream fileOut("vectores.txt",ios::out|ios::binary);
    for (int u = 0; u < 10; u++)
    {
        for (int it2 = 0; it2<10; it2++)
            fileOut.write(reinterpret_cast<const char*>(&adj[u][it2]),sizeof(int));
    }
    fileOut.close();
//    guardarNombres();
}

void Menu::guardarNombres()
{
    ofstream fileOut("vectoresNombres.txt",ios::app);
    while(!nombres.empty()){
        cout<<nombres.back()<<endl;
            fileOut<<nombres.back()<<"|";
            nombres.pop_back();
        }
    nombres.clear();
    getch();
    fileOut.close();
}

void Menu::cargar()
{
    ifstream fileIn("vectores.txt",ios::in);
    for (int u = 0; u < 10; u++)
    {
        for (int it2 = 0; it2<10; it2++)
            fileIn.read(reinterpret_cast<char*>(&adj[u][it2]),sizeof(int));
    }
    fileIn.close();
    cargarNombres();
}

void Menu::cargarNombres()
{
    string nombre;
    ifstream fileIn("vectoresNombres.txt",ios::in);
    while(!fileIn.eof()){
        getline(fileIn,nombre,'|');
        nombres.push_back(nombre);
        if(fileIn.eof())
            break;
    }
    fileIn.close();
}

void Menu::menu()
{
    int opc;
    do{
        system("cls");
        cout<<menuAgregar<<".- Agregar"<<endl
            <<menuMostrar<<".- Mostrar"<<endl
            <<menuGuardar<<".- Guardar"<<endl
            <<menuCargar<<".- Cargar"<<endl
            <<menuSalir<<".- Salir"<<endl;
        cin>>opc;
        switch (opc) {
            case menuAgregar:
                agregar();
            break;
            case menuMostrar:
                printGraph();
            break;
            case menuGuardar:
                guardar();
            break;
            case menuCargar:
                cargar();
            break;
        }
    }while(opc!=menuSalir);
}
