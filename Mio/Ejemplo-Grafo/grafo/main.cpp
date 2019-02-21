#include <iostream>
#include <cstdlib>         //librerias necesarias para que las instruccuiones sean reconocidas por el compilador
#include <conio.h>

using namespace std;

struct nodo     //estructura del vertice y arista
{
   int dato;      // cuando es un vertice guarda un dato pero si es una arista guara el peso
   struct nodo *liga_vertice;        //guardan las direcciones de los siguientes nodos o vertices y aristas
   struct nodo *liga_arista;
};


typedef struct nodo *registro;
registro sig_ver, ant_ver, cab_ver,sig_ari, ant_ari,dir1,dir2;   //apuntadores de memoria


registro nuevo_vertice(int dat)   //añade un nuevo vertice
{
     registro reg_ver = new(struct nodo);  //instruccion para pedir memoria con la estructura del vertice o nodo
     reg_ver->dato = dat;
     reg_ver->liga_vertice=NULL;
     reg_ver->liga_arista= NULL;
     return reg_ver;
}


void insertarVertice(int dat)    //funcion para insertar un nuevo vertice
{
 int sw;
 sw=0;
    ant_ver=cab_ver;
 sig_ver=cab_ver;
 while (sig_ver != NULL && sw==0)  //recorre el grafo verificando si el vertive existe, sino existe lo adiciona al final
 {        //si existe saca u mensaje de error
   if (sig_ver->dato==dat)
   {
       sw=1;
   }
   else
   {
       ant_ver=sig_ver;
       sig_ver=sig_ver->liga_vertice;
   }
 }
 if (sw==1)
 {
  cout << "\n Vertice ya existe no se adiciona\n";
 }
 else
 {
  if (cab_ver==NULL)
  {
   cab_ver=nuevo_vertice(dat); //El primer vertice queda como cabeza
  }
  else
  {
   ant_ver->liga_vertice=nuevo_vertice(dat); //se adiciona despues del ultimo vertice
  }
  cout << "Vertice adicionado \n";
 }
}


registro recorrer_vertice(int dat)
{
 registro dir;
 dir=NULL;
 sig_ver=cab_ver;
 while (sig_ver != NULL)  //recorre el grafo buscando uno en especial
 {
   if (sig_ver->dato==dat)
   {
       dir=sig_ver;
   }
   sig_ver=sig_ver->liga_vertice;
 }
 return dir;
}


registro nueva_arista(int pes)   //añade una nueva arista al vertice
{
     registro reg_ari = new(struct nodo);  //instruccion para pedir memoria con la estructura de las aristas
     reg_ari->dato = pes;
     reg_ari->liga_arista=NULL;
     reg_ari->liga_vertice=dir2;
     return reg_ari;
}


void insertarArista(int dato_destino)   //funcion para insertar una nueva arista
{
 int sw2,pes;
 sw2=0;
    ant_ari=dir1;
 sig_ari=dir1;
 while (sig_ari != NULL && sw2==0)  //recorre la sublista de aristas de ese vertice
 {
   if (sig_ari->dato==dato_destino)
   {
       sw2=1;
   }
   else
   {
       ant_ari=sig_ari;
       sig_ari=sig_ari->liga_arista;
   }
 }
 if (sw2==1)    //si la arista existe no se adiciona
 {
   cout<<"Arista ya existe no se adiciona \n\n ";
 }
 else
 {
  cout<< "Digite el peso de la arista: ";
  cin >> (pes);
  ant_ari->liga_arista=nueva_arista(pes);
 }
}


void verlista()
{
 cout<< "\n\n VER LISTA DE VERTICES Y SUS ARISTAS";
 sig_ver=cab_ver;
 while (sig_ver != NULL)   //busca los vertices
 {
  cout << "\n El nodo  ";
     cout<< (sig_ver->dato );
     cout << " Tiene las siguientes aristas  ";
     sig_ari=sig_ver->liga_arista; //pasa al siguiente vertice o nodo
     while (sig_ari != NULL)   //busca las aristas
  {
      cout << " ";
      dir1=sig_ari->liga_vertice;
      cout<< dir1->dato;
      sig_ari=sig_ari->liga_arista; //pasa a la siguiente arista
     }
     sig_ver=sig_ver->liga_vertice;
 }
}
//********************************************************************************************************************************
void eliminar()
{
 cout << "\n Prueba \n";
}

//**********************************************************************************************************************************




int main(){
    cab_ver = NULL;    //grafo vacio
     int dato_origen,dato_destino;
        int sw,opc=10;
        char Resp;

        while (opc != 5)
        {
         system("cls");
         cout << "\n GRAFO CON VERTICES (NODOS) Y LAS ARISTAS QUE LOS UNEN \n";
         cout << "\n 1. CREACION DE VERTICES";
         cout << "\n 2. Eliminar vertice (Solucion a primer punto)";
         cout << "\n 3. CREACION DE ARISTAS";
         cout << "\n 4. MOSTRAR GRAFO";
         cout << "\n 5. SALIR";
         cout << "\n SELECCIONE OPCION ENTRE 1 y 5 ";
         cin>>(opc);
         switch (opc)
         {
          case 1: Resp='s';
            while (Resp =='s')          //añade vertices hsta que diga que NO (n)
          {
           cout << "Digite dato para vertice (dato numerico): ";  //se pide cual es el vertice origen
             cin >> dato_origen;
             insertarVertice(dato_origen);   //se llama el metodo insertarVertice (para añadir un nuevo nodo o vertice)
                cout <<"\n Desea continuar insertando vertices s/n?: ";
                cin >>Resp;
            }
             break;
    //*******************************************************************************************************************************************
           case 2: Resp='s';
            while (Resp =='s')          //elimina vertices hsta que diga que NO (n)
          {
           cout << "Digite dato a eliminar para vertice (dato numerico): ";  //se pide cual es el vertice origen para eliminar
             cin >> dato_origen;
             insertarVertice(dato_origen);   //se llama el metodo insertarVertice (para añadir un nuevo nodo o vertice)
                cout <<"\n Desea continuar insertando vertices s/n?: ";
                cin >>Resp;
            }
             break;
    //*******************************************************************************************************************************************


           case 3: Resp='s';
            while (Resp =='s')          //añade aristas hsta que diga que NO (n)
         {
           cout << "Digite dato nodo origen (dato numerico): ";
             cin >> dato_origen;
             cout << "Digite dato nodo destino (dato numerico): ";
             cin >> dato_destino;
             dir1=recorrer_vertice(dato_origen);
             dir2=recorrer_vertice(dato_destino);
             if (dir1==NULL || dir2==NULL)
             {
               cout <<"\n Nodo origen o destino no existen revise";
             }
             else
             {
              insertarArista(dato_destino);   //se llama el metodo insertarVertice (para añadir un nuevo nodo o vertice)
             }
             cout <<"\n Desea continuar insertando vertices s/n?: ";
                cin >>Resp;
            }
             break;

             case 4: verlista();
            cout << endl << endl;
          system("pause"); //genera una pausa para ver los datos
             break;
         }
     }


    return 0;
}


