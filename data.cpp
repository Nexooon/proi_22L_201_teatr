#include <iostream>
#include <fstream>
#include <list>
#include "data.h"
#include "hall.h"
#include "play.h"
#include "comedy.h"

using namespace std;

Data::Data(vector<Hall> h, vector<Play> p, vector<Comedy> c, vector<Drama> d, vector<Tragedy> t)
{
    halls = h;
    plays = p;
    comedies = c;
    dramas = d;
    tragedies = t;
}

Data::Data(const Data *d)
{
    halls = d->halls;
    plays = d->plays;
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
            Play play_obj(title, stoi(price), stoi(duration));
            plays.push_back(play_obj);
        }
        if (type == "2")
        {
            file >> nfunny_scenes;
            Comedy comedy_obj(title, stoi(price), stoi(duration), stoi(nfunny_scenes));
            comedies.push_back(comedy_obj);
        }
        if (type == "3")
        {
            file >> drama_thread;
            Drama drama_obj(title, stoi(price), stoi(duration), drama_thread);
            dramas.push_back(drama_obj);
        }
        if (type == "4")
        {
            file >> tragic_ch_name;
            Tragedy tragedy_obj(title, stoi(price), stoi(duration), tragic_ch_name);
            tragedies.push_back(tragedy_obj);
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
    return plays.size();
}

int Data::comedies_size()
{
    return comedies.size();
}

int Data::dramas_size()
{
    return dramas.size();
}

int Data::tragedies_size()
{
    return tragedies.size();
}

void Data::add_random_play_to_repertuar(Repertuar repertuar) // adds 2 plays
{
    for (int i = 0; i < 2; i++)
    {
        int x = rand() % 4 + 1;

        if (x == 1)
        {
            int tmp = rand() % plays.size() + 1;
            repertuar.add_play(plays[tmp]);
        }
        else if (x == 2)
        {
            int tmp = rand() % comedies.size() + 1;
            repertuar.add_comedy(comedies[tmp]);
        }
        else if (x == 3)
        {
            int tmp = rand() % dramas.size() + 1;
            repertuar.add_drama(dramas[tmp]);
        }
        else if (x == 4)
        {
            int tmp = rand() % tragedies.size() + 1;
            repertuar.add_tragedy(tragedies[tmp]);
        }
        else
        {
            throw invalid_argument("Adding random doesnt work right!");
        }
    }
}
