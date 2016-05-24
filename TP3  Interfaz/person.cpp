#include "person.h"
#include <iostream>
#include <sstream>
using namespace std;

person::person()
{
    m_nickname = "";
    m_fullname="";
    m_age=0;
    m_sex=false;
}
person::~person(){


}

bool person::operator == (const person &p) const
{
    return  (this->m_nickname==p.m_nickname);
}
bool person::operator != (const person &p) const{

 return  (this->m_nickname!=p.m_nickname);
}



bool  person::operator < (const person &p)const
{
    return  (this->m_nickname<p.m_nickname);
}

bool  person::operator > (const person &p)const
{
    return  (this->m_nickname>p.m_nickname);
}
bool  person::operator <= (const person &p)const
{
    return  (this->m_nickname<=p.m_nickname);
}
bool  person::operator >= (const person &p) const
{
    return  (this->m_nickname>=p.m_nickname);
}

person::person(std::string& nick,std::string& fullname,unsigned int& age,bool& sex,std::string hobbies[])
{
    m_nickname = nick;
    m_fullname=fullname;
    m_age=age;
    m_sex=sex;

    if(hobbies != NULL)
    {
        for (int i=0; i<10; i++)
        {
            m_hobbies[i] = hobbies[i];
        }
    }


}

/**
*   EFE:Imprime  via ostream la información de la persona.
*   REQ:Objeto tipo ostream.
*   MOD:N/A.
**/
wxString person::print_info() const
{
    wxString s;
    s<<"\n"<<"Nombre: "<<m_fullname<<"\n"
     <<"Nickname: "<<m_nickname<<"\n"
     <<"Edad: "<<m_age<<"\n";
    string x = (m_sex==false)? "Masculino":"Femenino";
    s<<"Sexo: "<<x<<"\n";
    s<<"Sus hobbies son: "<<"\n";
    for(int i = 0; i<10; ++i)
    {
        s<<i+1<<"."<<m_hobbies[i]<<"\n";
    }
    return s;
}

/**
*   EFE:Sobrecarga el operador << para imprmir via ostream, la informacion de la persona.
*   REQ:Objeto tipo person.
*   MOD:N/A
**/
ostream& operator << (ostream &out, const person &p)
{
    out << p.m_nickname << "\n" << p.m_fullname << "\n" << p.m_age << "\n" << p.m_sex << "\n";
    for(int i = 0; i<10; ++i)
    {
        out << p.m_hobbies[i] << "\n";
    }
    return out;
}
/**
*   EFE:Sobrecarga el operador >> para la lectura de archivos.
*   REQ:Flujo de entrada y un objeto de tipo persona.
*   MOD: La persona que le entro por parametro.
**/
istream& operator >> (istream& in, person &p)
{
    getline(in, p.m_nickname);
    getline(in, p.m_fullname);
    string age_string= "";
    int age = -1;
    getline(in,age_string);
    stringstream my_stream(age_string);
    my_stream>>age;
    p.m_age=age;

    string sex_string= "";
    getline(in,sex_string);
    stringstream my_stream_2(sex_string);
    my_stream_2>>p.m_sex;

    string hobbie="";
    for(int i = 0 ; i<10; ++i)
    {
        getline(in, hobbie);
        p.m_hobbies[i]=hobbie;
    }

    return in;

}

std::string person::get_nickname() const
{
    return m_nickname;
}

void person::set_nickname(string x)
{
    m_nickname=x;
}


std::string person::get_fullname()
{
    return m_fullname;
}

void  person::set_fullname(string fullname)
{
    m_fullname=fullname;
}


unsigned int person::get_age()
{
    return m_age;
}

void  person::set_age(unsigned int age)
{
    m_age=age;
}

bool person::get_sex()
{
    return m_sex;
}

void person::set_sex(bool sex)
{
    m_sex=sex;
}



std::string* person::get_hobbies()
{
    return m_hobbies;
}


void person::set_hobbies(string hobbies[])
{
    for (int i=0; i<10; i++)
    {
        m_hobbies[i] = hobbies[i];
    }
}
