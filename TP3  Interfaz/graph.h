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

    void add_vertex(Tipo& guy)
    {

        if(!exist_in_net(guy))
        {

            Pair<Tipo,friends> pr =typename graph::graph_data::value_type(guy, friends()); //AQUI ESTA EL ERROR
            data.insert(pr); // friends() es vacio, inserta a guy son amigos
        }

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

    wxString  print_friends(Tipo& guy)
    {
wxString s;

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
                    s<<"\n"<<c++<<". "<<friends_iter->first.get_nickname()<<"\n";// Imprime el nickname de friends_iter
                }

            }
            else
            {
                cout<<"\n"<<"No tiene Amigos "<<"\n";
            }

        }
        else
        {
            cout<<"No existe tal persona "<<"\n";
        }
        return s;
    }
    wxString  print_people_in_net()const
    {
        wxString s;

        typename        graph_data::iterator iter = data.begin();
        typename        graph_data::const_iterator fin = data.end();
        if(iter==fin)
        {
            s<<"No hay nadie en la red"<<"\n";
        }
        else
        {
            int c=1;

            for(iter; iter!=fin; ++iter)
            {
                s<<c++<<".  "<< iter->first.get_nickname()<<"\n";// (*iter).first.get_nickname()<<endl;

            }
        }
return s;
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





    wxString print_mutual_friends(Tipo& a, Tipo& b)
    {
wxString s;

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
                        s<<c++<<".  "<<friends_of_b->first.get_nickname()<<"\n";
                        found=true;
                        at_least_one = true;
                    }
                    c=1;
                }
            }
            if(at_least_one != true)
            {
                s<<"\n"<<"No tiene amigos en comun"<<"\n";
            }
        }
        else
        {
            s<<"\n"<<"Alguna persona no esta en la red"<<"\n";
        }
return s;
    }
    wxString consult(Tipo& guy)
    {
        wxString x;
        if(exist_in_net(guy) )
        {
            typename graph_data::iterator iter =data.find(guy);
            x = iter->first.print_info();
            x+"\n"+" Sus amigos son: "+"\n";
            person x1 =iter->first;
            x+=print_friends(x1);
        }
        else
        {
            x<<guy.get_nickname()<<" no existe en la red"<<"\n";
        }

return x;
    }
    void remove_vertex(Tipo& guy)
    {

        if(exist_in_net(guy))
        {
            data.erase(guy);
            typename            graph_data::iterator  iter = data.begin();
            typename            graph_data::iterator fin = data.end();

            for (iter; iter!=fin; ++iter)
            {
                iter->second.erase(guy);
            }
            cout<<" Vertice eliminado"<<endl;

        }
        else
        {
            cout<<"No existe tal  vertice en el grafo"<<endl;
        }

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
            cout<<"Al menos una persona no existe en la red, no se pudo borrar"<<endl;
        }

    }





    friend class social_network;
friend class Project1Frm;
public:
    typedef Tipo key_person; /**<Tipo de los vértices, cada vertice es una persona en la red, es un key_type */
    typedef List<  Tipo, int > friends; /**<Lista de adyacencias (amigos), este es el mapa interno*/
public:
    typedef List<key_person,friends> graph_data;/**< Mapa externo,  son las personas que estan en la red */
private:
    graph_data data;
};
#endif // GRAPH_H
