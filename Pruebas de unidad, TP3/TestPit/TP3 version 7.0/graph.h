#ifndef GRAPH_H
#define GRAPH_H
#include "person.h"
#include <fstream>
#include <ostream>
#include <string>
#include "mapa.h"
#include <iostream>
#include <iterator>

template <typename Tipo>
class graph
{
public:
    graph()
    {

    }

    ~graph()
    {
        this->wipe_out();
    }

    bool is_empty_() const
    {
        return data.empty();
    }


    bool exist_in_net(Tipo& guy) const
    {

        bool found  =false;
        typename graph_data::const_iterator iter= data.find(guy);
        if(iter != data.end())
        {
            found=true;
        }
        return found;

    }


    void wipe_out()
    {
        data.clear();


    }

    bool  add_vertex(Tipo& guy)
    {
        bool c =false;
        if(!exist_in_net(guy))
        {

            Pair<Tipo,friends> pr =typename graph::graph_data::value_type(guy, friends()); //AQUI ESTA EL ERROR
            data.insert(pr); // friends() es vacio, inserta a guy son amigos
            c=true;
        }
        return c;
    }


    void add_adjacency (Tipo& src, Tipo& dst)
    {


        if(exist_in_net(src) && exist_in_net(dst) )
        {

            if(!are_related(src,dst))
            {
                typename graph_data::iterator iter_src =data.find(src);
                Pair<Tipo,int> ds = typename graph<Tipo>::friends::value_type(dst,1);
                iter_src->second.insert(ds);


                typename  graph_data::iterator iter_dst =data.find(dst);
                Pair<Tipo,int> sr = typename graph<Tipo>::friends::value_type(src,1);
                iter_dst->second.insert(sr);
            }


        }
        else
        {
            cout<<"No  ha creado la relacion"<<endl;

        }

    }

    bool are_related(Tipo& src, Tipo& dst)
    {

        bool are = false;
        typename graph_data::const_iterator src_iter =data.find(src);//puntero a src en el map externo.

        if(src_iter != data.end()) //si existe src en map principal
        {
            if(src_iter->second.find(dst) !=  src_iter->second.end()   ) //si existe dst en la lista de amigos de src
            {
                are=true;
            }
        }
        return are;

    }

    void print_friends(Tipo& guy)
    {


        if(exist_in_net(guy))
        {
            typename    graph_data::const_iterator guy_iter =data.find(guy);//puntero a guy en map externo
            typename    friends::iterator friends_iter = guy_iter->second.begin();//Inicio del map interno
            typename    friends::const_iterator fin = guy_iter->second.end();//Final del map interno
            int c =1;
            if(friends_iter!=fin)
            {
                for(friends_iter; friends_iter!=fin; ++friends_iter) //Recorre  mapa interno( mapa de amigos)
                {
                    cout<<endl<<c++<<". "<<friends_iter->first.get_nickname()<<endl;// Imprime el nickname de friends_iter
                }

            }
            else
            {
                cout<<endl<<"No tiene Amigos "<<endl;
            }

        }
        else
        {
            cout<<"No existe tal persona "<<endl;
        }
    }
    void print_people_in_net()const
    {

        typename        graph_data::iterator iter = data.begin();
        typename        graph_data::const_iterator fin = data.end();
        if(iter==fin)
        {
            cout<<"No hay nadie en la red"<<endl;
        }
        else
        {
            int c=1;

            for(iter; iter!=fin; ++iter)
            {
                cout<<c++<<".  "<< iter->first.get_nickname()<<endl;// (*iter).first.get_nickname()<<endl;

            }
        }

    }

    void print_vertex_list()const
    {

        typename  graph_data::iterator iter = data.begin();
        typename  graph_data::const_iterator fin = data.end();
        if(iter==fin)
        {
            cout<<"No hay vertices en el grafo"<<endl;
        }
        else
        {
            int c=1;

            for(iter; iter!=fin; ++iter)
            {
                cout<<c++<<".  "<< iter->first<<endl;// (*iter).first.get_nickname()<<endl;

            }
        }

    }





    void print_mutual_friends(Tipo& a, Tipo& b)
    {


        if(exist_in_net(a),exist_in_net(b))
        {
            int c =1;
            typename            graph_data::const_iterator iter_a = data.find(a);
            typename            friends::iterator friends_of_a = iter_a ->second.begin();
            typename            friends::const_iterator fin = iter_a ->second.end();
            bool at_least_one = false;
            for(friends_of_a; friends_of_a!=fin; ++friends_of_a)//iterar en amigos de a
            {
                typename                graph_data::const_iterator iter_b= data.find(b);
                typename                friends::iterator friends_of_b=iter_b->second.begin();
                typename                friends::const_iterator fin2=iter_b->second.end();

                bool found =false;
                for(friends_of_b; friends_of_b!=fin2 && found == false; ++friends_of_b)
                {
                    if(friends_of_a->first == friends_of_b->first)
                    {
                        cout<<c++<<".  "<<friends_of_b->first.get_nickname()<<endl;
                        found=true;
                        at_least_one = true;
                    }
                    c=1;
                }
            }
            if(at_least_one != true)
            {
                cout<<endl<<"No tiene amigos en comun"<<endl;
            }
        }
        else
        {
            cout<<endl<<"Alguna persona no esta en la red"<<endl;
        }

    }
    void consult(Tipo& guy)
    {
        if(exist_in_net(guy) )
        {
            typename            graph_data::iterator iter =data.find(guy);
            iter->first.print_info(cout);
            cout<<endl<<" Sus amigos son: "<<endl;
            person x =iter->first;
            print_friends(x);
        }
        else
        {
            cout<<guy.get_nickname()<<" no existe en la red"<<endl;
        }


    }
    bool remove_vertex(Tipo& guy)
    {
        bool c=false;
        if(exist_in_net(guy))
        {
            data.erase(guy);
            typename            graph_data::iterator  iter = data.begin();
            typename            graph_data::iterator fin = data.end();

            for (iter; iter!=fin; ++iter)
            {
                iter->second.erase(guy);
            }
            c=true;
        }

 return c;
    }


    void remove_adjacency(Tipo& src, Tipo& dst)
    {
        if(exist_in_net(src)&& exist_in_net(dst))
        {
            typename            graph_data::iterator iter =data.find(src);
            iter->second.erase(dst);
            typename            graph_data::iterator iter2 =data.find(dst);
            iter2->second.erase(src);
        }
        else
        {
            cout<<"Al menos un vertice  no existe en la red, no se pudo borrar"<<endl;
        }

    }





    friend class social_network;

public:
    typedef Tipo key_person; /**<Tipo de los vértices, cada vertice es una persona en la red, es un key_type */
    typedef List<  Tipo, int > friends; /**<Lista de adyacencias (amigos), este es el mapa interno*/
public:
    typedef List<key_person,friends> graph_data;/**< Mapa externo,  son las personas que estan en la red */
private:
    graph_data data;
};
#endif // GRAPH_H
