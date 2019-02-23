#include <iostream>
#include <ldl.h>
#include <menu.h>

using namespace std;

//void ldl(){
//    LDL<int> x;


//    x.push_front(5);
//    x.push_front(10);
//    cout<<"Size: "<<x.size()<<endl;
//    size_t tam=x.size();
//    for(size_t i=0;i<tam;i++){
//        cout<<"Front: "<<x.front()<<endl;
//        x.pop_front();
//    }
//    cout<<"Size: "<<x.size()<<endl<<endl;

//    /*____________________________________*/
//    for(int i=0;i<10;i++){
//        x.push_back(i);
//        cout<<i<<endl;
//    }

//    cout<<"Size: "<<x.size()<<endl<<endl;

//    tam=x.size();
//    for(size_t i=0;i<tam;i++){
//        cout<<"Front: "<<x.back()<<endl;
//        cout<<"Size: "<<x.size()<<endl<<endl;
//        x.pop_back();
//    }

//    /*________________________*/

//    cout<<"Empty: "<<x.empty()<<endl;
//    x.push_front(5);

//    cout<<"Empty: "<<x.empty()<<endl;

//    x.clear();
//    cout<<"Size: :"<<x.size()<<endl<<endl;

//    /*________________________*/

//    for(int i=0;i<10;i++)
//        x.push_back(i);

//    tam=x.size();
//    for(size_t i=0;i<tam;i++)
//        cout<<x[i]<<endl;

//    cout<<"\n\n\n";
//    x.insert(5-1,50);

//    tam=x.size();
//    for(size_t i=0;i<tam;i++)
//        cout<<x[i]<<endl;
//    cout<<"\n\n\n";

//    x.erease(4);


//    tam=x.size();
//    for(size_t i=0;i<tam;i++)
//        cout<<x[i]<<endl;


//    cout<<"\n\n\n Y\n";
//    LDL<int> Y(x);

//    tam=Y.size();
//    for(size_t i=0;i<tam;i++)
//        cout<<Y[i]<<endl;
//    cout<<"\n\n\n";


//    x.clear();

//    tam=x.size();
//    for(size_t i=0;i<tam;i++)
//        cout<<x[i]<<endl;
//}


int main()
{
    Menu menu;
    menu.menu();

    return 0;
}

