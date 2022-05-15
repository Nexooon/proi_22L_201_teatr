#ifndef __data
#define __data

#include <iostream>
#include <vector>
#include "hall.h"
#include "play.h"

using namespace std;

class Data
{
    vector<Hall> halls;
    vector<Play> plays;

public:
    Data(vector<Hall> halls, vector<Play> plays);
    Data(const Data *data);
    virtual ~Data();

    void read(string path);
    // void read_plays(string plays_path);

    int halls_size();
    int plays_size();

    friend void add_play_obj(vector<Play> plays, string title, string price, string time);
    friend void add_hall_obj(vector<Hall> halls, string hnr, string hseats);
    friend int get_header(string line);
};

void add_play_obj(vector<Play> plays, string title, string price, string time);
void add_hall_obj(vector<Hall> halls, string hnr, string hseats);
int get_header(string line);

#endif