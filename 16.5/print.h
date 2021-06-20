#ifndef _PRINT_H_
#define _PRINT_H_

#include <iostream>

template <typename T, signed N>
void print(const T (&someArray)[N])
{
/*
    auto i = 0;
    while (i != N)
    {
        std::cout << someArray[i] << " ";
        i++;
    }
*/
    for (auto item : someArray)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

#endif
