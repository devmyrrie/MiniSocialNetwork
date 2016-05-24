#include "graph.h"
#include "person.h"
#include "UnitTest++.h"
#include <iostream>
#include <fstream>
using namespace std;


namespace
{

graph<person> x;
graph<int> num;

person person_1,person_2,person_3,person_4,person_5,person_6;
int a,b,c,d,e,f;

void iniciar_personas()
{

    ifstream entrada("in.dat",  ios::in);

    entrada>>person_1;
    entrada>>person_2;
    entrada>>person_3;
    entrada>>person_4;
    entrada>>person_5;
    entrada>>person_6;





}

void iniciar_numeros()
{
    ifstream entrada("in_numbers.dat",  ios::in);

    entrada>>a;
    entrada>>b;
    entrada>>c;
    entrada>>d;
    entrada>>e;
    entrada>>f;


}




TEST(agregar_personas)
{
    iniciar_personas();
    //El resultado espero que sea true, ya que si lo agrego
    bool result =x.add_vertex(person_1);
    CHECK_EQUAL(true, result);

    //Espero un error, ya que no voy a poder agregar a la persona
    result =x.add_vertex(person_1);
    CHECK_EQUAL(true, result); //Espero que el resultado sea true, o sea que se agregue la persona, pero esto no pasara por que no se va  aagregar

    //Resultado true, no hay error, si lo agrega
    result =x.add_vertex(person_2);
    CHECK_EQUAL(true, result); //Espero que el resultado sea true

result =x.add_vertex(person_2);//espero un error
    CHECK_EQUAL(true, result);

    //Resultado true, no hay error, si lo agrega
    result =x.add_vertex(person_3);
    CHECK_EQUAL(true, result);

    result =x.add_vertex(person_4);
    CHECK_EQUAL(true, result);

    result =x.add_vertex(person_5);
    CHECK_EQUAL(true, result);

    result =x.add_vertex(person_6);
    CHECK_EQUAL(true, result);

}

TEST(eliminar_persona)
{
    //Espero que todo vaya bien, no habrá erro, ya que se va a eliminar alguien que si esta en la red.
    bool result =x.remove_vertex(person_1);
    CHECK_EQUAL(true, result);

    //Espero un error, voy a eliminar a alguien que ni tan siquiera esta en la red.
    result =x.remove_vertex(person_1);
    CHECK_EQUAL(true, result);

    result =x.remove_vertex(person_1);//eeror ya qu eesta eliminado
    CHECK_EQUAL(true, result);


    result =x.remove_vertex(person_2);
    CHECK_EQUAL(true, result);

    result =x.remove_vertex(person_3);
    CHECK_EQUAL(true, result);

}

TEST(buscar_personas)
{
    //en el test anterior se borro a person_1,person_2 y person_3 por ende hay que agregarlo de nuevo:
    x.add_vertex(person_1);
    x.add_vertex(person_2);
    //No espero error, ya que si existe en red
    bool result =x.exist_in_net(person_1);
    CHECK_EQUAL(true, result);

    result =x.exist_in_net(person_2);
    CHECK_EQUAL(true, result);

//person_3 fue eliminada en el test anterior, y no se agrego de nuevo , por eso no va a esta ren la red y yo estaba esperando que si estuviera
    result =x.exist_in_net(person_3);
    CHECK_EQUAL(true, result);

}


TEST(agregar_numero)
{
    iniciar_numeros();
    bool result = num.add_vertex(a);
    CHECK_EQUAL(true, result);

    result = num.add_vertex(b);
    CHECK_EQUAL(true, result);

//Voy a esperar que no me agregue al c, pero si lo va  a agregar, deberia de brincar un error
    result = num.add_vertex(c);
    CHECK_EQUAL(false, result);

    result = num.add_vertex(d);
    CHECK_EQUAL(true, result);

    result = num.add_vertex(e);
    CHECK_EQUAL(true, result);
//espero un error
 result = num.add_vertex(e);
    CHECK_EQUAL(true, result);

    result = num.add_vertex(f);
    CHECK_EQUAL(true, result);

//espero un error
    result = num.add_vertex(f);
    CHECK_EQUAL(true, result);
}

TEST(eliminar_numero)
{
    bool result =num.remove_vertex(a);
    CHECK_EQUAL(true, result);

    result =num.remove_vertex(b);
    CHECK_EQUAL(true, result);
//espero error ya que no se puede eliminar, ya esta eliminado
  result =num.remove_vertex(b);
    CHECK_EQUAL(true, result);

    result =num.remove_vertex(c);
    CHECK_EQUAL(true, result);

//no deberia de haber borrado daf, ya que ni existe en el grafo, deberia de brincar error
    int daf =999;
    result =num.remove_vertex(daf);
    CHECK_EQUAL(true, result);//estoy esperando true, pero va  a devolver false ya que no se pudo borrar


    result =num.remove_vertex(e);
    CHECK_EQUAL(true, result);

    result =num.remove_vertex(f);
    CHECK_EQUAL(true, result);

    result =num.remove_vertex(d);
    CHECK_EQUAL(true, result);
}

TEST(buscar_numero){



    //en el test anterior se borro a  a,b c,d,e,f por ende hay que agregarlo de nuevo, pero solo a,b,c:
    num.add_vertex(a);
    num.add_vertex(b);
    num.add_vertex(c);

    //No espero error, ya que si existe en red
    bool result =num.exist_in_net(a);
    CHECK_EQUAL(true, result);

    result =num.exist_in_net(b);
    CHECK_EQUAL(true, result);

result =num.exist_in_net(c);
    CHECK_EQUAL(true, result);

//d  fue eliminada en el test anterior, y no se agrego de nuevo , por eso no va a estar en grafo.
    result =num.exist_in_net(d);
    CHECK_EQUAL(true, result);//estoy esperando true, pero me devolvera false


}
}


