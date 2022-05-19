// Kamil Kulak

#ifndef __DEFINICJE_HPP__
#define __DEFINICJE_HPP__

#include <iostream>

using namespace std;
class Date
{
    int day, month, year;
    enum Month
    {
        january = 1,
        february,
        march,
        april,
        may,
        june,
        july,
        august,
        september,
        october,
        november,
        december,
    };

public:
    Date(int d = 1, int m = 1, int r = 2000);

    void show();

    int get_day();
    int get_month();
    int get_year();

    void set_day(int new_day);
    void set_month(int new_month);
    void set_year(int new_year);

    void check(int day, int month, int year);
};

#endif
