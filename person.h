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
};

#endif