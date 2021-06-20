#ifndef _GET_COUNT_H_
#define _GET_COUNT_H_

#include <cstring>
#include <vector>
#include <iostream>

template <typename T, typename Itr>
size_t getCount(const T& value, Itr itrBeg, Itr itrEnd)
{
    std::cout << "Template default instantiation called." << std::endl;

    size_t count = 0;
    for (; itrBeg != itrEnd; itrBeg++)
    {
        if (*itrBeg == value)
        {
            count++;
        }
        else
        {
            // do nothing
        }
    }
    return count;
}

template <>
size_t getCount(const char* const& value, std::vector<const char*>::iterator itrBeg
    , std::vector<const char*>::iterator itrEnd)
{
    std::cout << "Template special instantiation called." << std::endl;

    size_t count = 0;
    for (; itrBeg != itrEnd; itrBeg++)
    {
        if (strcmp(*itrBeg, value) == 0)
        {
            count++;
        }
        else
        {
            // do nothing
        }
    }
    return count;
}

#endif

