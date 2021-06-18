#ifndef _FLIP_H_
#define _FLIP_H_

#include <utility>
#include <iostream>

template <typename F, typename T, typename U>
void flip(F func, T&& para1, U&& para2)
{
    std::cout << "arg1: " << para1 << std::endl;
    std::cout << "arg2: " << para2 << std::endl;

    func(std::forward<U>(para2), std::forward<T>(para1));

    std::cout << "arg1: " << para1 << std::endl;
    std::cout << "arg2: " << para2 << std::endl;
    std::cout << std::endl;
}

#endif

