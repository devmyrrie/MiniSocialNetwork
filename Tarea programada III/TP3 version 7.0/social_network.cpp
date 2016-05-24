#include "social_network.h"
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

social_network::social_network()
{
}
social_network::~social_network()
{
    m_social_graph.wipe_out();
}


/**
*   EFE:Crea objeto tipo person.
*   REQ:N/A.
*   MOD:N/A.
*/
void social_network::create_person(person& x)
{
    cout<<"\nIngrese los siguientes datos de la persona por crear:" <<endl;

    string fullname="";
    cout<<"Nombre: ";
    getline(cin,fullname);
    x.set_fullname(fullname);


    string nick="";
    cout<<"Nickname: ";
    getline(cin,nick);
    x.set_nickname(nick);

    int age=0;
    string age_string="";
    cout<<"Edad: ";
    getline(cin,age_string);
    stringstream myStream(age_string);
    myStream>>age;
    x.set_age(age);

    bool sex=true;
    char sex2='f';
    string sex_string="";
    cout<<"Sexo: (m para masculino, f para femenino) "<<endl;
    getline(cin,sex_string);
    sex2=sex_string[0];
    if(sex2 == 'M' || sex2 == 'm')
    {
        sex=false;

    }
    x.set_sex(sex);

    string hobbies[10];;
    cout<<"Ingrese 10 pasatiempos suyos"<<endl;
    for(int i=0; i<10; ++i)
    {
        cout<<i+1<<". ";
        getline(cin,hobbies[i]);
    }
    x.set_hobbies(hobbies);
}

/**
*   EFE: Pregunta por la opcion a escoger.
*   REQ: Un entero, para ver cual menu desplegar.
*   MOD: N/A.
*/
int social_network::ask_option(int x)
{

    if(x==1)
    {
        cout<< "\nEscriba su opci\xa2n" << endl
            << "1.  Cargar base de datos" << endl
            << "2.  Agregar persona" << endl
            << "3.  Eliminar persona" << endl
            << "4.  Agregar relaci\xa2n" << endl
            << "5.  Eliminar relaci\xa2n" << endl
            << "6.  Consultas" << endl
            << "7.  Guardar base de datos" << endl
            << "8.  Fin del programa\n";

    }
    else
    {
        cout<<"\n\n"
            << "\n\xa8Que desea consultar?" << endl
            << "1.  Ver los amigos de una persona" << endl
            << "2.  Ver existencia de una persona en la red" << endl
            << "3.  Ver amigos en com\xa3n de dos personas" << endl
            << "4.  Ver si dos personas son amigos" << endl
            << "5.  Ver las personas de la red" << endl
            << "6.  Ver informaci\xa2n de una persona"<<endl
            << "7.  Regresar" << endl;

    }

    int option =-1;
    string option_string="";
    cout<<"\n\nIngrese su opci\xa2n: ";
    getline(cin,option_string);
    stringstream s(option_string);
    s>>option;

    return option;

}

/**
*   EFE:Muestra el primer menu.
*   REQ:N/A.
*   MOD:N/A.
*/
void social_network::show_first_menu()
{

    int option =0;
    while( ( option=ask_option(1) )!= 8 )
    {
        switch (option)
        {
        case 1:
        {
            m_social_graph.wipe_out();
            ifstream data_base_in("data_base.dat",  ios::in);
            load_people(data_base_in);
            data_base_in.seekg(0, ios::beg);
            load_friends(data_base_in);
            break;
        }

        case 2:
        {
            person human;
            create_person(human);
            (m_social_graph.add_vertex(human));

            break;
        }
        case 3:
        {
            string nick = "";
            cout<<"\nIngrese el nick de la persona que quiere eliminar de la red: ";
            getline(cin,nick);
            person human;
            human.set_nickname(nick);
            m_social_graph.remove_vertex(human);
            break;

        }

        case 4:
        {

            cout<<"\nIngrese los nicknames de las personas que quiere que sean amigos"<<endl;
            string str1= "";
            string str2= "";
            cout<<"a. ";
            getline(cin,str1);
            cout<<"\nb. ";
            getline(cin,str2);
            person x;
            x.set_nickname(str1);
            person y;
            y.set_nickname(str2);
            m_social_graph.add_adjacency(x,y);
            break;
        }


        case 5:
        {
            cout<<"\nIngrese los nicknames de las personas a las cuales quiere eliminar amistad"<<endl;
            string str1= "";
            string str2= "";
            cout<<"a. ";
            getline(cin,str1);
            cout<<"\nb. ";
            getline(cin,str2);
            person x;
            x.set_nickname(str1);
            person y;
            y.set_nickname(str2);
            m_social_graph.remove_adjacency(x,y);
            break;

        }
        case 6:
        {
            show_second_menu();
            break;
        }


        case  7:
        {
            ofstream data_base_out("data_base.dat",  ios::out |ios::trunc);
            save_data(data_base_out);
            break;
        }


        default :
        {

            cout<<"Opci\xa2n incorrecta"<<endl;
            break;

        }
        }
    }
}


