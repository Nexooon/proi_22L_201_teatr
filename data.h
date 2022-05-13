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

    void read_halls(string halls_path);
    void read_plays(string plays_path);

    // string hallspath, playspath;

    // Data(string hallspath, string playspath);
};

#endif