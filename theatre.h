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

using namespace std;

class Theatre : public Data
{
protected:
    vector<Repertuar> repertuars;

public:
    Theatre(vector<Hall> halls, vector<shared_ptr<Play>> plays, vector<shared_ptr<Worker>> workers);
    Repertuar create_random_repertuar();

};

#endif