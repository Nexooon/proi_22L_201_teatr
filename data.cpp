#include <iostream>
#include <fstream>
#include <list>
#include <random>
#include "data.h"
#include "theatre.h"
#include "data.h"
#include "play.h"
#include "comedy.h"
#include "drama.h"
#include "tragedy.h"
#include "hall.h"
#include "date.h"
#include "repertuar.h"
#include "worker.h"
#include "usher.h"

using namespace std;

Data::Data(vector<Hall> h, vector<shared_ptr<Play>> p, vector<shared_ptr<Worker>> w, vector<Person> ppl)
{
    halls = h;
    plays = p;
    workers = w;
    people = ppl;
}

Data::Data(const Data &d)
{
    halls = d.halls;
    plays = d.plays;
    workers = d.workers;
    people = d.people;
}

Data::Data(){};

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

void Data::read_people(string path)
{
    fstream file;
    file.open(path, ios::in);

    if (file.good() == false)
    {
        throw invalid_argument("File does not exist!");
        exit(0);
    }
    string name, surname;
    while (file >> name)
    {
        file >> surname;
        add_person(name, surname);
    }

    file.close();
}

int Data::halls_size()
{
    return halls.size();
}

int Data::plays_size()
{
    return plays.size();
}

int Data::workers_size()
{
    return workers.size();
}

int Data::people_size()
{
    return people.size();
}

void Data::add_play(string title, unsigned int price, unsigned int duration)
{
    Play *play_object = new Play(title, price, duration);
    plays.emplace_back(play_object);
}

void Data::add_comedy(string title, unsigned int price, unsigned int duration, unsigned int nfunny_scenes)
{
    Comedy *comedy_object = new Comedy(title, price, duration, nfunny_scenes);
    plays.emplace_back(comedy_object);
}

void Data::add_drama(string title, unsigned int price, unsigned int duration, string main_drama_thread)
{
    Drama *drama_object = new Drama(title, price, duration, main_drama_thread);
    plays.emplace_back(drama_object);
}

void Data::add_tragedy(string title, unsigned int price, unsigned int duration, string tragic_character_name)
{
    Tragedy *tragedy_object = new Tragedy(title, price, duration, tragic_character_name);
    plays.emplace_back(tragedy_object);
}

void Data::add_worker(string name, string obligation)
{
    Worker *worker_object = new Worker(name, obligation);
    workers.emplace_back(worker_object);
}

void Data::add_usher(string name, string obligation, int sold_tickets)
{
    Usher *usher_object = new Usher(name, obligation, sold_tickets);
    workers.emplace_back(usher_object);
}

void Data::add_person(string name, string surname)
{
    Person person_object(name, surname);
    people.push_back(person_object);
}

void Data::add_random_play_to_repertuar(Repertuar &repertuar) // adds 1 random play
{
    int x;
    // for (int i = 0; i < 2; i++)
    // {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, plays.size() - 1);
    x = dist(gen);
    repertuar.add_play(plays.at(x));
    // }
}

Hall Data::get_random_hall()
{
    int x;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, halls.size() - 1);
    x = dist(gen);
    return halls.at(x);
}

void Data::buy_a_ticket(Repertuar &repertuar)
{
    int x, y;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, repertuar.get_hall_max_seats() - 1);
    x = dist(gen);

    for (int i = 0; i < x; i++)
    {
        uniform_int_distribution<> dist(0, (int)people.size() - 1);
        y = dist(gen);
        cout << people.at(y) << " bought a ticket." << endl;
        // repertuar.hall_obj.taken += 1;
    }
}