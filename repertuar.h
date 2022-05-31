#ifndef __repertuar
#define __repertuar

#include <iostream>
#include <vector>
#include <list>
#include <memory>
// #include "data.h"
// #include "theatre.h"
#include "play.h"
#include "comedy.h"
#include "drama.h"
#include "tragedy.h"
#include "hall.h"
#include "date.h"
#include "repertuar.h"
// #include "worker.h"
// #include "usher.h"

using namespace std;

class Repertuar
{
protected:
    Hall hall_obj;
    vector<shared_ptr<Play>> plays;

public:
    Repertuar(Hall hall);
    ~Repertuar();

    int get_hall_max_seats();

    void add_play(shared_ptr<Play> play);
    void add_comedy(shared_ptr<Comedy> comedy);
    void add_drama(shared_ptr<Drama> drama);
    void add_tragedy(shared_ptr<Tragedy> tragedy);

    void print_repertuar();
    void print_summary();
};

#endif