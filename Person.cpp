#include <iostream>
#include "person.h"

using namespace std;

Person::Person(string n, string s)
{
    name = n;
    surname = s;
}

Person::~Person() {}

string Person::get_name()
{
    return name;
}

string Person::get_surname()
{
    return surname;
}

void Person::set_name(string new_name)
{
    name = new_name;
}

void Person::set_surname(string new_surname)
{
    surname = new_surname;
}

std::ostream &operator<<(ostream &os, const Person &personn)
{
    os << personn.name << " " << personn.surname << " ";
    return os;
}