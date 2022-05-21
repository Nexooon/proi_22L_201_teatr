#include <iostream>
#include <fstream>
#include "data.h"
#include "hall.h"
#include "play.h"
#include "comedy.h"

using namespace std;

Data::Data(vector<Hall> h, vector<Play> p, vector<Comedy> c, vector<Drama> d, vector<Tragedy> t)
{
    halls = h;
    plays = p;
    comedies = c;
    dramas = d;
    tragedies = t;
}

Data::Data(const Data *d)
{
    halls = d->halls;
    plays = d->plays;
}

Data::~Data(){};

void Data::read_halls(string path)
{
    fstream file;
    file.open(path, ios::in);

    if (file.good() == false)
    {
        throw invalid_argument("File does not exist!");
        exit(0);
    }
    string nr, seats;
    while (file >> nr)
    {
        file >> seats;
        Hall hall_obj(stoi(nr), stoi(seats));
        halls.push_back(hall_obj);
    }
    file.close();
}

void Data::read_plays(string path)
{
    fstream file;
    file.open(path, ios::in);

    if (file.good() == false)
    {
        throw invalid_argument("File does not exist!");
        exit(0);
    }
    string title, duration, price, type, nfunny_scenes, drama_thread, tragic_ch_name;
    while (file >> title)
    {
        file >> duration;
        file >> price;
        file >> type;

        if (type == "1")
        {
            Play play_obj(title, stoi(price), stoi(duration));
            plays.push_back(play_obj);
        }
        if (type == "2")
        {
            file >> nfunny_scenes;
            Comedy comedy_obj(title, stoi(price), stoi(duration), stoi(nfunny_scenes));
            comedies.push_back(comedy_obj);
        }
        if (type == "3")
        {
            file >> drama_thread;
            Drama drama_obj(title, stoi(price), stoi(duration), drama_thread);
            dramas.push_back(drama_obj);
        }
        if (type == "4")
        {
            file >> tragic_ch_name;
            Tragedy tragedy_obj(title, stoi(price), stoi(duration), tragic_ch_name);
            tragedies.push_back(tragedy_obj);
        }
    }
    file.close();
}

int Data::halls_size()
{
    return halls.size();
}

int Data::plays_size()
{
    return plays.size();
}

int Data::comedies_size()
{
    return comedies.size();
}

int Data::dramas_size()
{
    return dramas.size();
}

int Data::tragedies_size()
{
    return tragedies.size();
}

// void Data::read(string path)
// {
//     fstream myfile;

//     myfile.open(path, ios::in);

//     if (myfile.good() == false)
//     {
//         throw invalid_argument("File does not exist!");
//         exit(0);
//     }

//     string line;
//     int nline = 1;
//     int header;
//     string hall_obj_nr, hall_obj_seats, play_obj_title, play_obj_price, play_obj_time;

//     if (myfile.is_open())
//     {
//         while (getline(myfile, line))
//         {
//             if (nline == 1)
//             {
//                 header = get_header(line);
//                 nline++;
//                 continue;
//             }

//             switch (header)
//             {

//                 // halls

//             case 1:
//             {
//                 switch (nline)
//                 {
//                 case 2:
//                     hall_obj_nr = line;
//                     break;
//                 case 3:
//                     hall_obj_seats = line;
//                     break;
//                 }

//                 if (nline == 3)
//                 {

//                     add_hall_obj(halls, hall_obj_nr, hall_obj_seats);
//                     // Hall hall_obj(stoi(hall_obj_nr), stoi(hall_obj_seats));
//                     // halls.push_back(hall_obj);
//                     nline = 1;
//                 }
//                 nline++;
//                 break;
//             }

//                 // plays

//             case 2:
//             {
//                 switch (nline)
//                 {
//                 case 2:
//                     play_obj_title = line;
//                     break;
//                 case 3:
//                     play_obj_price = line;
//                     break;
//                 case 4:
//                     play_obj_time = line;
//                     break;
//                 }

//                 if (nline == 4)
//                 {
//                     add_play_obj(plays, play_obj_title, play_obj_price, play_obj_time);
//                     // Play play_obj(play_obj_title, stoi(play_obj_price), stoi(play_obj_time));
//                     // plays.push_back(play_obj);
//                     nline = 1;
//                 }
//                 nline++;
//                 break;
//             }
//             }
//         }
//         myfile.close();
//     }
// }

// void add_hall_obj(vector<Hall> halls, string hnr, string hseats)
// {
//     Hall hall_obj(stoi(hnr), stoi(hseats));
//     halls.push_back(hall_obj);
// }

// void add_play_obj(vector<Play> plays, string title, string price, string time)
// {
//     Play play_obj(title, stoi(price), stoi(time));
//     plays.push_back(play_obj);
// }

// int get_header(string line)
// {
//     if (line == "halls")
//     {
//         return 1;
//     }
//     else if (line == "plays")
//     {
//         return 2;
//     }
//     else
//     {
//         throw invalid_argument("Wrong header!");
//     }
// }
