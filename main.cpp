#include <iostream>
#include <sstream>
#include "data.h"
#include "theatre.h"
#include "data.h"
#include "play.h"
#include "comedy.h"
#include "drama.h"
#include "tragedy.h"
#include "hall.h"
#include "date.h"
#include "repertuar.h"
#include "worker.h"
#include "usher.h"
#include "person.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cerr << "Incorrect number of command line arguments, expected 4, got " << argc - 1 << endl;
    }
    string path1, path2, path3, path4;

    stringstream stream;

    stream << argv[1];
    stream >> path1;
    stream.clear();

    stream << argv[2];
    stream >> path2;
    stream.clear();

    stream << argv[3];
    stream >> path3;
    stream.clear();

    stream << argv[4];
    stream >> path4;
    stream.clear();

    vector<Hall> halls;
    vector<shared_ptr<Play>> plays;
    vector<shared_ptr<Worker>> workers;
    vector<Person> people;
    Data data(halls, plays, workers, people);

    Date date(1, 5, 2010);
    ++date;

    data.read_halls(path1);
    data.read_plays(path2);
    data.read_workers(path3);
    data.read_people(path4);

    // Hall hall(1, 50, 0);
    // Repertuar repertuar(hall);

    // repertuar.print_repertuar();
    // data.add_random_play_to_repertuar(repertuar);
    // repertuar.print_repertuar();

    Theatre theatre(data, date);

    theatre.simulation();
}
