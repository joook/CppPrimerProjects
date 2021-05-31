#ifndef _MY_FIND_H_
#define _MY_FIND_H_

#include <iostream>

template <typename T, typename V>
T myFind(const T& itrBegin, const T& itrEnd, const V& value)
{
    T itr = itrBegin;
    while (itr != itrEnd)
    {
        if (*itr == value)
        {
            break;
        }
        else
        {
            // do nothing
        }

        itr++;
    }

    return itr;
}

template <typename T>
void myPrint(const T& itrBegin, const T& itrEnd)
{
    T itr = itrBegin;
    while (itr != itrEnd)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
}

#endif
