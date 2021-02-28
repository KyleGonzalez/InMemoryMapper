//
// Created by kyle on 23/02/2021.
//

#ifndef INMEMORYMAP_INMEMORYMAP_H
#define INMEMORYMAP_INMEMORYMAP_H

#include <array>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <typeinfo>
#include <iostream>

namespace kt
{
    class InMemoryMap
    {
    private:
        std::unique_ptr<unsigned char[]> array;
        std::unordered_map<unsigned char*, size_t> tracker;
        size_t maxCapacity;
        size_t consumedSize;

    public:

        /**
         * The amount of memory consumed by a single byte (1).
         */
        const static unsigned int BYTE = 1;

        /**
         * The amount of memory consumed by a single kilo byte.
         */
        const static unsigned int KILO_BYTE = 1024 * BYTE;

        /**
         * The amount of memory consumed by a single mega byte.
         */
        const static unsigned int MEGA_BYTE = KILO_BYTE * KILO_BYTE;

        /**
         * The amount of memory consumed by a single giga byte.
         */
        const static unsigned int GIGA_BYTE = MEGA_BYTE * KILO_BYTE;

        explicit InMemoryMap(const size_t&);
        ~InMemoryMap() = default;

        size_t getMaxCapacity() const;
        size_t getRemainingCapacity() const;
        size_t getConsumedCapacity() const;

        /**
         * Implementing this here for now since it is a template function.
         *
         * Allocate the request memory for the provided type and amount passed in.
         *
         * @tparam T type to allocate memory for
         * @param size amount of type T to allocate
         * @return a pointer to the allocated memory. Or null if there is not enough memory
         */
        template<typename T>
        T* allocate(const size_t& size)
        {
            const size_t sizePerValue = sizeof(T);
            const size_t amountToAllocate = sizePerValue * size;

            if (this->getRemainingCapacity() >= amountToAllocate)
            {
                size_t lastMemoryIndex = 0;
                for_each(this->tracker.begin(), this->tracker.end(), [&lastMemoryIndex](std::pair<unsigned char*, size_t> entry)
                {
                    if (lastMemoryIndex < entry.second)
                    {
                        lastMemoryIndex = entry.second;
                    }
                });

                if (lastMemoryIndex + amountToAllocate > this->getMaxCapacity())
                {
                    // Need to shuffle memory
                    throw std::runtime_error("Not enough continuous memory, need to shuffle");
                }

                this->consumedSize += amountToAllocate;
                this->tracker.insert({&this->array[lastMemoryIndex], amountToAllocate });
                return (T*) &this->array[lastMemoryIndex];
            }
            return nullptr;
        }
    };
}

#endif //INMEMORYMAP_INMEMORYMAP_H
