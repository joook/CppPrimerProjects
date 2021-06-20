#ifndef _PRINT_H_
#define _PRINT_H_

#include <iostream>

template <typename T>
void print(const T& container)
{
    for (auto item : container)
    {
        std::cout << item << " ";
    }

/*
    for (typename T::size_type i = 0; i != container.size(); i++)
    {
        std::cout << container.at(i) << " ";
    }
*/
/*
    for (typename T::const_iterator itr = container.begin(); itr != container.end(); itr++)
    {
        std::cout << *itr << " ";
    }
*/
}

#endif
