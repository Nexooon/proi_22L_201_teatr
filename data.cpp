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

void Data::read_halls(string path)
{
    fstream myfile;

    myfile.open(path, ios::in);

    if (myfile.good() == false)
    {
        throw invalid_argument("File does not exist!");
        exit(0);
    }

    string line;
    int nline = 0;
    int header;

    if (myfile.is_open())
    {

        while (getline(myfile, line))
        {
            if (nline == 0)
            {
                if (line == "halls")
                {
                    header = 1;
                }
                else if (line == "plays")
                {
                    header = 2;
                }
                else
                {
                    throw invalid_argument("Wrong header!");
                }
            }
            string tmp;
            string hall1, hall2, play1, play2, play3; // find better place for that
            // vector<Play> plays_vec;                   //
            // vector<Hall> hall_vec;                    //
            switch (header)
            {

                // halls

            case 1:
            {
                // for (int i=0; i< (int)line.length(), i++)
                // {
                //     if (line[i] == ' ')
                //     {

                //     }
                // }
                // string hall1, hall2;
                // vector<Hall> hall_vec;

                switch (nline)
                {
                case 2:
                    hall1 = line;
                    break;
                case 3:
                    hall2 = line;
                    break;
                }

                if (nline == 3)
                {
                    Hall hall_obj(stoi(hall1), stoi(hall2));
                    halls.push_back(hall_obj);
                    nline = 1;
                }
                nline++;
                break;
            }

                // plays

            case 2:
            {
                // string play1, play2, play3;
                // vector<Play> plays_vec;

                switch (nline)
                {
                case 2:
                    play1 = line;
                    break;
                case 3:
                    play2 = line;
                    break;
                case 4:
                    play3 = line;
                    break;
                }

                if (nline == 4)
                {

                    Play play_obj(play1, stoi(play2), stoi(play3));
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