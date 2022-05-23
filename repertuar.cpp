#include <iostream>
#include <list>
#include "repertuar.h"
#include "play.h"
#include "comedy.h"
#include "drama.h"
#include "tragedy.h"

using namespace std;

Repertuar::Repertuar(Hall h)
{
    hall_obj = h;
}

Repertuar::~Repertuar(){};

void Repertuar::add_play(Play play)
{
    unique_ptr<Play> added_play = make_unique<Play>(play.get_title(), play.get_price(), play.get_duration());
    plays_list.push_back(move(added_play));
}

void Repertuar::add_comedy(Comedy comedy)
{
    unique_ptr<Comedy> added_comedy = make_unique<Comedy>(comedy.get_title(), comedy.get_price(), comedy.get_duration(), comedy.get_nfunny_scenes());
    plays_list.push_back(move(added_comedy));
}

void Repertuar::add_drama(Drama drama)
{
    unique_ptr<Drama> added_drama = make_unique<Drama>(drama.get_title(), drama.get_price(), drama.get_duration(), drama.get_main_drama_thread());
    plays_list.push_back(move(added_drama));
}

void Repertuar::add_tragedy(Tragedy tragedy)
{
    unique_ptr<Tragedy> added_tragedy = make_unique<Tragedy>(tragedy.get_title(), tragedy.get_price(), tragedy.get_duration(), tragedy.get_tragic_character_name());
    plays_list.push_back(move(added_tragedy));
}

void Repertuar::print_repertuar()
{
    cout << "Hall number: " << hall_obj.get_number() << endl;
    for (list<unique_ptr<Play>>::iterator i = plays_list.begin(); i != plays_list.end(); i++)
    {
        cout << (*i)->get_title() << endl;
    }
}

void Repertuar::print_summary()
{
    cout << "Hall number: " << hall_obj.get_number() << endl;
    ;
    cout << "Seats" << hall_obj.get_taken_seats() << "/" << hall_obj.get_seats() << endl;
}
