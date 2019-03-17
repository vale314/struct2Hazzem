#include "biblioteca.h"

Biblioteca::Biblioteca()
{
    initializate();
}

Biblioteca::~Biblioteca()
{
    guardar();
}

void Biblioteca::initializate()
{
    listaInvertida = NULL;
    categoria = NULL;
    direccion = NULL;
    cantidadDireccion=0;
}

bool Biblioteca::emptyCategoria()
{
    if(categoria==NULL)
        return true;
    else
        return false;
}

bool Biblioteca::buscarCategoria(char nombre[TAMCHAR])
{
    Categoria *auxC=categoria;

    while(auxC->siguiente!=NULL){
        if(!strcmp(auxC->getNombre(),nombre))
            return true;
        auxC=auxC->siguiente;
    }
    return  false;

}

Categoria *Biblioteca::retornarCategoria(char nombre[TAMCHAR])
{
    Categoria *auxC=categoria;

    while (auxC->siguiente != NULL) {
        if(!strcmp(auxC->getNombre(),nombre))
            return auxC;
        auxC=auxC->siguiente;
    }
    return NULL;
}

int Biblioteca::posCategoria(Categoria * actualC)
{
    Categoria *auxC;
    int pos;
    pos=0;
    auxC=categoria;
    while (auxC->siguiente != NULL) {
        if(auxC==actualC)
            return pos;
        pos++;
    }
    return -1;
}


bool Biblioteca::validaId(int id)
{
    Lista_Invertida * auxL;
    auxL=listaInvertida;

    if(emptyCategoria())
        return false;

    while(auxL->siguiente != NULL){
        if(auxL->getId()==id)
            return true;
        auxL=auxL->siguiente;
    }
    return false;
}

void Biblioteca::insertarLibro(Libro libro)
{
    Categoria *auxC;
    Lista_Invertida *auxL;
    if(validaId(libro.getId())){
        cout<<"Id duplciado"<<endl;
        return;
    }
    guardarBook(libro);
    if(emptyCategoria()){
        cout<<"Primer Libro"<<endl;
        Lista_Invertida *listaNew= new Lista_Invertida;
        listaNew->setId(libro.getId());
        listaNew->nextCategoria=NULL;
        listaNew->siguiente=NULL;

        listaInvertida=listaNew;

        Categoria *catNew= new Categoria;
        catNew->setNombre(libro.getGenero());
        catNew->siguiente=NULL;
        catNew->origen=listaNew;

        categoria=catNew;
        return;
    }
    if(buscarCategoria(libro.getGenero())){
        Lista_Invertida *auxL1;
        cout<<"Misma Categoria"<<endl;
        auxC=retornarCategoria(libro.getGenero());

        auxL1=auxC->origen;
        while (auxL1->nextCategoria != NULL)
            auxL1=auxL1->nextCategoria;

        auxL=listaInvertida;
        while(auxL->siguiente!=NULL)
            auxL=auxL->siguiente;

        Lista_Invertida *listaNew= new Lista_Invertida;
        listaNew->setId(libro.getId());
        listaNew->nextCategoria=NULL;
        listaNew->siguiente=NULL;

        auxL->siguiente=listaNew;
        auxL1->nextCategoria=listaNew;

        return;
    }
    cout<<"Nueva Categoria"<<endl;
    auxC=categoria;
    while (auxC->siguiente !=NULL)
        auxC=auxC->siguiente;

    auxL=listaInvertida;
    while(auxL->siguiente!=NULL)
          auxL=auxL->siguiente;

    Lista_Invertida *listaNew= new Lista_Invertida;
    listaNew->setId(libro.getId());
    listaNew->nextCategoria=NULL;
    listaNew->siguiente=NULL;

    Categoria *catNew = new Categoria;
    catNew->setNombre(libro.getGenero());
    catNew->siguiente=NULL;
    catNew->origen=listaNew;

    auxL->siguiente=listaNew;
    auxC->siguiente=catNew;

    return;
}

