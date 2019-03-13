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
        cout<<tdaInvertida[pos].getKey()<<endl;
        pos=tdaInvertida[pos].getPos();
    }while(imprimir);
    return;
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

bool Administrador::validarGenero(char nombreGenero[TAMCHAR])
{
    for(int i=0;i<contadorGenero;i++)
        if(!strcmp(tdaGenero[i].getGenero(),nombreGenero))
            return true;
    return false;
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

int Administrador::posicionInvertida(int pos)
{
    int i=pos;
    while(tdaInvertida[i].getPos()!=-1)
        i=tdaInvertida[i].getPos();
    return i;
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

long long Administrador::escribirArchivo(Libro libro)
{
    fstream salida;
    salida.open("archivo.dat",ios::out|ios::app|ios::binary);
    system("pause");
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
    ofstream salida("indice.txt",ios::app|ios::binary);
    while(i<contadorIndice){
        salida.write(reinterpret_cast<char *>(&tdaIndice[i]),sizeof (TdaIndice));
        i++;
    }
    salida.close();
}

void Administrador::escribirGenero()
{
    int i=0;
    ofstream salida("genero.txt",ios::app|ios::binary);
    while(i<contadorGenero){
        salida.write(reinterpret_cast<char *>(&tdaGenero[i]),sizeof (TdaGeneros));
        i++;
    }
    salida.close();
}

void Administrador::escribirInvertida()
{
    int i=0;
    ofstream salida("invertida.txt",ios::app|ios::binary);
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

