#ifndef __tragedy
#define __tragedy

#include <iostream>
#include "play.h"

using namespace std;

class Tragedy : public Play
{
private:
    string tragic_character_name;

public:
    Tragedy(string title, unsigned int price = 60, unsigned int duration = 120, string tragic_character_name = "Jack");

    string get_tragic_character_name();

    void set_tragic_charactesr_name(string new_tragic_character_name);

    friend std::ostream &operator<<(std::ostream &os, const Tragedy &tragedyy);
};

std::ostream &operator<<(std::ostream &os, const Tragedy &strategyy);

#endif