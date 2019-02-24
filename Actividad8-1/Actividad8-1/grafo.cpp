#include "grafo.h"

Grafo::Grafo()
{
    resetGrafo();
}

void Grafo::resetGrafo()
{
   for(int i=0;i<10;i++){
       for(int j=0;j<10;j++){
            aristas[i][j].setPeso(0);
            aristas[i][j].setOrigen(0);
            aristas[i][j].setDestino(0);
       }
       vertice[i].setNumVertice(0);
       vertice[i].setNombre("");
   }
   vectoresNombres.clear();
   counter=0;
   nameArchivoVertices="";
   nameArchivoAristas="";
}

int Grafo::name_to_int(const char nombresBuscar[10])
{
    Vertice vectorAux;
    int encontrado=0;
    int i=0;
    bool fileRead=false;
    ifstream fileIn(nameArchivoVertices,ios::in|ios::binary);
    while(!fileIn.eof()&&fileIn.good()){
        //analizar el documento
        fileIn.read(reinterpret_cast<char *>(&vectorAux),sizeof (Vertice));
        if(fileIn.eof())
            break;
        fileRead=true;
        if(!strcmp(vectorAux.getNombre(),nombresBuscar)){
            getch();
            encontrado=1;
            break;
        }
        i++;
    }
    fileIn.close();

    cout<<"Antes IF"<<endl<<"i: "<<i<<endl;
    getch();

    if(!vectoresNombres.empty()&&!encontrado){
        for(size_t j=0;j<vectoresNombres.size();j++){
            if(!strcmp(vectoresNombres[j].getNombre(),nombresBuscar)){
                i=j;
                encontrado=1;
                break;
            }
        }
    }
    cout<<"Despues IF"<<endl<<"i: "<<i<<endl;
    getch();
    if(!encontrado&&i<9){
            i=vectoresNombres.size();
        Vertice verticeNew(nombresBuscar,i);
        counter++;
        vectoresNombres.push_back(verticeNew);
    }
    cout<<"Size: "<<vectoresNombres.size()<<endl;
    cout<<"Ultimo"<<endl<<"i: "<<i<<endl;
    getch();
    return i;

}

void Grafo::insertarArista(const char nombreOrigen[10],const char nombreDestino[10], bool dirigido,bool pond,int pondNum)
{
    int origen;
    int destino;
    Arista arista;
    origen=name_to_int(nombreOrigen);
    destino=name_to_int(nombreDestino);

    cout<<"Origen: "<<origen<<"Destino: "<<destino<<endl;
    getch();
    arista.setOrigen(origen);
    arista.setDestino(destino);

    if(!pond)
        arista.setPeso(1);
    else
        arista.setPeso(pondNum);

    aristas[origen][destino]=arista;
    if(!dirigido){
        arista.setDestino(origen);
        arista.setOrigen(destino);
        aristas[destino][origen]=arista;
    }
}

void Grafo::mostrarLogico()
{
    if(!vectoresNombres.size()){
        cout<<"Vector Vacio"<<endl;
        return;
    }
    mostrarLogicoCabeceras();
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<setw(10)<<aristas[i][j].getPeso();
            if(j==9)
                cout<<endl;
        }
    }

    for(size_t j=0;j<vectoresNombres.size();j++){
        for(size_t i=0;i<vectoresNombres.size();i++){
            cout<<"  Origen: "<<aristas[j][i].getOrigen();
            cout<<"  Destino: "<<aristas[j][i].getDestino();
            cout<<"  Peso: "<<aristas[j][i].getPeso();
        }
        cout<<endl;
    }
}

void Grafo::mostrarLogicoCabeceras()
{
    for(size_t i=0;i<vectoresNombres.size();i++)
        cout<<setw(10)<<vectoresNombres[i].getNumVertice()<<"|";
    cout<<endl;
    for(size_t i=0;i<vectoresNombres.size();i++)
        cout<<setw(10)<<vectoresNombres[i].getNombre();
    cout<<endl;
}

void Grafo::mostrarFisico()
{
    mostrarFiscoCabeceras();
    Arista aristasAux;
    ifstream fileInAristas(nameArchivoAristas,ios::in|ios::binary);
    if(!fileInAristas.good()){
        cout<<"Error File Not Find"<<endl;
        fileInAristas.close();
        return;
    }
    while(!fileInAristas.eof()){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                fileInAristas.read(reinterpret_cast<char *>(&aristasAux),sizeof (Arista));
                if(fileInAristas.eof())
                    break;
                cout<<setw(10)<<aristasAux.getPeso();
                if(j==9)
                    cout<<endl;
            }
        }
    }
    fileInAristas.close();
}

void Grafo::
mostrarFiscoCabeceras()
{
    Vertice vectorAux;


    ifstream fileInVertices(nameArchivoVertices,ios::in|ios::binary);
    if(!fileInVertices.good()){
        cout<<"Error File Not Find"<<endl;
        fileInVertices.close();
        return;
    }

    for(size_t i=0;i<10;i++)
        cout<<setw(10)<<i<<"|";
    cout<<endl;
    while(!fileInVertices.eof()){
        fileInVertices.read(reinterpret_cast<char *>(&vectorAux),sizeof (Vertice));
        if(fileInVertices.eof())
            break;
        cout<<setw(10)<<vectorAux.getNombre();
    }
    fileInVertices.close();
    cout<<endl;
}

