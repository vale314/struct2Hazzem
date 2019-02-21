#ifndef GRAFO_H
#define GRAFO_H
#include <list>

using namespace std;

template <class tn,class ta>
    class Grafo {
    public :
        typedef int apuntador ;
    private :
        class nodoArco {
            public :
            ta infoarco;// et i q u et a d e l arco , peso
            apuntador anodo ;// í n d i c e a l nodo adyacente
            nodoArco ( const ta & e , apuntador pos ) ;
        };// f i n c la se nodoArco
        class nodo {
        public :
        tn infonodo; // et i q u et a d e l nodo
        list <nodoArco> listarcos; // l i s t a de a rcos de ese nodo
        bool visitado ; // i n i c i a l m e n t e a f a l s o
        nodo ( const tn & elem=tn ( ) ) ;
        } ; // c la se nodo
        nodo * graf ; // v e ct o r dinámico de nodos
        int numnodos ; // número de nodos a ct u a l
        int capacidad ; // t a l l a d e l v e ct o r
        apuntador insert_nodo ( const nodo &n );
    public :
        struct arco {
            apuntador norigen , nfin;
            ta info;
        };
        Grafo(int n=256 );
        ~Grafo ( );
        Grafo ( const Grafo <tn , ta > & origen) ;
        Grafo <tn , ta > & operator = ( const Grafo <tn , ta > & origen) ;
        bool empty () const ;
        apuntador insert_elem (const tn & elem) ;
        void insert_arco(const arco & a);
        apuntador find_elem ( const tn & elem ) const ;
        const tn & data_nodo ( apuntador p ) const ;
        tn & data_nodo ( apuntador p ) ;
        const ta & data_arco ( apuntador ini , apuntador fin ) const ;
        ta & data_arco ( apuntador ini , apuntador fin ) ;
        void erase_nodo ( apuntador p ) ;
        void erase_arco ( const arco & a ) ;
        void DepthFirst ( apuntador p ) const ; // re c . en p rofundidad
        void BreadthFirst ( apuntador p ) const ; // re c . en anchura
};

    template < class tn , class ta >
    typename Grafo <tn , ta > :: apuntador
    Grafo <tn , ta > :: insert_nodo ( const nodo & n ){
        int pos ;
        if ( numnodos < capacidad ) {
            pos = numnodos ;
            graf [ numnodos ] = n ;
            numnodos++;
        }
        else
            pos = -1;
        return pos ;
    }

    template < class tn , class ta >
    void Grafo <tn , ta >::insert_arco(const arco & a ) {
        // Implementación para un g r af o no d i r i g i d o
        nodoArco ar1 ( a.info , a.nfin) ;
        graf[a.norigen ].listarcos.push_front(ar1) ;
        nodoArco ar2 ( a.info, a.norigen ) ;
        graf[a.nfin].listarcos.push_front(ar2);
    }

//    template < class tn , class ta >
//    void Grafo <tn , ta > ::BreadthFirst(apuntador p ) const {
//        queue<apuntador> cola ;
//        visitar(p) ;
//        cola.push(p) ;
//        mientras (! cola.empty () ) {
//            n = cola.front (); cola.pop () ;
//            para (todos los nodos m adyacentes a n )
//            si (no visitado(m) ) {
//                visitar(m) ;
//                cola.push (m) ;
//            }
//        }
//    }
#endif // GRAFO_H
