#ifndef __data
#define __data

#include <iostream>
#include <vector>
#include <list>
#include "play.h"
#include "comedy.h"
#include "drama.h"
#include "tragedy.h"
#include "hall.h"
// #include "date.h"
#include "repertuar.h"
// #include "theatre.h"
#include "worker.h"
#include "usher.h"
#include "person.h"

using namespace std;

class Data
{
protected:
    vector<Hall> halls;
    vector<shared_ptr<Play>> plays;
    vector<shared_ptr<Worker>> workers;
    vector<Person> people;

public:
    Data(vector<Hall> halls, vector<shared_ptr<Play>> plays, vector<shared_ptr<Worker>> workers, vector<Person> people);
    Data(const Data &data);
    Data();
    virtual ~Data();

    void read_plays(string plays_path);
    void read_halls(string halls_path);
    void read_workers(string workers_path);
    void read_people(string people_path);

    int halls_size();
    int plays_size();
    int workers_size();
    int people_size();

    void add_play(string title, unsigned int price, unsigned int duration);
    void add_comedy(string title, unsigned int price, unsigned int duration, unsigned int n_funny_scenes);
    void add_drama(string title, unsigned int price, unsigned int duration, string main_drama_thread);
    void add_tragedy(string title, unsigned int price, unsigned int duration, string tragic_character_name);
    void add_worker(string name, string obligation);
    void add_usher(string name, string obligation, int sold_tickets);
    void add_person(string name, string surname);

    void add_random_play_to_repertuar(Repertuar &repertuar);
    Hall get_random_hall();

    void buy_a_ticket(Repertuar &repertuar);
};

#endif
