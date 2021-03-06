#include "biblioteca.h"

Biblioteca::Biblioteca()
{
    initializate();
    cargar();
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

    while(auxC!=NULL){
        if(!strcmp(auxC->getNombre(),nombre))
            return true;
        auxC=auxC->siguiente;
    }
    return false;

}

Categoria *Biblioteca::retornarCategoria(char nombre[TAMCHAR])
{
    Categoria *auxC=categoria;

    while (auxC!= NULL) {
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

Lista_Invertida *Biblioteca::retornarOrigen(char nombre[TAMCHAR])
{
    Categoria *auxC;
    auxC=categoria;

    while(auxC!=NULL){
        if(!strcmp(auxC->getNombre(),nombre))
            return auxC->origen;
        auxC=auxC->siguiente;
    }
    return NULL;
}

void Biblioteca::insertarCargaCategoria(char nombre[TAMCHAR])
{
    Categoria *auxC;
    auxC=categoria;

    Categoria *cateNew = new Categoria;
    cateNew->setNombre(nombre);
    cateNew->origen=NULL;
    cateNew->siguiente=NULL;

    if(auxC==NULL){
        categoria=cateNew;
        return;
    }

    while(auxC->siguiente!=NULL)
        auxC=auxC->siguiente;
    auxC->siguiente=cateNew;
}

Categoria * Biblioteca::retornarCategoria(int origen)
{
    Categoria * auxC;
    int i=0;

    auxC=categoria;
    while (auxC!=NULL) {
        if(i==origen)
            return auxC;
        i++;
        auxC=auxC->siguiente;
    }
    return NULL;
}

void Biblioteca::insertarConexionCategoria(int origen, int destino)
{
    Categoria *auxC;
    Lista_Invertida *auxL;



    auxC=retornarCategoria(origen);
    auxL=retornarElmento(destino);

    auxC->origen=auxL;

}

bool Biblioteca::verificarPrimero(Lista_Invertida *origen)
{
    Categoria* auxC;
    auxC=categoria;
    while(auxC!=NULL){
        if(auxC->origen==origen)
            return true;
        auxC=auxC->siguiente;
    }
    return false;
}

Categoria *Biblioteca::retornarCategoria(Lista_Invertida * origen)
{
    Categoria* auxC;
    auxC=categoria;
    while(auxC!=NULL){
        if(auxC->origen==origen)
            return auxC;
        auxC=auxC->siguiente;
    }
    return NULL;
}

void Biblioteca::eliminarCategoria(Categoria *origen)
{
    Categoria* auxC;

    if(categoria==origen){
        if(categoria->siguiente==NULL){
            categoria=NULL;
            return;
        }
        categoria=categoria->siguiente;
        return;
    }

    auxC=categoria;
    cout<<origen->getNombre()<<endl;
    while (auxC->siguiente!=origen&&auxC!=NULL)
        auxC=auxC->siguiente;
    auxC->siguiente=origen->siguiente;
}


bool Biblioteca::validaId(int id)
{
    Lista_Invertida * auxL;
    auxL=listaInvertida;

    if(emptyCategoria())
        return false;

    while(auxL!= NULL){
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
        cout<<"Next: "<<auxL->nextCategoria<<endl;
        cout<<"Destino: "<<auxL->siguiente<<endl;
        cout<<endl;
        auxL=auxL->siguiente;
    }
}

void Biblioteca::insertarCarga(int id)
{
    Lista_Invertida *auxL;
    auxL=listaInvertida;

    Lista_Invertida *listNew = new Lista_Invertida;
    listNew->setId(id);
    listNew->siguiente=NULL;
    listNew->nextCategoria=NULL;

    if(auxL==NULL){
        listaInvertida=listNew;
        return;
    }

    while(auxL->siguiente!=NULL)
        auxL=auxL->siguiente;
    auxL->siguiente=listNew;
}

void Biblioteca::insertarConexionLista(int origen, int destino)
{
    Lista_Invertida *auxL;
    Lista_Invertida *auxL1;

    auxL=retornarElmento(origen);
    auxL1=retornarElmento(destino);

    auxL->nextCategoria=auxL1;


}

Lista_Invertida *Biblioteca::retornarElmento(int origen)
{
    int i=0;
    Lista_Invertida * auxL;
    auxL=listaInvertida;
    while (auxL!=NULL) {
        if(i==origen)
            return auxL;
        i++;
        auxL=auxL->siguiente;
    }
    return NULL;
}

Lista_Invertida *Biblioteca::buscarElemento(int id)
{
    Lista_Invertida * auxL;
    auxL=listaInvertida;
    while (auxL!=NULL) {
        if(auxL->getId()==id)
            return auxL;
        auxL=auxL->siguiente;
    }
    return NULL;
}

void Biblioteca::eliminarLista(int origen)
{
    Lista_Invertida* auxL= buscarElemento(origen);
    Lista_Invertida *auxL1;
    if(auxL==NULL){
        cout<<"Elemento No Encontrado"<<endl;
        return;
    }
    eliminarDireccion(origen);
    //verificarSi Existe
    Categoria *elimC=retornarCategoria(auxL); /*Retorna si es origen de una categoria si no NULL*/
    if(elimC==NULL){
            auxL1=listaInvertida;
            while(auxL1->nextCategoria!=auxL&&auxL1!=NULL)
                auxL1=auxL1->siguiente;
            auxL1->nextCategoria=auxL->nextCategoria;

            if(auxL==listaInvertida)
                    listaInvertida=listaInvertida->siguiente;
            else{
                auxL1=listaInvertida;
                while(auxL1->siguiente!=auxL&&auxL1!=NULL)
                    auxL1=auxL1->siguiente;
                auxL1->siguiente=auxL->siguiente;
            }
            return;

    }
    if(auxL==listaInvertida)
        listaInvertida=listaInvertida->siguiente;
     else{
        auxL1=listaInvertida;
        while(auxL1->siguiente!=auxL&&auxL1!=NULL)
            auxL1=auxL1->siguiente;
        auxL1->siguiente=auxL->siguiente;
        }


    if(auxL->nextCategoria==NULL)
        eliminarCategoria(elimC);
    else
        elimC->origen=auxL->nextCategoria;

}

void Biblioteca::modificar(int id,Libro libro)
{
    eliminarLista(id);
    insertarLibro(libro);
}

long long Biblioteca::obtenerPos(int id)
{
    Direccion *auxD;
    auxD=direccion;

    while(auxD!=NULL){
        if(auxD->getId()==id)
            return auxD->getPos();
        auxD=auxD->siguiente;
    }
    return -1;
}

void Biblioteca::insertarCargarDireccion(int id, long long pos)
{
    Direccion * auxD;
    auxD=direccion;

    Direccion * direcNew = new Direccion;
    direcNew->setId(id);
    direcNew->setPos(pos);
    direcNew->siguiente=NULL;

    cantidadDireccion++;
    if(auxD==NULL){
        direccion=direcNew;
        return;
    }

    while (auxD->siguiente!=NULL)
        auxD=auxD->siguiente;
    auxD->siguiente=direcNew;
}

void Biblioteca::eliminarDireccion(int id)
{
    long long pos = obtenerPos(id);
    if(pos==-1)
        return;

    eliminarArchivo(pos);
}

void Biblioteca::resetDireccion()
{
    direccion=NULL;
    cantidadDireccion=0;
}


void Biblioteca::reposicionarDireccion()
{
    resetDireccion();

    Direccion *auxD;
    auxD=direccion;
    long long pos=0;

    Libro libro;
    ifstream entrada("book.dat",ios::in);
    if(!entrada.good()){
        cout<<"Error al abrir el archivo"<<endl;
        return;
    }
    while(!entrada.eof()){
        pos=entrada.tellg();
        entrada.read(reinterpret_cast<char*>(&libro),sizeof(Libro));
        if(entrada.eof())
            break;
        insertarCargarDireccion(libro.getId(),pos);
    }
    entrada.close();
}
void Biblioteca::mostrar()
{
    Libro libro;
    ifstream entrada("book.dat",ios::in);
    while(!entrada.eof()){
        entrada.read(reinterpret_cast<char*>(&libro),sizeof (Libro));
        if(entrada.eof())
            break;
        cout<<libro<<endl;
    }
    entrada.close();

}

void Biblioteca::eliminarArchivo(long long pos)
{
    Libro libro;

    ofstream salida("bookAux.dat",ios::out|ios::app);
    ifstream entrada("book.dat",ios::in);
    if(!entrada.good()||!salida.good()){
        cout<<"Error en Archivo"<<endl;
        return;
    }
    while(!entrada.eof()){
        if(entrada.tellg()!=pos){
            entrada.read(reinterpret_cast<char*>(&libro),sizeof (Libro));
            if(entrada.eof())
                    break;
            salida.write(reinterpret_cast<char*>(&libro),sizeof (Libro));
        }else
            entrada.read(reinterpret_cast<char*>(&libro),sizeof (Libro));
    }
    entrada.close();
    salida.close();
    remove("book.dat");
    rename("bookAux.dat","book.dat");
    reposicionarDireccion();
}

void Biblioteca::mostrarGeneros()
{
    Categoria* auxC;
    auxC=categoria;

    while(auxC!=NULL){
        cout<<auxC->getNombre()<<endl;
        auxC=auxC->siguiente;
    }

}

void Biblioteca::mostrarPorGenero(char genero [TAMCHAR])
{
    Lista_Invertida *auxL;
    auxL=retornarOrigen(genero);

    if(auxL==NULL){
        cout<<"El Elmeneto Buscado No EXISTE"<<endl;
        return;
    }
    long long id=0;
    while(auxL!=NULL){
        id=obtenerPos(auxL->getId());
        mostrarPorPos(id);
        auxL=auxL->nextCategoria;
    }
}

void Biblioteca::mostrarPorPos(long long pos)
{
    Libro libro;
    ifstream leer("book.dat",ios::in);
        leer.seekg(pos);
        leer.read(reinterpret_cast<char *>(&libro),sizeof(Libro));
        cout<<libro<<endl;
    leer.close();
}

void Biblioteca::guardar()
{
    guardarDireccion();
    guardarListaInvertida();
    guardarCategoria();
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
        while(auxC!=NULL){
            salida.write(reinterpret_cast<char *>(auxC->getNombre()),TAMCHAR);
            //no escribe completo el nombre en el archivo
            auxC=auxC->siguiente;
        }
    salida.close();

    auxC=categoria;
    int i=0;
    int pos=0;
    ofstream salidaAux("categoriaConection.dat",ios::out|ios::trunc);
        while(auxC!=NULL){
            if(auxC->origen!=NULL){
                salidaAux.write(reinterpret_cast<char *>(&i),sizeof (int));
                pos=posLista(auxC->origen);
                salidaAux.write(reinterpret_cast<char *>(&pos),sizeof (int));
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
    int id=0;
    long long pos=0;
    ofstream salida("direccion.dat",ios::out|ios::trunc);
        while(auxD!=NULL){
            id=auxD->getId();
            pos=auxD->getPos();
            salida.write(reinterpret_cast<char *>(&id),sizeof (int));
            salida.write(reinterpret_cast<char *>(&pos),sizeof (long long));
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
    cout<<cantidadDireccion-1<<endl;
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



void Biblioteca::cargar()
{
    cargarDireccion();
    cargarListaInvertida();
    cargarCategoria();

}

void Biblioteca::cargarListaInvertida()
{
    int id;
    ifstream entrada("lista.dat",ios::in);
    if(!entrada.good()){
        entrada.close();
        return;
    }
        while(!entrada.eof()){
            entrada.read(reinterpret_cast<char *>(&id),sizeof (int));
            if(entrada.eof())
                break;
            insertarCarga(id);
        }
    entrada.close();
    int i=0;
    int pos;
    ifstream entradaAux("listaConection.dat",ios::in);


        while(!entradaAux.eof()){
            entradaAux.read(reinterpret_cast<char* >(&i),sizeof (int));
            entradaAux.read(reinterpret_cast<char *>(&pos),sizeof (int));

            if(entradaAux.eof())
                break;
            insertarConexionLista(i,pos);
        }
        entradaAux.close();
}

void Biblioteca::cargarCategoria()
{
    char nombre [TAMCHAR];
    ifstream entrada("categoria.dat",ios::in);
    if(!entrada.good()){
        entrada.close();
        return;
    }
        while(!entrada.eof()){
            entrada.read(reinterpret_cast<char *>(&nombre),TAMCHAR);
            if(entrada.eof())
                break;
            insertarCargaCategoria(nombre);
        }
    entrada.close();

    int i=0;
    int pos=0;
    ifstream salidaAux("categoriaConection.dat",ios::in);
        while(!salidaAux.eof()){
            salidaAux.read(reinterpret_cast<char *>(&i),sizeof (int));
            salidaAux.read(reinterpret_cast<char *>(&pos),sizeof (int));

            if(salidaAux.eof())
                break;
            insertarConexionCategoria(i,pos);
        }
        salidaAux.close();
}

void Biblioteca::cargarDireccion()
{
    int id;
    long long pos;
    ifstream entrada("direccion.dat",ios::in);
    if(!entrada.good()){
        entrada.close();
        return;
    }
        while(!entrada.eof()){
            entrada.read(reinterpret_cast<char *>(&id),sizeof (int));
            entrada.read(reinterpret_cast<char *>(&pos),sizeof (long long));
            if(entrada.eof())
                break;
            insertarCargarDireccion(id,pos);
        }
    entrada.close();
}


