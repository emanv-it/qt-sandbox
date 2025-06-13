#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

class OutOfSchema : public std::out_of_range
{
    public:
        OutOfSchema(): out_of_range("Out of Schema Exception") {}
};

#endif // EXCEPTIONS_H
