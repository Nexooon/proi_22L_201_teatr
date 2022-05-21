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

    void read_plays(string plays_path);
    void read_halls(string halls_path);

    int halls_size();
    int plays_size();
    int comedies_size();
    int dramas_size();
    int tragedies_size();
};

#endif