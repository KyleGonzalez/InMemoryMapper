//
// Created by kyle on 23/02/2021.
//

#include "InMemoryMap.h"
#include "../exception/NotEnoughMemoryException.h"

InMemoryMap::InMemoryMap(size_t size): totalSize(size), consumedSize(0)
{
    array = std::unique_ptr<unsigned char[]>(new unsigned char [size]);
    // Initialise Memory to 0
    for (size_t i = 0; i < size; i++)
    {
        array[i] = static_cast<unsigned char>('\0');
    }
}

InMemoryMap::~InMemoryMap() = default;

size_t InMemoryMap::size() const
{
    return totalSize;
}
