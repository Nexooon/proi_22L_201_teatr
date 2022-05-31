#include <iostream>
#include "theatre.h"
#include "data.h"

using namespace std;

Theatre::Theatre(Data &d)
{
    data = &d;
}

Theatre::~Theatre(){};

// Repertuar Theatre::create_repertuar()
// {
//     Hall hall = data->get_random_hall();
//     Repertuar rep(hall);
//     data->add_random_play_to_repertuar(rep);
//     return rep;
// }
