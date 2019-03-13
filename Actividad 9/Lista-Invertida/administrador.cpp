#include "administrador.h"

Administrador::Administrador()
{
    contadorIndice=0;
    contadorGenero=0;
    contadorInvertida=0;

    leerGenero();
    leerIndice();
    leerInvertida();
}

Administrador::~Administrador()
{
    escribirGenero();
    escribirIndice();
    escribirInvertida();
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
        nuevoGenero(libro.getGenero(),contadorGenero-1);
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
        if(!strcmp(tdaGenero[i].getGenero(),nombreGenero))
            return tdaGenero[i].getPos();
    return -1;
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
    int i=contadorIndice-1;
    ofstream salida("indice.txt",ios::app|ios::binary);
    while(i>=0){
        salida.write(reinterpret_cast<char *>(&tdaIndice[i]),sizeof (TdaIndice));
        i--;
    }
    salida.close();
}

void Administrador::escribirGenero()
{
    int i=contadorGenero-1;
    ofstream salida("genero.txt",ios::app|ios::binary);
    while(i>=0){
        salida.write(reinterpret_cast<char *>(&tdaGenero[i]),sizeof (TdaGeneros));
        i--;
    }
    salida.close();
}

void Administrador::escribirInvertida()
{
    int i=contadorInvertida-1;
    ofstream salida("invertida.txt",ios::app|ios::binary);
    while(i>=0){
        salida.write(reinterpret_cast<char *>(&tdaInvertida[i]),sizeof (TdaListaInvertida));
        i--;
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

    TdaListaInvertida invertida;
    ifstream leer("invertida.txt",ios::in|ios::binary);
    if(!leer.good())
        return;
    while(!leer.good()){
        leer.read(reinterpret_cast<char*>(&invertida),sizeof (TdaListaInvertida));
        if(leer.eof())
            return;
        tdaInvertida[contadorInvertida]=invertida;
        contadorInvertida++;
    }
    leer.close();
}

