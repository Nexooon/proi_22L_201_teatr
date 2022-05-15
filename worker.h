#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include <string>
#include <map>

using namespace std;


class Worker
{
    protected:
        string name;
        string obligation;
        map<string, string> weekly_schedule;

    public:
        Worker(string name, string obligation);
        virtual void set_schedule();

        void set_name(string new_name);
        void set_obligation(string new_obligation);
        void print_schedule();
        void modify_schedule(string day, string hours);

        virtual ~Worker();

        string get_name() const;
        string get_obligation() const;
        string get_day_hours(string day);

        friend ostream& operator<<(ostream& os, const Worker& work);
};

ostream& operator<<(ostream& os, const Worker& work);

#endif
