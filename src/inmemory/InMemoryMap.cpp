//
// Created by kyle on 23/02/2021.
//

#include "InMemoryMap.h"
#include "../exception/NotEnoughMemoryException.h"

namespace kt
{
    /**
     * Initialise a new instance of InMemoryMap. This will create an internal memory of the desired capacity.
     * Once initialised, the memory is initialised to zero.
     *
     * @param maxCapacity the desired maximum capacity of the memory map
     */
    InMemoryMap::InMemoryMap(const size_t& maxCapacity): maxCapacity(maxCapacity), consumedSize(0)
    {
        this->array = std::unique_ptr<unsigned char[]>(new unsigned char [maxCapacity]);
        // Initialise allocated memory to 0
        for (size_t i = 0; i < this->getMaxCapacity(); i++)
        {
            this->array[i] = static_cast<unsigned char>('\0');
        }
    }

    /**
     * Get the maximum capacity that was declared when the MemoryMap was initialised.
     *
     * @return the maximum capacity that this structure can hold in bytes
     */
    size_t InMemoryMap::getMaxCapacity() const
    {
        return this->maxCapacity;
    }

    /**
     * Get the remaining capacity available in the MemoryMap.
     *
     * @return the remaining capacity that this structure can hold in bytes
     */
    size_t InMemoryMap::getRemainingCapacity() const
    {
        return this->getMaxCapacity() - this->getConsumedCapacity();
    }

    /**
     * Get the amount of consumed memory in the MemoryMap.
     *
     * @return the consumed amount of memory that is unavailable in the structure in bytes
     */
    size_t InMemoryMap::getConsumedCapacity() const
    {
        return this->consumedSize;
    }
}
