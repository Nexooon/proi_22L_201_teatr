#include <iostream>
#include "tragedy.h"
#include "play.h"

using namespace std;

Tragedy::Tragedy(string t, unsigned int p, unsigned int d, string n) : Play(t, p, d)
{
    set_tragic_charactesr_name(n);
}

string Tragedy::get_tragic_character_name()
{
    return tragic_character_name;
}

void Tragedy::set_tragic_charactesr_name(string new_tragic_character_name)
{
    tragic_character_name = new_tragic_character_name;
}

std::ostream &operator<<(std::ostream &os, const Tragedy &tragedyy)
{
    os << "Title: " << tragedyy.title << endl
       << "Price: " << tragedyy.price << endl
       << "Duration: " << tragedyy.duration << endl
       << "Tragic character's name: " << tragedyy.tragic_character_name << endl;
    return os;
}