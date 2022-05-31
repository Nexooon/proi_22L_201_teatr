#ifndef __person
#define __person

#include <iostream>

using namespace std;

class Person
{
    string name, surname;

public:
    Person(string name, string surname);
    ~Person();

    string get_name();
    string get_surname();

    void set_name(string new_name);
    void set_surname(string new_name);

    friend std::ostream &operator<<(ostream &os, const Person &personn);
};

std::ostream &operator<<(ostream &os, const Person &personn);

#endif