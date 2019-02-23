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

    if(!vectoresNombres.empty()&&!encontrado){
        for(size_t j=0;j<vectoresNombres.size();j++){
            if(!strcmp(vectoresNombres[j].getNombre(),nombresBuscar)){
                if(i)
                    i=i+j+1;
                else
                    i=i+j;
                encontrado=1;
                break;
            }
        }
    }

    if(!encontrado&&i<9){
        if(!fileRead)
            i=i+vectoresNombres.size();
        Vertice verticeNew(nombresBuscar,counter);
        counter++;
        vectoresNombres.push_back(verticeNew);
    }
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
    if(!dirigido)
        aristas[destino][origen]=arista;
}

void Grafo::mostrarLogico()
{
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<aristas[i][j].getPeso();
            if(j==9)
                cout<<endl;
        }
    }
}

void Grafo::mostrarFisico()
{
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
                cout<<aristasAux.getPeso();
                if(j==9)
                    cout<<endl;
            }
        }
    }
    fileInAristas.close();
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

