#include "grafo.h"

Grafo::Grafo()
{
    initialize();
}

int Grafo::tamano()
{
    int i=0;
    Vertice *aux;
    aux=vertice;
    while(aux != NULL){
        i++;
        aux = aux->siguiente;
    }
    return i;
}

bool Grafo::empty()
{
    if(vertice==NULL)
        return true;
    else
        return false;
}

void Grafo::initialize()
{
    vertice=NULL;
}

Vertice *Grafo::getVertice(char nombre[10])
{
    Vertice *aux;
    aux=vertice;
    while(aux !=NULL){
        if(!strcmp(aux->getNombre(),nombre))
            return aux;
        aux=aux->siguiente;
    }
    return NULL;
}


void Grafo::insertarArista(Vertice *origen, Vertice *destino, int peso)
{
    Arista *nuevo= new Arista;
    nuevo->setPeso(peso);
    nuevo->adyacencia=NULL;
    nuevo->siguiente=NULL;


    Arista *aux;

    aux=origen->adyacencia;

    if(aux==NULL){
        origen->adyacencia=nuevo;
        nuevo->adyacencia=destino;
    }else{
        while (aux->siguiente !=NULL) {
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
        nuevo->adyacencia=destino;
    }
}

void Grafo::listaAdyacencia()
{
    Vertice *verticeAux;
    Arista *aristaAux;

    verticeAux=vertice;
    while (verticeAux!=NULL) {
        cout<<verticeAux->getNombre()<<"->";

        aristaAux= verticeAux->adyacencia;
        while (aristaAux!=NULL) {
            cout<<aristaAux->getPeso()<<"->"<<aristaAux->adyacencia->getNombre()<<"->";
            aristaAux=aristaAux->siguiente;
        }
        verticeAux=verticeAux->siguiente;
        cout<<""<<endl;
    }
}

void Grafo::guardar()
{
    Vertice verticeNew;
    string nameArchivoGrafo;
    cin.ignore();
    cout<<"Ingrese el Nombre Del grafo"<<endl;
    getline(cin,nameArchivoGrafo);

    ofstream fileOutVertices(nameArchivoGrafo+"Name.txt",ios::binary|ios::trunc);
        Vertice *aux;
        aux=vertice;

        while(aux != NULL){
            fileOutVertices.write(reinterpret_cast<char *>(aux->getNombre()),sizeof (10));
            aux=aux->siguiente;
        }
     fileOutVertices.close();

     ofstream fileOutAristas(nameArchivoGrafo+"Aristas.txt",ios::binary|ios::trunc);

     Vertice *verticeAux;
     Arista *aristaAux;

     verticeAux=vertice;
     while (verticeAux!=NULL) {
         aristaAux= verticeAux->adyacencia;
         while (aristaAux!=NULL) {
             fileOutAristas.write(reinterpret_cast<char *>(verticeAux->getNombre()),sizeof (10));
             int peso= aristaAux->getPeso();
             fileOutAristas.write(reinterpret_cast<char *>(&peso),sizeof (4));
             fileOutAristas.write(reinterpret_cast<char *>(aristaAux->adyacencia->getNombre()),sizeof (4));
             aristaAux=aristaAux->siguiente;
         }
         verticeAux=verticeAux->siguiente;
     }
      fileOutAristas.close();

}

void Grafo::cargar()
{
    string nameArchivoGrafo;
    cin.ignore();
    cout<<"Ingrese El Nombre Graph"<<endl;
    getline(cin,nameArchivoGrafo);

    char verticeNombre[10];

    ifstream fileInVertices(nameArchivoGrafo+"Name.txt",ios::in|ios::binary);
    if(!fileInVertices.good()){
        cout<<"Error File Not Find"<<endl;
        fileInVertices.close();
        return;
    }
    while(!fileInVertices.eof()){
        fileInVertices.read(reinterpret_cast<char *>(&verticeNombre),sizeof (10));
        if(fileInVertices.eof())
            break;

        insertarVertice(verticeNombre);
    }
    fileInVertices.close();


    char verticeO[10]="";
    char verticeD[10]="";
    int peso;

    ifstream fileInAristas(nameArchivoGrafo+"Aristas.txt",ios::in|ios::binary);
    if(!fileInAristas.good()){
        cout<<"Error File Not Find"<<endl;
        fileInAristas.close();
        return;
    }
    while(!fileInAristas.eof()){
        fileInAristas.read(reinterpret_cast<char *>(&verticeO),sizeof (10));
        fileInAristas.read(reinterpret_cast<char *>(&peso),sizeof (4));
        fileInAristas.read(reinterpret_cast<char *>(&verticeD),sizeof (10));
        if(fileInAristas.eof())
            break;
        insertarArista(getVertice(verticeO),getVertice(verticeD),peso);
    }
    fileInAristas.close();
}

int Grafo::posVertice(char nombre[10])
{
    Vertice *aux;
    aux=vertice;
    int i=0;
    while(aux != NULL){
        if(!strcmp(aux->getNombre(),nombre))
            return i;
        i++;
        aux=aux->siguiente;
    }
    return -1;
}

void Grafo::matrizAdyacencias()
{
    Vertice *aux;
    aux=vertice;
    cout<<setw(2)<<right;
    while(aux != NULL){
        cout<<aux->getNombre()<<setw(2);
        aux=aux->siguiente;
    }
    cout<<endl;

    Vertice *verticeAux;
    Arista *aristaAux;

    int i=0;
    verticeAux=vertice;
    cout<<setw(1);
    while (verticeAux!=NULL) {
        cout<<verticeAux->getNombre()<<setw(2)<<right;

        aristaAux= verticeAux->adyacencia;
        while (aristaAux!=NULL) {
            int pos=posVertice(aristaAux->adyacencia->getNombre());
            cout<<aristaAux->getPeso()<<setw(2);
            aristaAux=aristaAux->siguiente;
        }
        verticeAux=verticeAux->siguiente;
        cout<<""<<endl;
    }
}

void Grafo::eliminarArista(Vertice *origen, Vertice *destino)
{
    if(origen==NULL||destino==NULL){
        cout<<"Origen O Destino Incorrectos"<<endl;
        return;
    }
    Arista *actual;
    Arista *anterior;
    bool encontrado=false;
    actual= origen->adyacencia;

    if(actual ==NULL)
        cout<<"No Se Encontraron Aristas"<<endl;
    else if(actual->adyacencia==destino){

        origen->adyacencia=actual->siguiente;
        delete (actual);
    }else{
        while(actual != NULL){
            if(actual->adyacencia==destino){
                encontrado=true;
                anterior->siguiente=actual->siguiente;
                delete (actual);
                break;
            }
            anterior=actual;
            actual=actual->siguiente;
        }
    }
}

void Grafo::eliminarVertice(Vertice *eliminar)
{
    if(eliminar==NULL){
        cout<<"No Se encuentra ese vertice"<<endl;
        return;
    }
    Vertice *actual;
    Vertice *anterior;

    Arista *aux;

    actual=vertice;
    while(actual!=NULL){
        aux=actual->adyacencia;
        while (aux != NULL) {
            if(aux->adyacencia==eliminar){
                eliminarArista(actual,aux->adyacencia);
                break;
            }
            aux=aux->siguiente;
        }
        actual = actual->siguiente;
    }
    actual = vertice;
    if(vertice==eliminar){
        vertice=vertice->siguiente;
        delete actual;
    }else{
        cout<<"Here"<<endl;
        while(actual != eliminar&&actual != NULL){
            anterior=actual;
            actual=actual->siguiente;
        }
        anterior->siguiente=actual->siguiente;
        delete (actual);
    }
}

void Grafo::modificarArista(Vertice *origen, Vertice *destino, int ponderacion)
{
    if(origen==NULL||destino==NULL){
        cout<<"Origen O Destino Incorrectos"<<endl;
        return;
    }
    Arista *actual;
    bool encontrado=false;

    actual= origen->adyacencia;
    if(actual ==NULL)
        cout<<"No Se Encontraron Aristas"<<endl;
    else if(actual->adyacencia==destino)
        actual->setPeso(ponderacion);
    else{
        while(actual != NULL){
            if(actual->adyacencia==destino){
                encontrado=true;
                actual->setPeso(ponderacion);
                break;
            }
            actual=actual->siguiente;
        }
    }
}

void Grafo::modificarVertice(Vertice *origen)
{
    if(origen==NULL){
        cout<<"No Se encuentra ese vertice"<<endl;
        return;
    }
    Vertice *actual;
    Vertice *anterior;
    Arista *aux;
    char nombre[10];

    cin.ignore();
    cout<<"Ingrese El Nuevo Nombre"<<endl;
    cin.getline(nombre,10,'\n');

    actual=vertice;
    if(vertice==origen){
        vertice->setNombre(nombre);
    }else{
        while(actual != origen&&actual != NULL)
            actual=actual->siguiente;
        actual->setNombre(nombre);
    }
}

void Grafo::recorridoAnchura(Vertice *origen)
{
    bool band=0;
    bool band2=0;
    Vertice *actual;
    LDL<Vertice*> cola;
    LDL<Vertice*> lista;

    cola.push_back(origen);

    while(!cola.empty()){
        actual=cola.front();
        cola.pop_front();

        for(size_t i=0;i<lista.size();i++){
            if(lista[i]==actual)
                band=true;
        }
        if(!band){
            cout<<actual->getNombre()<<" ";
            lista.push_back(actual);

            Arista *aux;
            aux=actual->adyacencia;
            while(aux!=NULL){
                band2=0;
                for(size_t i=0;i<lista.size();i++){
                    if(aux->adyacencia==lista[i]){
                        band2=true;
                    }

                }
                if(!band2)
                    cola.push_back(aux->adyacencia);
                aux=aux->siguiente;
            }
        }
    }
}

void Grafo::insertarVertice(char nombre[10])
{
    Vertice *nuevo=new Vertice;
    nuevo->setNombre(nombre);
    nuevo->siguiente=NULL;
    nuevo->adyacencia=NULL;

    if(empty()){
        vertice=nuevo;
    }
    else{
        Vertice *aux;
        aux=vertice;
        while(aux->siguiente != NULL){
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
    }

}
