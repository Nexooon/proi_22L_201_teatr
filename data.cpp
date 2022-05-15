#include <iostream>
#include <fstream>
#include "data.h"
#include "hall.h"
#include "play.h"

using namespace std;

Data::Data(vector<Hall> h, vector<Play> p)
{
    halls = h;
    plays = p;
}

Data::Data(const Data *d)
{
    halls = d->halls;
    plays = d->plays;
}

Data::~Data(){};

void Data::read(string path)
{
    fstream myfile;

    myfile.open(path, ios::in);

    if (myfile.good() == false)
    {
        throw invalid_argument("File does not exist!");
        exit(0);
    }

    string line;
    int nline = 1;
    int header;
    string hall_obj_nr, hall_obj_seats, play_obj_title, play_obj_price, play_obj_time;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (nline == 1)
            {
                header = get_header(line);
                nline++;
                continue;
            }

            // cout << line << " its a line " << nline << endl;

            switch (header)
            {

                // halls

            case 1:
            {
                switch (nline)
                {
                case 2:
                    hall_obj_nr = line;
                    break;
                case 3:
                    hall_obj_seats = line;
                    break;
                }

                if (nline == 3)
                {
                    cout << hall_obj_nr << endl
                         << hall_obj_seats << endl;
                    // add_hall_obj(halls, hall_obj_nr, hall_obj_seats);
                    Hall hall_obj(stoi(hall_obj_nr), stoi(hall_obj_seats));
                    cout << hall_obj.get_number() << endl
                         << hall_obj.get_seats() << endl;
                    halls.push_back(hall_obj);
                    nline = 1;
                }
                nline++;
                break;
            }

                // plays

            case 2:
            {
                switch (nline)
                {
                case 2:
                    play_obj_title = line;
                    break;
                case 3:
                    play_obj_price = line;
                    break;
                case 4:
                    play_obj_time = line;
                    break;
                }

                if (nline == 4)
                {
                    // add_play_obj(plays, play_obj_title, play_obj_price, play_obj_time);
                    Play play_obj(play_obj_title, stoi(play_obj_price), stoi(play_obj_time));
                    plays.push_back(play_obj);
                    nline = 1;
                }
                nline++;
                break;
            }
            }
        }
        myfile.close();
    }
}

int Data::halls_size()
{
    return halls.size();
}

int Data::plays_size()
{
    return plays.size();
}

void add_hall_obj(vector<Hall> halls, string hnr, string hseats) // do poprawy
{
    cout << hnr << endl;
    cout << hseats << endl;

    Hall hall_obj(stoi(hnr), stoi(hseats));

    cout << hall_obj.get_number() << " nr" << endl;
    cout << hall_obj.get_seats() << " seats" << endl;

    halls.push_back(hall_obj);
}

void add_play_obj(vector<Play> plays, string title, string price, string time) // do poprawy
{
    Play play_obj(title, stoi(price), stoi(time));
    plays.push_back(play_obj);
}

int get_header(string line)
{
    if (line == "halls")
    {
        return 1;
    }
    else if (line == "plays")
    {
        return 2;
    }
    else
    {
        throw invalid_argument("Wrong header!");
    }
}