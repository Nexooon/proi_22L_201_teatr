#ifndef __repertuar
#define __repertuar

#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include "data.h"
#include "play.h"
#include "comedy.h"
#include "drama.h"
#include "tragedy.h"
#include "hall.h"
#include "date.h"
#include "theatre.h"

using namespace std;

class Repertuar
{
public:
    Hall hall_obj;

    vector<shared_ptr<Play>> plays;

    Repertuar(Hall hall);
    ~Repertuar();

    void add_play(shared_ptr<Play> play);
    void add_comedy(shared_ptr<Comedy> comedy);
    void add_drama(shared_ptr<Drama> drama);
    void add_tragedy(shared_ptr<Tragedy> tragedy);

    void print_repertuar();
    void print_summary();
};

#endif