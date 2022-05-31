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
    cout << "Titles:" << endl;
    for (const auto &play_ptr : plays)
    {
        cout << "    " << play_ptr->get_title() << endl;
    }
}

void Repertuar::print_summary()
{
    cout << "Hall number: " << hall_obj.get_number() << endl;
    cout << "Seats" << hall_obj.get_taken_seats() << "/" << hall_obj.get_seats() << endl;
}
