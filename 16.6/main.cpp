#include <cstdint>

#include <iostream>
#include <string>

#include "my_begin_end.h"

int main(int argc, char* argv[])
{
    const std::int16_t array1[10] = {1, 2, 3};
    const std::string array2[20] = {"hello", ", ", "world", "!"};

    std::cout << "Array1: " << std::endl;
    for (auto itr = std::begin(array1); itr != std::end(array1); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    std::cout << "Array2: " << std::endl;
    for (auto itr = std::begin(array2); itr != std::end(array2); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    std::cout << "Using myBegin and myEnd, Array1: " << std::endl;
    for (auto itr = myBegin(array1); itr != myEnd(array1); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    std::cout << "Using myBegin and myEnd, Array2: " << std::endl;
    for (auto itr = myBegin(array2); itr != myEnd(array2); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    return 0;
}

