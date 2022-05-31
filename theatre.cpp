#include <iostream>
#include "play.h"
#include "comedy.h"
#include "drama.h"
#include "tragedy.h"
#include "hall.h"
#include "date.h"
#include "repertuar.h"
#include "theatre.h"
#include "worker.h"
#include "usher.h"
#include "data.h"

using namespace std;

// Theatre::Theatre(Data &data)
// {
//     data = &data;
// }

Theatre::~Theatre(){};

// Repertuar Theatre::create_repertuar()
// {
//     Hall hall = data->get_random_hall();
//     Repertuar rep(hall);
//     data->add_random_play_to_repertuar(rep);
//     return rep;
// }
// Theatre::~Theatre(){};

// create repertuar
// choose hall randomly and create repertuar,
//  then use method add_random_play_to_repertuar on data using this repertuar to add 2 plays,
//  at the end push it to the vector, return repertuar and print it

// Repertuar Theatre::create_repertuar()
// {
// }
