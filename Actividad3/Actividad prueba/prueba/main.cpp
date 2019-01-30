#include <iostream>
#include <string.h>
#include <iostream>
#include <ostream>
#include <fstream>

using namespace std;

struct persona{
    std::string nombre;
    std::string nacionalidad;
    std::string origen;
    int edad;

};

int change(char* nombreBits);

int cantidadDigitos(int num){
    int cantidad=0;

      while (num > 0) {
        num = num / 10;
        cantidad++ ;
      }

      return cantidad;
}

string agregarCeros(int num){
    int cantidad=cantidadDigitos(num);
    char c1='0';
    string newNumber=to_string(num);

    while(cantidad!=4){
        if(cantidad==4)
            break;
        newNumber=c1+newNumber;
        cantidad++;
    }
//    static char returnChar=*newNumber.c_str();
    return (newNumber);
}

string borrarBasura(char* nombre,int tam){
    int i=0;
    char c1='0';
    string newNumber="";

    while(i!=tam){
        newNumber=newNumber+nombre[i];
        i++;
    }
//    static char returnChar=*newNumber.c_str();
    return (newNumber);
}

//std::string s = "234567";
//int i = 1;
//char c1 = i + '0';
//s = c1 + s;
//std::cout << s << std::endl;
//system("pause");

int main(){
    persona persona1;
    persona1.nombre="Valentin Roberto";
    persona1.nacionalidad="Mexicano";
    persona1.origen="Guadalajara";
    persona1.edad=21;



    //const char *nombreC = persona1.nombre.c_str();
    size_t a = strlen(persona1.nombre.c_str());
    //const char *nacionalidadC = persona1.nacionalidad.c_str();
    size_t b = strlen(persona1.nacionalidad.c_str());
    size_t c = strlen(persona1.origen.c_str());




    std::ofstream escribir("archivo.txt",std::ios::app);

    escribir.write(agregarCeros(a).c_str(),sizeof (size_t));
    escribir.write((char*)persona1.nombre.c_str(),a);

    escribir.write(agregarCeros(b).c_str(),sizeof (size_t));
    escribir.write((char*)persona1.nacionalidad.c_str(),b);


    escribir.write(agregarCeros(c).c_str(),sizeof (size_t));
    escribir.write((char*)persona1.origen.c_str(),c);

    escribir.write(agregarCeros(persona1.edad).c_str(),sizeof(size_t));

    escribir.close();








    std::ifstream leer("archivo.txt",std::ios::in|ios::out);

    //char *nombreLeer;
    char *nombreBits=new char;
    char *nombrePersona=new char;

    char *nacionalidadBits=new char;
    char *nacionalidaPersona=new char;

    char *origenBits=new char;
    char *origenPersona=new char;

    char *edadBits=new char;
    char *edadPersona=new char;

    leer.read((char*)nombreBits,sizeof (size_t));
    leer.read((char*)nombrePersona,change(nombreBits));

    leer.read((char*)nacionalidadBits,sizeof(size_t));
    leer.read((char*)nacionalidaPersona,change(nacionalidadBits));

    leer.read((char*)origenBits,sizeof (size_t));
    leer.read((char*)origenPersona,change(origenBits));

//    leer.read((char*)edadBits,sizeof (size_t));
    leer.read((char*)edadPersona,sizeof (size_t));


    leer.close();

    //    string(char)

    cout<<"Nombre: " <<borrarBasura(nombrePersona,change(nombreBits))
        <<"Nacionalidad: "<<borrarBasura(nacionalidaPersona,change(nacionalidadBits))
        <<"Origen: "<<borrarBasura(origenPersona,change(origenBits))
        <<"Edad: "<<change(edadPersona)<<endl;
    return 0;
}

int appendDigit(int base, int append) {
   std::string sBase = std::to_string(base);
   std::string sAppend = std::to_string(append);
   std::string result = sBase + sAppend;
   return std::stoi(result);

}

int change(char* nombreBits){
    int number;

    number=appendDigit(nombreBits[0]-'0',nombreBits[1]-'0');
    number=appendDigit(number,nombreBits[2]-'0');
    number=appendDigit(number,nombreBits[3]-'0');

}







