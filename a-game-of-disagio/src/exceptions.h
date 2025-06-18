#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

class IncoherentSizeException : public std::runtime_error {
public:
    IncoherentSizeException() : runtime_error("Incoherent Size Exception") {}
};

class UnknownPatternException : public std::runtime_error {
public:
    UnknownPatternException() : runtime_error("Unknown Pattern Exception") {}
};

class OutOfSchemaException : public std::runtime_error {
public:
    OutOfSchemaException() : runtime_error("Out of Schema Exception") {}
};

#endif //EXCEPTIONS_H
