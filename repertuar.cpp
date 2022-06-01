#include <iostream>
#include <list>
#include "repertuar.h"
#include "data.h"
#include "theatre.h"
#include "data.h"
#include "play.h"
#include "comedy.h"
#include "drama.h"
#include "tragedy.h"
#include "hall.h"
#include "date.h"
#include "worker.h"
#include "usher.h"


using namespace std;

Repertuar::Repertuar(Hall h)
{
    hall_obj = h;
}

Repertuar::~Repertuar(){};

int Repertuar::get_hall_max_seats()
{
    return hall_obj.get_seats();
}

Hall Repertuar::get_hall_obj()
{
    return hall_obj;
}

Repertuar &Repertuar::operator++()
{
    hall_obj.taken++;
    return *this;
}

void Repertuar::add_play(shared_ptr<Play> play)
{
    plays.push_back(move(play));
}

void Repertuar::add_comedy(shared_ptr<Comedy> comedy)
{
    plays.push_back(move(comedy));
}

void Repertuar::add_drama(shared_ptr<Drama> drama)
{
    plays.push_back(move(drama));
}

void Repertuar::add_tragedy(shared_ptr<Tragedy> tragedy)
{
    plays.push_back(move(tragedy));
}

void Repertuar::print_repertuar()
{
    cout << "Hall number: " << hall_obj.get_number() << endl;
    cout << "Title:" << endl;
    for (const auto &play_ptr : plays)
    {
        cout << "    " << play_ptr->get_title() << endl;
    }
    cout << endl;
}

void Repertuar::print_summary()
{
    // cout << "Hall number: " << hall_obj.get_number() << endl;
    cout << endl
         << endl
         << "Seats " << hall_obj.get_taken_seats() << "/" << hall_obj.get_seats() << endl;
}
