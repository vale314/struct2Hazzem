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
       }
   }

}

int Grafo::name_to_int(const char nombresBuscar[10])
{
    Vertice vectorAux;
    int encontrado=0;
    int i=0;

    ifstream fileIn("vectoresNombres.txt",ios::in);
    while(!fileIn.eof()){
        //analizar el documento
        fileIn.read(reinterpret_cast<char *>(&vectorAux),sizeof (Vertice));
        if(fileIn.eof())
            break;
        if(vectorAux.getNombre()==nombresBuscar){
            encontrado=1;
            break;
        }
        i++;
    }
    fileIn.close();

    /* + si la lista de vectoresNombres:Vertice guardados esta !vacia
       i=i+vectoresNombre.size()
       if(i>10)
        return error llena;
    */

    if(encontrado)
        return i;
    if(!encontrado&&i<9){
        Vertice verticeNew(nombresBuscar,counter);
        counter++;
        //en vez de guardar meter a la lista vectoresNombres:Vertice
        ofstream fileOut("vectoresNombres.txt",ios::out);
           fileOut.write(reinterpret_cast<char *>(&verticeNew),sizeof (Vertice));
        fileOut.close();
        return i;
    }
    return -1;
}

void Grafo::insertarArista(const char nombreOrigen[10],const char nombreDestino[10], bool dirigido,bool pond,int pondNum)
{
    int origen;
    int destino;
    Arista arista;
    cout<<"llego"<<endl;
    origen=name_to_int(nombreOrigen);
    destino=name_to_int(nombreDestino);

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

void Grafo::mostrar()
{
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<aristas[i][j].getPeso();
            if(j==9)
                cout<<endl;
        }
    }
}
