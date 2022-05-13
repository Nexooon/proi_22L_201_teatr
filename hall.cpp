#include <iostream>
#include "hall.h"

using namespace std;

Hall::Hall(unsigned int nr, unsigned int s)
{
    set_number(nr);
    set_number(s);
}

unsigned int Hall::get_number()
{
    return number;
}

unsigned int Hall::get_seats()
{
    return seats;
}

void Hall::set_number(unsigned int new_number)
{
    if (new_number != 0)
    {
        number = new_number;
    }
    else
    {
        throw invalid_argument("Number must be positive!");
    }
}

void Hall::set_seats(unsigned int new_seats)
{
    if (new_seats != 0)
    {
        seats = new_seats;
    }
    else
    {
        throw invalid_argument("Number of seats must be positive!");
    }
}
