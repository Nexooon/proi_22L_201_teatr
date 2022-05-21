#include "reduced_ticket_student.h"
#include <iostream>
using namespace std;

int ReducedTicketStudent::calculate_price() const
{
    return 0.75 * base_price;
}
