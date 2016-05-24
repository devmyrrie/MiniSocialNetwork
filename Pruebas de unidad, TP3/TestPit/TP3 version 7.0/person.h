#ifndef PERSON_H
#define PERSON_H
#include <string>
class person {
    friend std::ostream& operator << (std::ostream &out, const person& p);
    friend std::istream& operator >> (std::istream& in, person &p);

public:
    person();
    ~person();

    person(std::string nick,std::string fullname="",unsigned int age =20,bool sex =false,std::string*  hobbies =NULL);
    bool operator == (const person &p) const;
    bool operator < (const person &p)const;
    bool operator > (const person &p)const;
    bool operator <= (const person &p) const;
    bool operator >= (const person &p)const;
    bool operator != (const person &p) const;
    std::string get_nickname() const;
    void set_nickname(std::string nick);

    std::string get_fullname();
    void set_fullname(std::string fullname);

    unsigned int get_age();
    void  set_age(unsigned int age);
    bool get_sex();
    void set_sex(bool sex);

    std::string* get_hobbies();
    void set_hobbies(std::string* hobbies);
    void print_info(std::ostream& o) const;
private://
    std::string m_nickname; //!< Member variable "m_nickname"
    std::string m_fullname; //!< Member variable "m_fullname"
    unsigned int m_age; //!< Member variable "m_age"
    bool m_sex; //!< Member variable "m_sex" true es mujer, false es hombre
    std::string m_hobbies[10]; //!< Member variable "m_hobbies"
};

#endif // PERSON_H
