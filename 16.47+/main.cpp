#include <iostream>
#include <string>

#include "pass.h"

#define TRACE (std::cout << "[" << __FILE__ << ": " << __FUNCTION__  << "] ")

void func1(int arg)
{
    TRACE << "Do self plus, inside the func, arg = " << ++arg << std::endl;
}

void func2(const int arg)
{
    TRACE << "Const arg cannot do self plus." << std::endl;
}

void func3(int& arg)
{
    TRACE << "Do self plus, inside the func, arg = " << ++arg << std::endl;
}

void func4(const int& arg)
{
    TRACE << "Const arg cannot do self plus." << std::endl;
}

void func5(int&& arg)
{
    TRACE << "Do self plus, inside the func, arg = " << ++arg << std::endl;
}

void func6(const int&& arg)
{
    TRACE << "Const arg cannot do self plus." << std::endl;
}

template <typename F, typename T>
void passHelper(F func, T&& arg)
{
    TRACE << "Before processed, " << "arg = " << arg << std::endl;
    pass(func, std::forward<T>(arg));
    TRACE << "After processed, " << "arg = " << arg << std::endl << std::endl;
}

template <typename F, typename T>
void passWithFlaw1Helper(F func, T&& arg)
{
    TRACE << "Before processed, " << "arg = " << arg << std::endl;
    passWithFlaw1(func, std::forward<T>(arg));
    TRACE << "After processed, " << "arg = " << arg << std::endl << std::endl;
}

template <typename F, typename T>
void passWithFlaw2Helper(F func, T&& arg)
{
    TRACE << "Before processed, " << "arg = " << arg << std::endl;
    passWithFlaw2(func, std::forward<T>(arg));
    TRACE << "After processed, " << "arg = " << arg << std::endl << std::endl;
}

template <typename F, typename T>
void passWithFlaw3Helper(F func, T&& arg)
{
    TRACE << "Before processed, " << "arg = " << arg << std::endl;
    passWithFlaw3(func, std::forward<T>(arg));
    TRACE << "After processed, " << "arg = " << arg << std::endl << std::endl;
}

int main()
{
    int arg1 = 100;
    const int arg2 = 200;
    int& arg3 = arg1;
    const int& arg4 = arg1;

/*
    // test using lvalue
    passHelper(func1, arg1);
    passHelper(func2, arg1);
    passHelper(func3, arg1);
    passHelper(func4, arg1);
    //passHelper(func5, arg1); // cannot compile, normal
    //passHelper(func6, arg1); // cannot compile, normal

    // test using const-lvalue
    passHelper(func1, arg2);
    passHelper(func2, arg2);
    //passHelper(func3, arg2); // cannot compile, normal
    passHelper(func4, arg2);
    //passHelper(func5, arg2); // cannot compile, normal
    //passHelper(func6, arg2); // cannot compile, normal

    // test using ref-of-lvalue
    passHelper(func1, arg3);
    passHelper(func2, arg3);
    passHelper(func3, arg3);
    passHelper(func4, arg3);
    //passHelper(func5, arg3); // cannot compile, normal
    //passHelper(func6, arg3); // cannot compile, normal

    // test using const-ref-of-lvalue
    passHelper(func1, arg4);
    passHelper(func2, arg4);
    //passHelper(func3, arg4); // cannot compile, normal
    passHelper(func4, arg4);
    //passHelper(func5, arg4); // cannot compile, normal
    //passHelper(func6, arg4); // cannot compile, normal
*/

    // test using rvalue
    passHelper(func1, 42);
    passHelper(func2, 42);
    //passHelper(func3, 42); // cannot compile, normal
    passHelper(func4, 42);
    passHelper(func5, 42); // rvalue is not necessarily const
    passHelper(func6, 42);

/*
    // test passWithFlaw1
    passWithFlaw1Helper(func3, arg1); // calculate error, flaw
    //passWithFlaw1Helper(func5, 42); // cannot compile, flaw
    //passWithFlaw1Helper(func6, 42); // cannot compile, flaw

    // test passWithFlaw2
    //passWithFlaw2Helper(func3, arg2); // cannot compile, flaw
    //passWithFlaw2Helper(func5, 42); // cannot compile, flaw
    //passWithFlaw2Helper(func6, 42); // cannot compile, flaw

    // test passWithFlaw3
    //passWithFlaw3Helper(func3, arg2); // cannot compile, flaw
    //passWithFlaw3Helper(func5, 42); // cannot compile, flaw
    //passWithFlaw3Helper(func6, 42); // cannot compile, flaw
*/
    return 0;
}