void Grafo::guardar(string nameFileVertices,string nameFileAristas)
{
    Vertice verticeNew;

    nameArchivoVertices=nameFileVertices;
    nameArchivoAristas=nameFileAristas;

    ofstream fileOutVertices(nameArchivoVertices,ios::binary|ios::trunc);
        for(size_t i=0;i<vectoresNombres.size();i++)
            fileOutVertices.write(reinterpret_cast<char *>(&vectoresNombres[i]),sizeof (Vertice));
    fileOutVertices.close();

    ofstream fileOutAristas(nameArchivoAristas,ios::binary|ios::trunc);
        for(size_t i=0;i<10;i++){
            for(size_t j=0;j<10;j++)
                fileOutAristas.write(reinterpret_cast<char *>(&aristas[i][j]),sizeof (Arista));
        }
    fileOutAristas.close();
}

void Grafo::cargar(string nameFileVertices, string nameFileAristas)
{
    resetGrafo();
    nameArchivoVertices=nameFileVertices;
    nameArchivoAristas=nameFileAristas;

    Vertice vectorAux;

    ifstream fileInVertices(nameArchivoVertices,ios::in|ios::binary);
    if(!fileInVertices.good()){
        cout<<"Error File Not Find"<<endl;
        fileInVertices.close();
        getch();
        return;
    }
    while(!fileInVertices.eof()){
        fileInVertices.read(reinterpret_cast<char *>(&vectorAux),sizeof (Vertice));
        if(fileInVertices.eof())
            break;
        vectoresNombres.push_back(vectorAux);
    }
    fileInVertices.close();


    ifstream fileInAristas(nameArchivoAristas,ios::in|ios::binary);
    if(!fileInAristas.good()){
        cout<<"Error File Not Find"<<endl;
        fileInAristas.close();
        getch();
        return;
    }
    while(!fileInAristas.eof()){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++)
                fileInAristas.read(reinterpret_cast<char *>(&aristas[i][j]),sizeof (Arista));
        }
    }
    fileInAristas.close();
}

bool Grafo::editarVertice(const char nombre[10],const char nombreNew[10])
{
    for(size_t i=0;i<vectoresNombres.size();i++){
        if(!strcmp(vectoresNombres[i].getNombre(),nombre)){
            vectoresNombres[i].setNombre(nombreNew);
            return true;
        }
    }
    return false;

}

bool Grafo::editarArista(const char nombreOrigen[10], const char nombreDestino[10],int ponderacion,bool dirigido)
{
    int  origen=0;
    int destino=0;
    for(size_t i=0;i<vectoresNombres.size();i++){
        if(!strcmp(vectoresNombres[i].getNombre(),nombreOrigen))
            origen=vectoresNombres[i].getNumVertice();
        if(!strcmp(vectoresNombres[i].getNombre(),nombreDestino))
            destino=vectoresNombres[i].getNumVertice();
    }

    if(aristas[origen][destino].getPeso()==0)
        return false;

    aristas[origen][destino].setPeso(ponderacion);
    aristas[destino][origen].setPeso(0);
    if(!dirigido)
        aristas[destino][origen].setPeso(ponderacion);

    if(aristas[origen][destino].getPeso()==ponderacion)
        return true;

    return false;
}

bool Grafo::eliminarArista(const char nombreOrigen [10], const char nombreDestino [10])
{
    int  origen=0;
    int destino=0;
    bool encontrado1=false;
    bool encontrado2=false;
    for(size_t i=0;i<vectoresNombres.size();i++){
        if(!strcmp(vectoresNombres[i].getNombre(),nombreOrigen)){
            origen=vectoresNombres[i].getNumVertice();
            encontrado1=true;
        }
        if(!strcmp(vectoresNombres[i].getNombre(),nombreDestino)){
            destino=vectoresNombres[i].getNumVertice();
            encontrado2=true;
        }
    }

    if(aristas[origen][destino].getPeso()==0||!encontrado1|!encontrado2)
        return false;

    aristas[origen][destino].setPeso(0);
    aristas[destino][origen].setPeso(0);

    if(aristas[origen][destino].getPeso()==0)
        return true;

    return false;
}

bool Grafo::eliminarVertice(const char nombreOrigen[10])
{
    Arista arista;
    int  origen=0;
    bool encontrado1=false;
    for(size_t i=0;i<vectoresNombres.size();i++){
        if(!strcmp(vectoresNombres[i].getNombre(),nombreOrigen)){
            origen=vectoresNombres[i].getNumVertice();
            encontrado1=true;
        }
    }
    if(!encontrado1)
        return false;


    for(size_t i=0;i<vectoresNombres.size();i++){
        aristas[i][origen]=arista;
        aristas[origen][i]=arista;
    }

    for(size_t j=origen;j<vectoresNombres.size();j++){
        for(size_t i=0;i<vectoresNombres.size();i++){
             aristas[i][j]=aristas[i][j+1];
             aristas[j][i]=aristas[j+1][i];
        }
    }

    vectoresNombres.erease(origen);

    return true;
}

