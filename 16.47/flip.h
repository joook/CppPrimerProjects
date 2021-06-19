#ifndef _FLIP_H_
#define _FLIP_H_

#include <utility>
#include <iostream>

template <typename F, typename T, typename U>
void flip(F func, T&& para1, U&& para2)
{
    func(std::forward<U>(para2), std::forward<T>(para1));
}

// using this flip template, 
// you cannot calculate in the right way, if the func requires a ref-type parameter, 
// you cannot calculate at all, if the func requires a right-ref-type parameter
template <typename F, typename T, typename U>
void flipWithFlaw1(F func, T para1, U para2)
{
    func(para2, para1);
}

// using this flip template, 
// you cannot calculate at all, if the func requires a right-ref-type parameter, 
// or if the func requires a ref-type parameter while the argument is a const-ref-type
template <typename F, typename T, typename U>
void flipWithFlaw2(F func, T& para1, U& para2)
{
    func(para2, para1);
}

// using this flip template, 
// you cannot calculate at all, if the func requires a right-ref-type parameter
template <typename F, typename T, typename U>
void flipWithFlaw3(F func, T&& para1, U&& para2)
{
    func(para2, para1);
}

// assist functions
template <typename T, typename U>
void print2Args(T para1, U para2)
{
    std::cout << "arg1: " << para1 << std::endl;
    std::cout << "arg2: " << para2 << std::endl;
}

template <typename F, typename T, typename U>
void printFlip(F func, T&& para1, U&& para2)
{
    print2Args(para1, para2);

    flip(func, std::forward<T>(para1), std::forward<U>(para2));

    print2Args(para1, para2);
    std::cout << std::endl;
}

template <typename F, typename T, typename U>
void printFlipWithFlaw1(F func, T&& para1, U&& para2)
{
    print2Args(para1, para2);

    flipWithFlaw1(func, std::forward<T>(para1), std::forward<U>(para2));

    print2Args(para1, para2);
    std::cout << std::endl;
}

template <typename F, typename T, typename U>
void printFlipWithFlaw2(F func, T&& para1, U&& para2)
{
    print2Args(para1, para2);

    flipWithFlaw2(func, std::forward<T>(para1), std::forward<U>(para2));

    print2Args(para1, para2);
    std::cout << std::endl;
}

template <typename F, typename T, typename U>
void printFlipWithFlaw3(F func, T&& para1, U&& para2)
{
    print2Args(para1, para2);

    flipWithFlaw3(func, std::forward<T>(para1), std::forward<U>(para2));

    print2Args(para1, para2);
    std::cout << std::endl;
}

#endif

