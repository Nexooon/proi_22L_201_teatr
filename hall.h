#ifndef __hall
#define __hall

#include <iostream>

using namespace std;

class Hall
{
    unsigned int number, seats, taken;

public:
    Hall(unsigned int number, unsigned int seats, unsigned int taken);
    ~Hall();
    Hall();

    unsigned int get_number();
    unsigned int get_seats();
    unsigned int get_taken_seats();

    void set_number(unsigned int new_number);
    void set_seats(unsigned int new_seats);
    void set_taken_seats(unsigned int new_taken_seats);
};

#endif
