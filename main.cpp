#include <iostream>
#include <sstream>
#include "data.h"
#include "play.h"
#include "hall.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cerr << "Incorrect number of command line arguments, expected 2, got " << argc - 1 << endl;
    }
    string path1, path2;

    stringstream stream;

    stream << argv[1];
    stream >> path1;
    stream.clear();

    stream << argv[2];
    stream >> path2;
    stream.clear();

    vector<Hall> halls;
    vector<Play> plays;
    vector<Comedy> comedies;
    vector<Drama> dramas;
    vector<Tragedy> tragedies;
    Data data(halls, plays, comedies, dramas, tragedies);

    data.read_halls(path1);
    data.read_plays(path2);

    cout << data.halls_size();
    cout << data.plays_size();
    cout << data.comedies_size();
    cout << data.dramas_size();
    cout << data.tragedies_size();
}

// int main()
// {
//     // string path1 = "C:\Users\kamil\OneDrive\Pulpit\PROI\teatr\halls.txt";
//     string path1 = "halls.txt";
//     string path2 = "plays.txt";
//     // string path2 = "C:\Users\kamil\OneDrive\Pulpit\PROI\teatr\plays.txt";
//     vector<Hall> halls;
//     vector<Play> plays;
//     Data data(halls, plays);
//     data.read(path1);
//     data.read(path2);

//     cout << data.halls_size();
// }
