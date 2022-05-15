#ifndef theatre
#define theatre

#include <iostream>
#include "data.h"
#include "hall.h"
#include "play.h"

using namespace std;

class Theatre
{
    Data *data;

public:
    Theatre(Data &data);
    ~Theatre();
};

#endif