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

Theatre::Theatre(Data &dataa, Date d)
{
    data = dataa;
    date = d;
}

Theatre::~Theatre(){};

// create repertuar
// choose hall randomly and create repertuar,
//  then use method add_random_play_to_repertuar on data using this repertuar to add 2 plays,
//  at the end push it to the vector, return repertuar and print it

Repertuar Theatre::create_random_repertuar()
{
    Hall hall = data.get_random_hall();
    Repertuar rep(hall);
    data.add_random_play_to_repertuar(rep);
    repertuars.push_back(rep);
    rep.print_repertuar();
    return rep;
}

void Theatre::simulation()
{
    for (int j = 0; j < 5; j++) // how many days
    {
        cout << "Today's date ";
        date.show();
        cout << endl
             << endl;
        for (int i = 0; i < 2; i++)
        {
            Repertuar repertuar = create_random_repertuar();
            data.buy_a_ticket(repertuar);
            repertuar.print_summary();
            cout << endl;
        }
        cout << endl;
        ++date;
    }
}