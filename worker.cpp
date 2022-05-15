#include "worker.h"
#include "invalid_day_exception.h"
#include <iostream>
using namespace std;

Worker::Worker(string new_name, string new_obligation)
{
    obligation = new_obligation;
    name = new_name;
    set_schedule();
}

void Worker::set_schedule()
{
    weekly_schedule["Monday"] = "8:00 - 16:00";
    weekly_schedule["Tuesday"] = "8:00 - 16:00";
    weekly_schedule["Wednesday"] = "8:00 - 16:00";
    weekly_schedule["Thursday"] = "8:00 - 16:00";
    weekly_schedule["Friday"] = "8:00 - 16:00";
}

void Worker::set_name(string new_name)
{
    name = new_name;
}

void Worker::set_obligation(string new_obligation)
{
    obligation = new_obligation;
}

void Worker::print_schedule()
{
    cout << "Monday: " << weekly_schedule["Monday"] << endl;
    cout << "Tuesday: " << weekly_schedule["Tuesday"] << endl;
    cout << "Wednesday: " << weekly_schedule["Wednesday"] << endl;
    cout << "Thursday: " << weekly_schedule["Thursday"] << endl;
    cout << "Friday: " << weekly_schedule["Friday"] << endl;
}

void Worker::modify_schedule(string d, string h)
{
    if (d != "Monday" && d != "Tuesday" && d != "Wednesday" && d != "Thursday" && d != "Friday")
        throw InvalidDayException(d);
    weekly_schedule[d] = h;
}

Worker::~Worker() {}

string Worker::get_name() const
{
    return name;
}

string Worker::get_obligation() const
{
    return obligation;
}

string Worker::get_day_hours(string d)
{
    return weekly_schedule[d];
}

ostream& operator<<(ostream& os, const Worker& wor)
{
    os << "Worker: " << wor.name << " " << wor.obligation << "\n";
    return os;
}
