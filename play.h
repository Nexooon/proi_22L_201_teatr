#ifndef __play
#define __play

#include <iostream>

using namespace std;

class Play
{
protected:
    string title;
    unsigned int duration, price;

public:
    Play(string title = "title", unsigned int price = 100, unsigned int duration = 120);
    virtual ~Play();

    string get_title();
    unsigned int get_duration();
    unsigned int get_price();

    void set_title(string title);
    void set_duration(unsigned int new_duration);
    void set_price(unsigned int new_price);

    friend std::ostream &operator<<(ostream &os, const Play &playy);
};

std::ostream &operator<<(ostream &os, const Play &playy);

#endif
