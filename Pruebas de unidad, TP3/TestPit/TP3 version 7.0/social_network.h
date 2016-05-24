#ifndef SOCIAL_NETWORK_H
#define SOCIAL_NETWORK_H
#include <string>
#include "graph.h"
#include "person.h"

class social_network
{
public:
    social_network();
    ~social_network();
    void load_people(std::ifstream& in);
    void load_friends(std::ifstream& in);
    void save_data(std::ofstream& out);
    void show_first_menu();
    void show_second_menu();
    void create_person(person& x);
    int ask_option(int x);



private:
    graph<person> m_social_graph; /**< Variable tipo graph */
};

#endif // SOCIAL_NETWORK_H
