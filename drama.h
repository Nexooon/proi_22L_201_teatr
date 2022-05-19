#ifndef drama
#define drama

#include <iostream>
#include "play.h"

using namespace std;

class Drama : public Play
{
    string main_drama_thread;

public:
    Drama(string title, unsigned int price = 80, unsigned int duration = 120, string main_drama_thread = "murder");

    string get_main_drama_thread();

    void set_main_drama_thread(string new_main_drama_thread);

    friend std::ostream &operator<<(std::ostream &os, const Drama &dramaa);
};

std::ostream &operator<<(std::ostream &os, const Drama &dramaa);

#endif