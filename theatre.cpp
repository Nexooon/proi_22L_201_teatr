#include <iostream>
#include "theatre.h"
#include "data.h"

using namespace std;

Theatre::Theatre(Data &d)
{
    data = &d;
}

Theatre::~Theatre(){};