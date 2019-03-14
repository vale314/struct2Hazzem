#include "administrador.h"

Administrador::Administrador()
{
    contadorIndice=0;
    contadorGenero=0;
    contadorInvertida=0;

    leerGenero();
    leerInvertida();
    leerIndice();
}

Administrador::~Administrador()
{
    escribirGenero();
    escribirInvertida();
    escribirIndice();
}

void Administrador::agregarLibro(Libro libro)
{
    if(validarId(libro.getCodigo())){
        cout<<"Libro Existente"<<endl;
        return;
    }
    long long pos = escribirArchivo(libro);
    nuevoIndice(libro.getCodigo(),pos);
    if(validarGenero(libro.getGenero())){
        int posGenero =posicionGenero(libro.getGenero());
        int posInvertida = posicionInvertida(posGenero);
        nuevoDato(libro.getCodigo(),posInvertida);
    }else{
        nuevoDato(libro.getCodigo(),-1);
        nuevoGenero(libro.getGenero(),contadorInvertida-1);
    }

}

void Administrador::mostrar()
{
    Libro libro;
    for(int i=0;i<contadorIndice;i++){
        cout<<"Key: "<<tdaIndice[i].getKey()
            <<"Pos: "<<tdaIndice[i].getPos()<<endl;;
    }
    cout<<endl;
    ifstream leer("archivo.dat",ios::in|ios::binary);
    for(int i=0;i<contadorIndice;i++){
        leer.seekg(tdaIndice[i].getPos());
        leer.read(reinterpret_cast<char*>(&libro),sizeof (Libro));
        cout<<libro<<endl;
    }
    leer.close();
}

void Administrador::mostrarGenero()
{
    cout<<endl;
    for(int i=0;i<contadorGenero;i++)
        cout<<tdaGenero[i].getGenero()<<" "<<tdaGenero[i].getPos()<<endl;
}

void Administrador::mostarPosicion(long long direccion)
{
    Libro libro;
    ifstream leer("archivo.dat",ios::in|ios::binary);
        leer.seekg(direccion);
        leer.read(reinterpret_cast<char*>(&libro),sizeof (Libro));
        cout<<libro<<endl;
        leer.close();
}

void Administrador::keyToPos(int key)
{
    //regresar La Posicion y llamar mostrarPosicion
    for(int i=0;i<contadorIndice;i++){
        if(tdaIndice[i].getKey()==key)
            return mostarPosicion(tdaIndice[i].getPos());
    }
}

void Administrador::mostrarPorGenero(char genero[TAMCHAR])
{
    int pos=0;
    for(int i=0;i<contadorGenero;i++){
        pos=-2;
        if(!strcmp(tdaGenero[i].getGenero(),genero)){
            pos=tdaGenero[i].getPos();
            break;
        }
    }
    if(pos==-2){
        cout<<"No Se encontro el genero"<<endl;
        return;
    }

    bool imprimir=false;
    do{
        imprimir=true;
        if(tdaInvertida[pos].getPos()==-1)
            imprimir=false;
        keyToPos(tdaInvertida[pos].getKey());
        pos=tdaInvertida[pos].getPos();
    }while(imprimir);
    return;
}

void Administrador::modificar(int id,Libro libro)
{
    if(!validarId(id)){
        cout<<"Id No Valido"<<endl;
        return;
    }

    if(!validarGenero(libro.getGenero())){
        actualizarGeneroInvertida(posicionInvertidaArray(libro.getCodigo()));
        nuevoGenero(libro.getGenero(),posicionInvertidaArray(libro.getCodigo()));

        int pos=posicionInvertidaArray(libro.getCodigo());
        tdaInvertida[pos].setPos(-1);
    }else{
        actualizarGeneroInvertida(posicionInvertidaArray(libro.getCodigo()));
        int pos=posicionGenero(libro.getGenero());
        pos=posicionInvertida(pos);
        tdaInvertida[pos].setPos(posicionInvertidaArray(libro.getCodigo()));
    }

    for(int i=0;i<contadorIndice;i++){
        if(tdaIndice[i].getKey()==id)
            return sobrescribir(tdaIndice[i].getPos(),libro);
    }
}

void Administrador::sobrescribir(long long pos,Libro libro)
{
    fstream salida("archivo.dat",ios::in|ios::out|ios::binary);
        salida.clear();
        salida.seekp(pos);
        cout<<salida.tellp()<<endl;
        salida.write(reinterpret_cast<char *>(&libro),sizeof (Libro));
    salida.close();
}

