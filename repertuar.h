#ifndef __repertuar
#define __repertuar

#include <iostream>
// #include <vector>
#include <list>
#include <memory>
#include "play.h"
#include "hall.h"
#include "comedy.h"
#include "drama.h"
#include "tragedy.h"

using namespace std;

class Repertuar
{
public:
    Hall hall_obj;
    // vector<Play> playss;
    // vector<Comedy> comediess;
    // vector<Drama> dramass;
    // vector<Tragedy> tragediess;
    list<unique_ptr<Play>> plays_list;

    // Repertuar(Hall h, vector<Play> playss, vector<Comedy> comediess, vector<Drama> dramass, vector<Tragedy> tragediess);
    Repertuar(Hall hall);
    ~Repertuar();

    void add_play(Play play);
    void add_comedy(Comedy comedy);
    void add_drama(Drama drama);
    void add_tragedy(Tragedy tragedy);

    void print_repertuar();
    void print_summary();
};

#endif