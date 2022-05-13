#ifndef play
#define play

#include <iostream>

using namespace std;

class Play
{
    string title;
    unsigned int duration, price;

public:
    Play(string title, unsigned int price, unsigned int duration);

    string get_title();
    unsigned int get_duration();
    unsigned int get_price();

    void set_title(string title);
    void set_duration(unsigned int new_duration);
    void set_price(unsigned int new_price);
};

#endif
