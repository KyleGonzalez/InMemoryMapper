//
// Created by Kyle on 24/02/2021.
//

#include "NotEnoughMemoryException.h"

NotEnoughMemoryException::NotEnoughMemoryException(std::string s): std::runtime_error(s) {}
