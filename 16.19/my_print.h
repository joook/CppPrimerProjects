#ifndef _MY_PRINT_H_
#define _MY_PRINT_H_

#include <iostream>

template <typename T>
void print(const T& container)
{
/*
    for (typename T::size_type i = 0; i != container.size(); i++)
    {
        std::cout << container.at(i) << " ";
    }
*/
    for (typename T::const_iterator itr = container.begin(); itr != container.end(); itr++)
    {
        std::cout << *itr << " ";
    }
}

#endif
