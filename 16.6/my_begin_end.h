#ifndef _MY_BEGIN_END_H_
#define _MY_BEGIN_END_H_

#include <cstdint>

template <typename T, size_t N>
T* myBegin(T (&someArray)[N])
{
    return someArray;
}

template <typename T, size_t N>
T* myEnd(T (&someArray)[N])
{
    return someArray+N;
}

#endif
