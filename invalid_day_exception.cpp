#include "invalid_day_exception.h"
#include <string>

InvalidDayException::InvalidDayException(std::string wrong_day):
std::invalid_argument("Day is out of Mon-Fri range: " + wrong_day){}
