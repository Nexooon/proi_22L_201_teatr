#include <iostream>
#include <fstream>
#include <list>
#include <random>
#include "data.h"
#include "play.h"
#include "comedy.h"
#include "drama.h"
#include "tragedy.h"
#include "hall.h"
#include "date.h"
#include "repertuar.h"
#include "theatre.h"
#include "worker.h"
#include "usher.h"

using namespace std;

// Data::Data(vector<Hall> h, vector<Play> p, vector<Comedy> c, vector<Drama> d, vector<Tragedy> t)
// {
//     halls = h;
//     plays = p;
//     comedies = c;
//     dramas = d;
//     tragedies = t;
// }

Data::Data(vector<Hall> h, list<shared_ptr<Play>> p, list<shared_ptr<Worker>> w)
{
    halls = h;
    plays_list = p;
    workers_list = w;
}

Data::Data(const Data *d)
{
    halls = d->halls;
    plays_list = d->plays_list;
    workers_list = d->workers_list;
}

Data::~Data(){};

void Data::read_halls(string path)
{
    fstream file;
    file.open(path, ios::in);

    if (file.good() == false)
    {
        throw invalid_argument("File does not exist!");
        exit(0);
    }
    string nr, seats;
    unsigned int taken = 0;
    while (file >> nr)
    {
        file >> seats;
        Hall hall_obj(stoi(nr), stoi(seats), taken);
        halls.push_back(hall_obj);
    }
    file.close();
}

void Data::read_plays(string path)
{
    fstream file;
    file.open(path, ios::in);

    if (file.good() == false)
    {
        throw invalid_argument("File does not exist!");
        exit(0);
    }
    string title, duration, price, type, nfunny_scenes, drama_thread, tragic_ch_name;
    while (file >> title)
    {
        file >> duration;
        file >> price;
        file >> type;

        if (type == "1")
        {
            add_play(title, stoi(price), stoi(duration));
        }
        if (type == "2")
        {
            file >> nfunny_scenes;
            add_comedy(title, stoi(price), stoi(duration), stoi(nfunny_scenes));
        }
        if (type == "3")
        {
            file >> drama_thread;
            add_drama(title, stoi(price), stoi(duration), drama_thread);
        }
        if (type == "4")
        {
            file >> tragic_ch_name;
            add_tragedy(title, stoi(price), stoi(duration), tragic_ch_name);
        }
    }
    file.close();
}

void Data::read_workers(string path)
{
    fstream file;
    file.open(path, ios::in);

    if (file.good() == false)
    {
        throw invalid_argument("File does not exist!");
        exit(0);
    }
    string name, obligation, sold_tickets, type;
    while (file >> name)
    {
        file >> type;
        file >> obligation;

        if (type == "1")
        {
            add_worker(name, obligation);
        }
        if (type == "2")
        {
            file >> sold_tickets;
            add_usher(name, obligation, stoi(sold_tickets));
        }
    }
    file.close();
}

int Data::halls_size()
{
    return halls.size();
}

int Data::plays_size()
{
    return plays_list.size();
}

// int Data::comedies_size()
// {
//     return comedies.size();
// }

// int Data::dramas_size()
// {
//     return dramas.size();
// }

// int Data::tragedies_size()
// {
//     return tragedies.size();
// }

int Data::workers_size()
{
    return workers_list.size();
}

void Data::add_play(string title, unsigned int price, unsigned int duration)
{
    shared_ptr<Play> added_play = make_shared<Play>(title, price, duration);
    plays_list.push_back(move(added_play));
}

void Data::add_comedy(string title, unsigned int price, unsigned int duration, unsigned int nfunny_scenes)
{
    shared_ptr<Comedy> added_comedy = make_shared<Comedy>(title, price, duration, nfunny_scenes);
    plays_list.push_back(move(added_comedy));
}

void Data::add_drama(string title, unsigned int price, unsigned int duration, string main_drama_thread)
{
    shared_ptr<Drama> added_drama = make_shared<Drama>(title, price, duration, main_drama_thread);
    plays_list.push_back(move(added_drama));
}

void Data::add_tragedy(string title, unsigned int price, unsigned int duration, string tragic_character_name)
{
    shared_ptr<Tragedy> added_tragedy = make_shared<Tragedy>(title, price, duration, tragic_character_name);
    plays_list.push_back(move(added_tragedy));
}

void Data::add_worker(string name, string obligation)
{
    shared_ptr<Worker> added_worker = make_shared<Worker>(name, obligation);
    workers_list.push_back(move(added_worker));
}

void Data::add_usher(string name, string obligation, int sold_tickets)
{
    shared_ptr<Usher> added_usher = make_shared<Usher>(name, obligation, sold_tickets);
    workers_list.push_back(move(added_usher));
}

// void Data::add_random_play_to_repertuar(Repertuar repertuar) // adds 2 plays
// {
//     for (int i = 0; i < 2; i++)
//     {
//         random_device rd;
//         mt19937 gen(rd());
//         uniform_int_distribution<> dist(1, 6);
//         int x = dist(gen);
//         if (x == 1)
//         {
//             uniform_int_distribution<> dist(1, (int)plays.size());
//             repertuar.add_play(plays[dist(gen)]);
//         }
//         else if (x == 2)
//         {
//             uniform_int_distribution<> dist(1, (int)comedies.size());
//             repertuar.add_comedy(comedies[dist(gen)]);
//         }
//         else if (x == 3)
//         {
//             uniform_int_distribution<> dist(1, (int)dramas.size());
//             repertuar.add_drama(dramas[dist(gen)]);
//         }
//         else if (x == 4)
//         {
//             uniform_int_distribution<> dist(1, (int)tragedies.size());
//             repertuar.add_tragedy(tragedies[dist(gen)]);
//         }
//         else
//         {
//             throw invalid_argument("Adding random doesnt work right!");
//         }
//     }
// }