void Administrador::mostrarListaInvertida()
{
    for(int i=0;i<contadorInvertida;i++){
        cout<<"key: "<<tdaInvertida[i].getKey()<<"  "<<"Siguiente: "<<tdaInvertida[i].getPos()<<endl;
    }
}

bool Administrador::validarId(int id)
{
    for(int i=0;i<contadorIndice;i++)
        if(tdaIndice[i].getKey()==id)
            return true;
    return false;
}

long long Administrador::posicionId(int id)
{
    for(int i=0;i<contadorIndice;i++)
        if(tdaIndice[i].getKey()==id)
            return tdaIndice[i].getPos();
    return -1;
}

void Administrador::nuevoIndice(int key,long long pos)
{
    TdaIndice indice;
    indice.setKey(key);
    indice.setPos(pos);
    tdaIndice[contadorIndice]=indice;
    contadorIndice++;
}

void Administrador::reset()
{
    contadorIndice=0;
}

bool Administrador::validarGenero(char nombreGenero[TAMCHAR])
{
    for(int i=0;i<contadorGenero;i++)
        if(!strcmp(tdaGenero[i].getGenero(),nombreGenero))
            return true;
    return false;
}

int Administrador::posicionGenero(int pos)
{
    for(int i=0;i<contadorGenero;i++)
        if(tdaGenero[i].getPos()==pos)
            return i;
    return -1;
}

int Administrador::posicionGenero(char nombreGenero[TAMCHAR])
{
    for(int i=0;i<contadorGenero;i++)
        if(!strcmp(tdaGenero[i].getGenero(),nombreGenero)){
            cout<<"Posicion: "<<tdaGenero[i].getPos()<<endl;
            return tdaGenero[i].getPos();
        }
    return -2;
}

void Administrador::nuevoGenero(char nuevo_genero[TAMCHAR],int pos)
{
    TdaGeneros genero;
    genero.setGenero(nuevo_genero);
    genero.setPos(pos);
    tdaGenero[contadorGenero]=genero;
    contadorGenero++;
}

void Administrador::eliminar(int id)
{
    int pos;
    pos=posicionInvertidaArray(id);
    eliminarFisico(pos);
    desasociarGeneroInvertida(pos);
}

void Administrador::desasociarGeneroInvertida(int pos)
{
    //buscar el genero es el header
    for(int i=0;i<contadorGenero;i++){
        if(tdaGenero[i].getPos()==pos){
            if(tdaInvertida[pos].getPos()==-1){
                quitarDeLaListaGenero(i);
            }
            else
                tdaGenero[i].setPos(tdaInvertida[pos].getPos());

            reposisionar(pos);
            quitarDeLaLista(pos);
            return;
        }
    }
    for(int i=0;i<contadorInvertida;i++){
        if(tdaInvertida[i].getPos()==pos){
            tdaInvertida[i].setPos(tdaInvertida[pos].getPos());
            reposisionar(pos);
            quitarDeLaLista(pos);
            return;
        }
    }
}

void Administrador::actualizarGeneroInvertida(int pos)
{
    for(int i=0;i<contadorGenero;i++){
        if(tdaGenero[i].getPos()==pos){
            if(tdaInvertida[pos].getPos()==-1){
                quitarDeLaListaGenero(i);
            }
            else
                tdaGenero[i].setPos(tdaInvertida[pos].getPos());

            return;
        }
    }
}

void Administrador::quitarDeLaListaGenero(int pos)
{
    cout<<"Quitar Lista Genero"<<endl;
    for(int i=pos;i<contadorGenero-1;i++){
        tdaGenero[i]=tdaGenero[i+1];
    }
    contadorGenero--;
}

void Administrador::quitarDeLaLista(int pos)
{
    for(int i=pos;i<contadorInvertida-1;i++){
        tdaInvertida[i]=tdaInvertida[i+1];
    }
    contadorInvertida--;
}

void Administrador::reposisionar(int pos)
{
    for(int i=pos;i<contadorInvertida;i++){
        if((tdaInvertida[i].getPos()>pos)&&(tdaInvertida[i].getPos()!=-1))
            tdaInvertida[i].setPos(tdaInvertida[i].getPos()-1);
    }
}

int Administrador::posicionInvertida(int pos)
{
    int i=pos;
    while(tdaInvertida[i].getPos()!=-1)
        i=tdaInvertida[i].getPos();
    return i;
}

int Administrador::posicionInvertidaArray(int key)
{
    for(int i=0;i<contadorIndice;i++)
        if(tdaInvertida[i].getKey()==key)
            return i;
    return -1;
}