int Biblioteca::posLista(Lista_Invertida * actualLis)
{
    Lista_Invertida *auxL;
    int pos;
    pos=0;
    auxL=listaInvertida;
    while (auxL!= NULL) {
        if(auxL==actualLis)
            return pos;
        pos++;
        auxL=auxL->siguiente;
    }
    return -1;
}

void Biblioteca::imprimirLista()
{
    Lista_Invertida * auxL;
    auxL=listaInvertida;
    while (auxL!=NULL) {
        cout<<"Origen: "<<auxL<<endl;
        cout<<"Id: "<<auxL->getId()<<endl;
        cout<<"Destino: "<<auxL->siguiente<<endl;
        auxL=auxL->siguiente;
    }
}

void Biblioteca::guardar()
{

    guardarListaInvertida();
//    guardarCategoria();
//    guardarCategoria();
}

void Biblioteca::guardarListaInvertida()
{
    Lista_Invertida *auxL;
    auxL=listaInvertida;
    int id;
    ofstream salida("lista.dat",ios::binary|ios::trunc);
        while(auxL!=NULL){
            id=auxL->getId();
            salida.write(reinterpret_cast<const char *>(&id),sizeof (int));
            auxL=auxL->siguiente;
        }
    salida.close();

    auxL=listaInvertida;
    int i=0;
    int pos;
    ofstream salidaAux("listaConection.dat",ios::out|ios::trunc);
        while(auxL!=NULL){
            if(auxL->nextCategoria!=NULL){
                salidaAux.write(reinterpret_cast<char* >(&i),sizeof (int));
                pos=posLista(auxL->nextCategoria);
                salidaAux.write(reinterpret_cast<char *>(&pos),sizeof (int));
            }
            auxL=auxL->siguiente;
            i++;
        }
    salidaAux.close();

}

void Biblioteca::guardarCategoria()
{
    Categoria *auxC;
    auxC=categoria;
    ofstream salida("categoria.dat",ios::out|ios::trunc);
        while(auxC->siguiente!=NULL){
            salida.write(reinterpret_cast<char *>(auxC->getNombre()),sizeof (int));
            auxC=auxC->siguiente;
        }
    salida.close();

    auxC=categoria;
    int i=0;
    ofstream salidaAux("categoriaConection.dat",ios::out|ios::trunc);
        while(auxC->siguiente!=NULL){
            if(auxC->origen!=NULL){
                salidaAux.write(reinterpret_cast<char *>(&i),sizeof (int));
                salidaAux.write(reinterpret_cast<char *>(posLista(auxC->origen)),sizeof (int));
            }
            auxC=auxC->siguiente;
            i++;
        }
    salidaAux.close();
}

void Biblioteca::guardarDireccion()
{

    Direccion *auxD;
    auxD=direccion;
    ofstream salida("direccion.dat",ios::out|ios::trunc);
        while(auxD->siguiente!=NULL){
            salida.write(reinterpret_cast<char *>(auxD->getId()),sizeof (int));
            salida.write(reinterpret_cast<char *>(auxD->getPos()),sizeof (long long));
            auxD=auxD->siguiente;
        }
        salida.close();
}

void Biblioteca::guardarBook(Libro libro)
{
    long long pos;
    pos=0;
    ofstream salida("book.dat",ios::out|ios::app);
        salida.write(reinterpret_cast<char *>(&libro),sizeof (Libro));
        cantidadDireccion++;
    salida.close();

    pos=(cantidadDireccion-1)*sizeof (Libro);

    cout<<pos<<endl;


    Direccion *direcNew= new Direccion;
    direcNew->setId(libro.getId());
    direcNew->setPos(pos);
    direcNew->siguiente=NULL;

    if(emptyCategoria()){
        direccion=direcNew;
        return;
    }

    Direccion *auxD;
    auxD=direccion;
    while (auxD->siguiente!=NULL)
        auxD=auxD->siguiente;

    auxD->siguiente=direcNew;
}

