#ifndef REGULAR_TICKET_H
#define REGULAT_TICKET_H
#include <iostream>
#include "hall.h"
#include "play.h"

using namespace std;


class RegularTicket
{
    protected:
        int base_price;
        Hall ticket_hall;
        Play ticket_play;

    public:
        RegularTicket(int base_price, Hall h, Play p);
        virtual int calculate_price() const;

        void set_base_price(int price);
        void set_hall(Hall h);
        void set_play(Play p);

        virtual ~RegularTicket();

        int get_base_price() const;
        Hall get_hall() const;
        Play get_play() const;

        friend ostream& operator<<(ostream& os, const RegularTicket& ticket);
};

ostream& operator<<(ostream& os, const RegularTicket& ticket);

#endif
