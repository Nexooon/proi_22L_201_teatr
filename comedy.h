#ifndef comedy_h
#define comedy_h

#include <iostream>
#include "play.h"

using namespace std;

class Comedy : public Play
{
private:
    unsigned int nfunny_scenes;

public:
    Comedy(string title, unsigned int price, unsigned int duration, unsigned int nfunny_scenes);

    unsigned int get_nfunny_scenes();

    void set_nfunny_scenes(unsigned int new_nfunny_scenes);

    friend std::ostream &operator<<(std::ostream &os, const Comedy &comedyy);
};

std::ostream &operator<<(std::ostream &os, const Comedy &comedyy);

#endif