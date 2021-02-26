#include <iostream>
#include "inmemory/InMemoryMap.h"

int main()
{
    InMemoryMap map(InMemoryMap::BYTE * 20);

    char* x = map.allocate<char>(10);
    if (x != nullptr)
    {
        std::cout << "Size: " << map.size() << std::endl;
        std::cout <<  "X: " << x[0] << std::endl;
        x[0] = 'A';
        std::cout <<  "X: " << x[0] << std::endl;
    }
    else
    {
        std::cout << "X is null" << std::endl;
    }

    char* y = map.allocate<char>(10);
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
