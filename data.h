#ifndef __data
#define __data

#include <iostream>
#include <vector>
#include "hall.h"
#include "play.h"
#include "comedy.h"
#include "drama.h"
#include "tragedy.h"

using namespace std;

class Data
{
    vector<Hall> halls;
    vector<Play> plays;
    vector<Comedy> comedies;
    vector<Drama> dramas;
    vector<Tragedy> tragedies;

public:
    Data(vector<Hall> halls, vector<Play> plays, vector<Comedy> comedies, vector<Drama> dramas, vector<Tragedy> tragedies);
    Data(const Data *data);
    virtual ~Data();

    // void read(string path);
    void read_plays(string plays_path);
    void read_halls(string halls_path);

    int halls_size();
    int plays_size();
    int comedies_size();
    int dramas_size();
    int tragedies_size();

    // friend void add_play_obj(vector<Play> plays, string title, string price, string time);
    // friend void add_hall_obj(vector<Hall> halls, string hnr, string hseats);
    // friend int get_header(string line);
};

// void add_play_obj(vector<Play> plays, string title, string price, string time);
// void add_hall_obj(vector<Hall> halls, string hnr, string hseats);
// int get_header(string line);

// Hall read_hall_obj(string line, int nline);

#endif