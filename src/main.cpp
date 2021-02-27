#include <iostream>
#include "inmemory/InMemoryMap.h"

int main()
{
    InMemoryMap map(InMemoryMap::BYTE * 79);

    int* x = map.allocate<int>(10);
    if (x != nullptr)
    {
        std::cout << "Capacity: " << map.getMaxCapacity() << std::endl;
        std::cout <<  "X: " << x[0] << std::endl;
        x[0] = 10;
        std::cout <<  "X: " << x[0] << std::endl;
    }
    else
    {
        std::cout << "X is null" << std::endl;
    }

    int* y = map.allocate<int>(10);
    if (y != nullptr)
    {
        std::cout << "Y: " << y[0] << std::endl;
    }
    else
    {
        std::cout << "Y is null" << std::endl;
    }

    return 0;
}
