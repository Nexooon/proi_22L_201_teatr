#ifndef REDUCED_TICKET_STUDENT_H
#define REDUCED_TICKET_STUDENT_H
#include <iostream>
#include "regular_ticket.h"
using namespace std;

class ReducedTicketStudent : public RegularTicket
{
    public:
        // ReducedTicketChildren(int base_price, Hall h, Play p);

        int calculate_price() const override;

        // friend ostream& operator<<(ostream& os, const ReducedTicketChildren& ticket);
};

// ostream& operator<<(ostream& os, const ReducedTicketChildren& ticket);

#endif
