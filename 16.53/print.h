#ifndef _PRINT_H_
#define _PRINT_H_

#include <iostream>
#include <typeinfo>

template <typename T>
void print(const T& t)
{
    // to see a readable type, you need to run the executable like this: "./test | c++filt -t"
    std::cout << "Type of arg is: " << typeid(T).name() << std::endl;
    std::cout << "Value of arg is: " << t << std::endl;
}

template <typename T, typename... Args>
void print(const T& t, const Args&... args)
{
    std::cout << "Type of arg is: " << typeid(T).name() << std::endl;
    std::cout << "Value of arg is: " << t << std::endl;
    print(args...);
}

#endif

