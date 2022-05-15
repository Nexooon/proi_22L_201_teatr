#ifndef USHER_H
#define USHER_H
#include <iostream>
#include "worker.h"
using namespace std;

class Usher : public Worker
{
    private:
        int sold_tickets;

    public:
        Usher(string name, string obligation, int sold_tickets);
        void set_schedule() override; // przedefiniowana wersja metody wirtualnej

        void set_sold_tickets(int tickets);

        int get_sold_tickets() const;

        friend ostream& operator<<(ostream& os, const Usher& ush);
};

ostream& operator<<(ostream& os, const Usher& ush);

#endif
