#include "regular_ticket.h"
#include <iostream>
using namespace std;

//no default constructor for Hall and Price
RegularTicket::RegularTicket(int price, Hall h, Play p)
{
    base_price = price;
    ticket_hall = h;
    ticket_play = p;
}

int RegularTicket::calculate_price() const
{
    return base_price;
}

void RegularTicket::set_base_price(int price)
{
    base_price = price;
}

void RegularTicket::set_hall(Hall h)
{
    ticket_hall = h;
}

void RegularTicket::set_play(Play p)
{
    ticket_play = p;
}

RegularTicket::~RegularTicket() {}

int RegularTicket::get_base_price() const
{
    return base_price;
}

Hall RegularTicket::get_hall() const
{
    return ticket_hall;
}

Play RegularTicket::get_play() const
{
    return ticket_play;
}

//dodac wypisywanie hall i play lub roziwazac problem braku mozliwosci odwolania do zmiennych title i number
ostream& operator<<(ostream& os, const RegularTicket& ticket)
{
    os << "Play: " << ticket.ticket_play << " Hall: " << ticket.ticket_hall.number << " Price: " << ticket.calculate_price();
    return os;
}
