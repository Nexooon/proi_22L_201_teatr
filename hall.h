#ifndef __hall
#define __hall

#include <iostream>

using namespace std;

class Hall
{
protected:
    unsigned int number, seats;

public:
    unsigned int taken;
    Hall(unsigned int number = 1, unsigned int seats = 50, unsigned int taken = 0);
    virtual ~Hall();

    unsigned int get_number();
    unsigned int get_seats();
    unsigned int get_taken_seats();

    Hall operator++();

    void set_number(unsigned int new_number);
    void set_seats(unsigned int new_seats);
    void set_taken_seats(unsigned int new_taken_seats);
};

#endif
