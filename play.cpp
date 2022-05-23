#include <iostream>
#include "play.h"

using namespace std;

Play::Play(string t, unsigned int pric, unsigned int d)
{
    set_title(t);
    set_price(pric);
    set_duration(d);
}

Play::~Play(){};

string Play::get_title()
{
    return title;
}

unsigned int Play::get_price()
{
    return price;
}

unsigned int Play::get_duration()
{
    return duration;
}

void Play::set_title(string new_title)
{
    title = new_title;
}

void Play::set_price(unsigned int new_price)
{
    if (new_price != 0)
    {
        price = new_price;
    }
    else
    {
        throw invalid_argument("Price must be a positive number!");
    }
}

void Play::set_duration(unsigned int new_duration)
{
    if (new_duration != 0)
    {
        duration = new_duration;
    }
    else
    {
        throw invalid_argument("Duration must be a positive number!");
    }
}

std::ostream &operator<<(ostream &os, const Play &playy)
{
    os << "Play: " << playy.title << ", price: " << playy.price << ", duration: " << playy.duration << endl;
    return os;
}