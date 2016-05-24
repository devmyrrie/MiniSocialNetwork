#ifndef MAPA_h
#define MAPA_h
#include <iostream>
#include "pair.h"

using namespace std;

template<typename KEY,typename VALUE>
class Node
{
private:
    Node<KEY,VALUE>* n;//Nodo siguiente
public:
    Pair <KEY,VALUE>  my_value_type;

public:
    Node<KEY,VALUE>() //Constructor de la clase node.
    {
        n=NULL;

    }

    ~Node<KEY,VALUE>()
    {
    }

    void next(Node<KEY,VALUE>* node)/**< Inicializa el siguiente nodo */
    {
        this->n = node;
    }
    void element( Pair <KEY,VALUE>&  element)
    {

        this->my_value_type.first = element.first;
        this->my_value_type.second = element.second;

    }

    Node<KEY,VALUE>* next() const
    {
        return n;
    }
};


template<typename KEY, typename VALUE>
class List
{
public:
    Node<KEY,VALUE> *frs; //Nodo primero de la Lista.
    typedef Pair<KEY,VALUE> value_type ;/**< creamos el nombre value_type para referirnos a un Pair*/

public:

    List<KEY,VALUE>(): frs(NULL)//Constructor de la clase Lista vacio
    {
    }

    ~List<KEY,VALUE>()//destructor de la clase Lista vacio
    {
        Node<KEY,VALUE>* aux;
        while(frs != NULL)
        {
            aux= frs;
            frs=frs->next();
            delete aux;
            aux=NULL;

        }

    }

    void clear()
    {
        this->~List<KEY,VALUE>();/**< Para limpiar todo la Lista, llamamos al destructor */

    }

    List<KEY,VALUE>(Pair<KEY,VALUE>& x)
    {
        frs= new Node<KEY,VALUE>;
        frs->element(x);
    }
    /**
    *   EFE: Verificar si la Lista  esta vacia o no
    *   REQ: N/A
    *   MOD: N/A
    */
    bool empty() const
    {
        return  (this->frs == NULL)? true:false;
    }


    class iterator
    {
    public:
        Node<KEY,VALUE>* p;
        /**
        *   EFE:Constructor de la clase iterator
        *   REQ: Una instancia de  List<KEY,VALUE>
        *   MOD: Modifica el puntero p, que es un iterador.
        */

        iterator(const List<KEY,VALUE>& tl) : p(tl.frs) {} //cargamos a p con el frs de la lista entrante

        /**
        *   EFE:Segundo constructor de la clase iterator
        *   REQ: Un puntero a un nodo
        *   MOD: Modifica el puntero p, que es un iterador.
        */
        iterator( Node<KEY,VALUE>* tl): p(tl) {}

        /**
        *   EFE: Copia entre dos iteradores
        *   REQ: Una instancia de la clase iterator
        *   MOD: Modifica el puntero p, que es un iterador.
        */
        iterator(const iterator& tl)  //copia entre dos iteradores
        {
            p=tl.p;
        }
        /**
        *   EFE: Inicializa a p como null
        *   REQ: N/A
        *   MOD: Puntero p
        */
        iterator() // Inizializa p como null
        {
            p= NULL;
        }
        /**
        *   EFE: Sobrecarga el operador ++, para asi incrementar el iterador
        *   REQ: N/A
        *   MOD: Puntero p
        */
        bool operator++()
        {
            if(p->next() != NULL)
                p = p->next();
            else
                p = NULL;   // Indicates end of list
            return bool(p);
        }
        /**
        *   EFE: Sobrecarga el operador ++, para asi incrementar el iterador
        *   REQ: N/A
        *   MOD: Puntero p
        */

        /**
               *   EFE: Sobrecarga el operador !=, para ver cuando es diferente de NULL
               *   REQ: N/A
               *   MOD:  N/A
               */
        bool operator!=(const iterator&) const
        {
            return p != 0;
        }
        /**
              *   EFE: Sobrecarga el operador ==, para ver cuando es igual  a NULL
              *   REQ: N/A
              *   MOD:  N/A
              */
        bool operator==(const iterator& tl) const
        {
            return p == 0; //y si quiero comparar dos iteradors que no sea null
        }


        /**
        *   EFE: Retorna a lo que apunta  el iterador
        *   REQ: N/A
        *   MOD:  N/A
        */
        Pair<KEY,VALUE> current() const
        {
            if(p == NULL)
            {
                return Pair<KEY,VALUE>();
            }
            else
            {
                return this->p->my_value_type;
            }
        }

        Pair<KEY,VALUE>* operator->() const
        {
            return &(p->my_value_type);
        }

        Pair<KEY,VALUE> operator*() const
        {
            return current();
        }
    };
    typedef const iterator const_iterator;


    iterator begin() const
    {
        return iterator(*this); //manda a la lista en si
    }
    iterator end() const
    {
        return iterator();
    }


    /**
           *   EFE: Retorna una instancia de iterator, que apunta al "e" que buscamos
           *   REQ: N/A
           *   MOD:  N/A
           */
    iterator find(KEY& e) const
    {

        Node<KEY,VALUE>* iter = frs;
        bool found =false;
        while(!found && iter!=NULL)
        {
            if(iter->my_value_type.first == e)
            {
                iterator it( iter);
                return it;
            }
            iter=iter->next();

        }
        if(found == false)
        {
            return NULL;
        }

    }


    /**
    *   EFE: Insertamos "e" a la lista, lo insertamos ordenadamente
    *   REQ: Objeto "e" que es de la clase Pair
    *   MOD:  La lista
    */    void insert(Pair<KEY,VALUE>&  e) //Element debe ser pair
    {
        Node<KEY,VALUE>* celda = new Node<KEY,VALUE> ; //Crea una celda donde estara mi //nuevo numero por agregar.

        celda->element(e);

        if(frs == NULL)  //Lista vacia
        {
            frs=celda;
        }
        else  //Lista no vacia
        {

            if(exist(e.first)==false) // Mete si no existe
            {

                if(frs->my_value_type.first > e.first  )//Como comparar  entre dos data_typrs
                {
                    celda->next(frs);
                    frs=celda;

                }
                else
                {
                    Node<KEY,VALUE>* iterador = frs;
                    while( (iterador -> next() != NULL) && (iterador -> next() -> my_value_type.first < e.first))
                    {
                        iterador = iterador ->next();
                    }
                    celda -> next(iterador ->next()) ;
                    iterador -> next(celda);
                }

            }



        }
    }


  /**
      *   EFE: Verifica a  "key"  en el mapa
      *   REQ: N/A
      *   MOD:  La lista
      */
    bool exist(KEY& key)
    {
        bool ex = false;
        Node<KEY,VALUE>* iterador = frs;
        while(iterador != NULL && !ex)
        {
            if(iterador->my_value_type.first == key)
            {
                ex = true;

            }
            iterador = iterador->next();

        }
        return ex;

    }


    /**
      *   EFE: Borramos a  "key"  de  la lista
      *   REQ: N/A
      *   MOD:  La lista
      */
    void erase(KEY& key)
    {
        Node<KEY,VALUE>* anterior = NULL;
        Node<KEY,VALUE>* iterador = frs;
        if(frs != NULL && frs->my_value_type.first== key)
        {
            frs=frs->next();
            delete iterador;
            iterador=NULL;
        }
        else
        {
            while(iterador != NULL && iterador->my_value_type.first !=key)
            {
                anterior=iterador;
                iterador=iterador->next();
            }
            if(iterador != NULL)
            {
                anterior->next(iterador->next());
                delete iterador;
            }

        }
    }


};

#endif // List_h
