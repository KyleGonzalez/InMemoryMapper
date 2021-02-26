//
// Created by Kyle on 24/02/2021.
//

#ifndef INMEMORYMAP_NOTENOUGHMEMORYEXCEPTION_H
#define INMEMORYMAP_NOTENOUGHMEMORYEXCEPTION_H

#include <exception>
#include <string>
#include <stdexcept>

class NotEnoughMemoryException: public std::runtime_error
{
public:
    explicit NotEnoughMemoryException(std::string);
};

#endif //INMEMORYMAP_NOTENOUGHMEMORYEXCEPTION_H
