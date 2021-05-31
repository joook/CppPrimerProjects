#include <cstdint>

#include <iostream>
#include <string>

#include "my_print.h"

int main(int argc, char* argv[])
{
    std::int16_t array1[10] = {1, 2, 3};
    std::string array2[20] = {"hello", ", ", "world", "!"};

    std::cout << "Array1: " << std::endl;
    myPrint(array1);
    std::cout << "Array2: " << std::endl;
    myPrint(array2);

    return 0;
}

