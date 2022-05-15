#ifndef INVALID_DAY_EXCEPTION_H
#define INVALID_DAY_EXCEPTION_H
#include <stdexcept>
#include <string>

class InvalidDayException : public std::invalid_argument
{
    public:
        InvalidDayException(std::string wrong_day);

};

#endif