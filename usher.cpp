#include "usher.h"
#include <iostream>
using namespace std;

Usher::Usher(string name, string obligation, int sold_tickets) :
Worker(name, obligation), sold_tickets(sold_tickets)
{
    if (sold_tickets < 0)
        throw invalid_argument("Tickets cannot be negative");
    set_schedule();
}

void Usher::set_schedule()
{
    weekly_schedule["Monday"] = "9:00 - 15:00";
    weekly_schedule["Tuesday"] = "9:00 - 16:00";
    weekly_schedule["Wednesday"] = "10:00 - 15:00";
    weekly_schedule["Thursday"] = "8:00 - 16:00";
    weekly_schedule["Friday"] = "9:00 - 14:00";
}

void Usher::set_sold_tickets(int tickets)
{
    if (tickets < 0)
        throw invalid_argument("Tickets cannot be negative");
    sold_tickets = tickets;
}

int Usher::get_sold_tickets() const
{
    return sold_tickets;
}

ostream& operator<<(ostream& os, const Usher& ush)
{
    os << "Usher: " << ush.name << " " << ush.obligation << " " << ush.sold_tickets <<"\n";
    return os;
}
