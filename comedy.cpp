#include <iostream>
#include "comedy.h"
#include "play.h"

using namespace std;

Comedy::Comedy(string t, unsigned int p = 100, unsigned int d = 120, unsigned int nfs = 5) : Play(t, p, d)
{
    set_nfunny_scenes(nfs);
}

unsigned int Comedy::get_nfunny_scenes()
{
    return nfunny_scenes;
}

void Comedy::set_nfunny_scenes(unsigned int new_nfunny_scens)
{
    if (new_nfunny_scens == 0)
    {
        throw invalid_argument("Number of funny scenes must be a posiive number!");
    }
    else
        nfunny_scenes = new_nfunny_scens;
}

std::ostream &operator<<(std::ostream &os, const Comedy &comedyy)
{
    os << "Title: " << comedyy.title << endl
       << "Price: " << comedyy.price << endl
       << "Duration" << comedyy.duration << endl
       << "Number of funny scenes: " << comedyy.nfunny_scenes << endl;
    return os;
}