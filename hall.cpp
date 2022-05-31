#include <iostream>
#include "hall.h"

using namespace std;

Hall::Hall(unsigned int nr, unsigned int s, unsigned int ts)
{
    set_number(nr);
    set_seats(s);
    set_taken_seats(ts);
}

Hall::~Hall(){};

// Hall::Hall(){};

Hall &Hall::operator++()
{
    taken++;
    return *this;
}

unsigned int Hall::get_number()
{
    return number;
}

unsigned int Hall::get_seats()
{
    return seats;
}

unsigned int Hall::get_taken_seats()
{
    return taken;
}

void Hall::set_number(unsigned int new_number)
{
    if (new_number == 0)
    {
        throw invalid_argument("Number must be positive!");
    }
    else
    {
        number = new_number;
    }
}

void Hall::set_seats(unsigned int new_seats)
{
    if (new_seats == 0)
    {
        throw invalid_argument("Number of seats must be positive!");
    }
    else
    {
        seats = new_seats;
    }
}

void Hall::set_taken_seats(unsigned int new_taken_seats)
{
    taken = new_taken_seats;
}