/**
*   EFE:Muestra el segundo menu, el de consultas.
*   REQ:N/A.
*   MOD:N/A.
*/
void social_network::show_second_menu()
{
    int option =0;
    while( ( option=ask_option(2) )!= 7 )
    {
        switch (option)
        {
        case 1:
        {
            cout<<"\nIngrese el nick de la persona que quiere ver los amigos"<<endl;
            string nick = "";
            getline(cin,nick);
            person x;
            x.set_nickname(nick);
            m_social_graph.print_friends(x);
            break;
        }


        case 2:
        {
            cout<<"\nIngrese el nick de la persona a verificar en la red"<<endl;
            string nick = "";
            getline(cin,nick);
            person x;
            x.set_nickname(nick);
            bool ex = m_social_graph.exist_in_net(x);
            if(ex)
            {
                cout<<"\nEfectivamente esta en la red"<<endl;
            }
            else
            {
                cout<<"\nNo esta en la red"<<endl;

            }
            break;
        }

        case 3:
        {
            cout<<"\nIngrese los nicknames de las personas de las cuales ud quiere ver sus amigos en comun\n"<<endl;
            string str1= "";
            string str2= "";
            cout<<"a. ";
            getline(cin,str1);
            cout<<"\nb. ";
            getline(cin,str2);
            person x;
            x.set_nickname(str1);
            person y;
            y.set_nickname(str2);
            m_social_graph.print_mutual_friends(x,y);
            break;

        }

        case 4:
        {

            cout<<"\nIngrese dos nicknames para ver si son amigos"<<endl;
            string str1= "";
            string str2= "";
            cout<<"a. ";
            getline(cin,str1);
            cout<<"\nb. ";
            getline(cin,str2);
            person x;
            x.set_nickname(str1);
            person y;
            y.set_nickname(str2);
            bool are = m_social_graph.are_related(x,y);
            if(are)
            {
                cout<<str1<<" y "<<str2<<" si son amigos\n"<<endl;
            }
            else
            {
                cout<<str1<<" y "<<str2<<" no son amigos\n"<<endl;
            }
            break;

        }


        case 5:
        {
            m_social_graph.print_people_in_net();
            break;

        }
        case 6:
        {
            string nick = "";
            cout<<"\nIngrese el nick de la persona que quiere consultar: ";
            getline(cin,nick);
            person human;
            human.set_nickname(nick);
            m_social_graph.consult(human);
            break;

        }
        default:
        {
            cout<<"Opci\xa2n incorrecta"<<"\n";

        }
        }
    }
}
/**
*   EFE:Guarda la base de datos.
*   REQ:Objeto ofstream.
*   MOD:N/A.
    \brief Los archivos se guardan en bloques, el primer bloque va la personas y todas sus caracteristicas, ie nombre, nick edad, etc.
    En el segundo bloque van sus amigos, "*" si no tiene amigos.
*/
void social_network::save_data(ofstream& out)
{
    if(m_social_graph.is_empty_() == false)
    {
typename   graph<person>::graph_data::iterator iter1 = m_social_graph.data.begin();
        graph<person>::graph_data::iterator fin=m_social_graph.data.end();

        while(iter1!=fin)
        {
            out<< (iter1->first);
            graph<person>::friends::iterator iter2 = iter1->second.begin();
            graph<person>::friends::iterator fin2=iter1->second.end();


            if(iter2!=fin2)
            {
                while( iter2!=fin2)
                {
                    out<<iter2->first.get_nickname();
                    ++iter2;
                    if(iter2 != fin2) //++iter2 != fin2
                    {
                        out<<",";//separa por comas
                    }
                }
            }
            else
            {
                out<<"*";//Si no tiene amigos pone un asterisco

            }
            ++iter1;
            if( iter1!= fin)
            {
                out<<endl;
            }
        }
        out.close();
    }
}

/**
*   EFE:Carga la base de datos (solo personas, no sus relaciones).
*   REQ:Objeto ifstream
*   MOD:N/A.
   \brief La estructura del archivo que ha sido guardado es:
    Primer bloque: person con todas sus caracteristicas, ie nombre, nick, hobbies...
    Segundo bloque:  sus amigos, si sale "*", no tiene amigos.
    Para cargar solo las personas vamos a inicializar la variable i en 2, y cada vez que carga una persona le  incrementa uno,
    y cuando se le incrementa uno, va a estar en la lista de amigos de esa persona, pero en este metodo no nos importa,
    por ende vamos a  agarrar solo los multiplos de 2.
    Resumiendo, el bloque person son multiplos de 2, y el bloque amigos no lo es.
*/


void social_network::load_people(ifstream& in )
{
    int i = 2;
    if(in.is_open())
    {
        cout<<endl;
        while(!in.eof())
        {

            if(i%2 ==0) //Si no estamos en el bloque de amigos
            {
                person human;
                in>>(human);

                (m_social_graph.add_vertex(human));

            }
            else
            {
                string x = "";//Lo hago solamente para pasar al siguiente bloque de informacion
                getline(in,x);
            }
            ++i;

        }
    }
}

/**
*   EFE:Carga la base de datos (las relaciones)
*   REQ:N/A.
*   MOD:N/A.
*/
void social_network::load_friends(ifstream& in)
{
    //Me posiciono en el segundo bloque, el de los amigos.


    if(in.is_open())
    {
        cout<<endl;
        person human;
        in>>(human);
        while(!in.eof())
        {
            graph<person>::graph_data::iterator iter = m_social_graph.data.begin();
            graph<person>::graph_data::iterator fin = m_social_graph.data.end();

            while(iter != fin)
            {
                string friends= "";
                getline(in,friends);
                if( friends!= "*")   //Si si existen amigos
                {
                    char* fr = new char [friends.length() +1];
                    strcpy(fr,friends.c_str());
                    char* ptr = strtok(fr, ",");
                    while(ptr!= NULL)
                    {
                        person dst;
                        dst.set_nickname(ptr);
                        person src=(iter->first);
                        m_social_graph.add_adjacency(src,dst);
                        ptr=strtok(NULL,",");
                    }
                    delete fr;
                }
                person human;
                in>>(human);
                ++iter;
            }
        }
    }
}
