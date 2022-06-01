#ifndef __theatre
#define __theatre

#include <iostream>
#include <vector>
// #include "theatre.h"
#include "data.h"
// #include "data.h"
#include "play.h"
#include "comedy.h"
#include "drama.h"
#include "tragedy.h"
#include "hall.h"
// #include "date.h"
#include "repertuar.h"
#include "worker.h"
#include "usher.h"
// #include "person.h"

using namespace std;

class Theatre
{
protected:
    Data data;
    vector<Repertuar> repertuars;
    Date date;

public:
    Theatre(Data &data, Date date);
    virtual ~Theatre();
    Repertuar create_random_repertuar();

    void simulation(int days);
};

#endif