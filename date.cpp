#include <iostream>
#include "date.h"

using namespace std;

Date::Date(int d, int m, int r)
{
    check(d, m, r);
    day = d;
    month = m;
    year = r;
}

void Date::show()
{
    cout << day << "." << month << "." << year << endl;
}

int Date::get_day()
{
    return day;
}

int Date::get_month()
{
    return month;
}

int Date::get_year()
{
    return year;
}

void Date::set_day(int new_day)
{
    check(new_day, month, year);
    day = new_day;
}

void Date::set_month(int new_month)
{
    check(day, new_month, year);
    month = new_month;
}

void Date::set_year(int new_year)
{
    check(day, month, new_year);
    year = new_year;
}

void Date::check(int day, int month, int year)
{
    int days_in_month;

    days_in_month = get_days_in_month(month);

    if (year < 1)
        throw invalid_argument("Invalid year!");
    if (month < 1 || month > 12)
        throw invalid_argument("Invalid month!");
    if (day < 1 || day > days_in_month)
        throw invalid_argument("Invalid day!");
}

Date &Date::operator++()
{
    day++;

    int days_in_current_month = get_days_in_month(month);

    if (day > days_in_current_month)
    {
        day = 1;
        month++;
    }
    if (month > 12)
    {
        month = 1;
        year++;
    }

    return *this;
}

int Date::get_days_in_month(int month)
{
    int days_in_month;

    switch (month)
    {
    case january:
    case march:
    case may:
    case july:
    case august:
    case october:
    case december:
        days_in_month = 31;
        break;
    case april:
    case june:
    case september:
    case november:
        days_in_month = 30;
        break;
    case february:
    {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
            days_in_month = 29;
        else
            days_in_month = 28;
        break;
    }
    }
    return days_in_month;
}