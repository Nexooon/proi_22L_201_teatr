#ifndef hall
#define hall

#include <iostream>

using namespace std;

class Hall
{
    unsigned int number, seats;

public:
    Hall(unsigned int number, unsigned int seats);

    unsigned int get_number();
    unsigned int get_seats();

    void set_number(unsigned int new_number);
    void set_seats(unsigned int new_seats);
};

#endif