void Administrador::nuevoDato(int key , int pos)
{
    TdaListaInvertida invertida;
    invertida.setKey(key);
    invertida.setPos(-1);
    tdaInvertida[contadorInvertida]=invertida;
    if(pos!=-1)
        tdaInvertida[pos].setPos(contadorInvertida);
    contadorInvertida++;

}

void Administrador::eliminarFisico(int pos)
{

    pos++;
    Libro libro;
    ofstream nuevo;
    long long posicion;
    nuevo.open("newA.dat",ios::out|ios::app|ios::binary);
    cout<<"pos: "<<pos<<endl;
    posicion=pos*sizeof (Libro);
    cout<<posicion<<endl;
    ifstream leer("archivo.dat",ios::in|ios::binary);
    for(int i=0;i<contadorIndice;i++){
        leer.seekg(tdaIndice[i].getPos());
        leer.read(reinterpret_cast<char*>(&libro),sizeof (Libro));
        if(leer.tellg()!=posicion)
            nuevo.write(reinterpret_cast<char *>(&libro),sizeof (Libro));
    }
    leer.close();
    nuevo.close();
    remove("archivo.dat");
    rename("newA.dat","archivo.dat");
    remove("newA.dat");
    reposicionarPunturos();


}

void Administrador::reposicionarPunturos()
{
    reset();
    long long posicion;
    Libro libro;
    TdaIndice indice;
    int i;
    ifstream entrada;
    i=0;

    entrada.open("archivo.dat",ios::in|ios::binary);
    entrada.clear();
    entrada.seekg(0);
    while (!entrada.eof()) {
        posicion=entrada.tellg();

        entrada.read(reinterpret_cast<char *>(&libro),sizeof (Libro));
        if(entrada.eof())
            break;
        cout<<libro<<endl;
        indice.setKey(libro.getCodigo());
        indice.setPos(posicion);
        tdaIndice[i]=indice;
        contadorIndice++;
        i++;
    }
    entrada.close();
    system("pause");
}

long long Administrador::escribirArchivo(Libro libro)
{
    fstream salida;
    salida.open("archivo.dat",ios::out|ios::app|ios::binary);
    long long pos=0;
    salida.clear();
    salida.seekp(contadorIndice*sizeof (Libro));
    pos=salida.tellp();
    salida.write(reinterpret_cast<char *>(&libro),sizeof (Libro));
    salida.close();
    return pos;
}

void Administrador::escribirIndice()
{
    int i=0;
    ofstream salida("indice.txt",ios::trunc|ios::binary);
    while(i<contadorIndice){
        salida.write(reinterpret_cast<char *>(&tdaIndice[i]),sizeof (TdaIndice));
        i++;
    }
    salida.close();
}

void Administrador::escribirGenero()
{
    int i=0;
    ofstream salida("genero.txt",ios::trunc|ios::binary);
    while(i<contadorGenero){
        salida.write(reinterpret_cast<char *>(&tdaGenero[i]),sizeof (TdaGeneros));
        i++;
    }
    salida.close();
}

void Administrador::escribirInvertida()
{
    int i=0;
    ofstream salida("invertida.txt",ios::trunc|ios::binary);
    while(i<contadorInvertida){
        salida.write(reinterpret_cast<const char *>(&tdaInvertida[i]),sizeof (TdaListaInvertida));
        i++;
    }
    salida.close();
}

void Administrador::leerIndice()
{
    TdaIndice indice;
    ifstream leer("indice.txt",ios::in|ios::binary);
    if(!leer.good())
        return;
    while(!leer.eof()){
        leer.read(reinterpret_cast<char*>(&indice),sizeof (TdaIndice));
        if(leer.eof())
            return;
        tdaIndice[contadorIndice]=indice;
        contadorIndice++;
    }
    leer.close();
}

void Administrador::leerGenero()
{

    TdaGeneros generos;
    ifstream leer("genero.txt",ios::in|ios::binary);
    if(!leer.good())
        return;
    while(!leer.eof()){
        leer.read(reinterpret_cast<char*>(&generos),sizeof (TdaGeneros));
        if(leer.eof())
            return;
        tdaGenero[contadorGenero]=generos;
        contadorGenero++;
    }
    leer.close();
}

void Administrador::leerInvertida()
{
    contadorInvertida=0;
    TdaListaInvertida invertida;
    ifstream leer2("invertida.txt",ios::in|ios::binary);
    if(!leer2.good()){
        return;
    }
    while(!leer2.eof()){
        leer2.read(reinterpret_cast<char*>(&invertida),sizeof (TdaListaInvertida));
        if(leer2.eof())
            return;
        tdaInvertida[contadorInvertida]=invertida;
        contadorInvertida++;
    }
    leer2.close();
}

