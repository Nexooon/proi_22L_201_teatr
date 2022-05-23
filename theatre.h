#ifndef __theatre
#define __theatre

#include <iostream>
#include <vector>
#include "data.h"
#include "hall.h"
#include "play.h"
#include "repertuar.h"

using namespace std;

class Theatre
{
    Data *data;
    vector<Repertuar> repertuars;

public:
    Theatre(Data &data);
    ~Theatre();

    Repertuar create_repertuar();
    void buy_a_ticket();
};

#endif