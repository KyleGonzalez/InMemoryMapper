//
// Created by kyle on 23/02/2021.
//

#ifndef INMEMORYMAP_INMEMORYMAP_H
#define INMEMORYMAP_INMEMORYMAP_H

#include <array>
#include <memory>
#include <unordered_map>
#include <algorithm>

class InMemoryMap
{
private:
    std::unique_ptr<unsigned char[]> array;
    std::unordered_map<unsigned char*, size_t> tracker;
    size_t totalSize;
    size_t consumedSize;

public:
    const static unsigned int BYTE = 1;
    const static unsigned int KILO_BYTE = 1024 * BYTE;
    const static unsigned int MEGA_BYTE = KILO_BYTE * KILO_BYTE;
    const static unsigned int GIGA_BYTE = MEGA_BYTE * KILO_BYTE;

    explicit InMemoryMap(size_t);
    ~InMemoryMap();

    size_t size() const;

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
    T* allocate(unsigned int size)
    {
        size_t sizePerValue = sizeof(T);
        size_t amountToAllocate = sizePerValue * size;
        size_t spaceRemaining = this->size() - consumedSize;

        if (spaceRemaining >= amountToAllocate)
        {
            size_t max = 0;
            for_each(tracker.begin(), tracker.end(), [&max](std::pair<unsigned char*, size_t> entry)
            {
                if (max < entry.second)
                {
                    max = entry.second;
                }
            });

            if (max + amountToAllocate > this->size())
            {
                // Need to shuffle memory
                throw std::runtime_error("Not enough continuous memory, need to shuffle");
            }

            consumedSize+= size;
            tracker.insert({ &array[max], size });
            return (T*) &array[max];
        }
        return nullptr;
    }
};

#endif //INMEMORYMAP_INMEMORYMAP_H
