#include <iostream>

#include "flip.h"

void func1(int para1, int para2)
{
    std::cout << "para1: " << para1;
    std::cout << ", after add: " << ++para1 << std::endl;
    std::cout << "para2: " << para2;
    std::cout << ", after minus: " << --para2 << std::endl;
}

void func2(const int para1, int para2)
{
    std::cout << "para1: " << para1 << std::endl;
    std::cout << "para2: " << para2;
    std::cout << ", after minus: " << --para2 << std::endl;
}

void func3(int& para1, int para2)
{
    std::cout << "para1: " << para1;
    std::cout << ", after add: " << ++para1 << std::endl;
    std::cout << "para2: " << para2;
    std::cout << ", after minus: " << --para2 << std::endl;
}

void func4(const int& para1, int para2)
{
    std::cout << "para1: " << para1 << std::endl;
    std::cout << "para2: " << para2;
    std::cout << ", after minus: " << --para2 << std::endl;
}

void func5(int&& para1, int para2)
{
    std::cout << "para1: " << para1;
    std::cout << ", after add: " << ++para1 << std::endl;
    std::cout << "para2: " << para2;
    std::cout << ", after minus: " << --para2 << std::endl;
}

void func6(const int&& para1, int para2)
{
    std::cout << "para1: " << para1 << std::endl;
    std::cout << "para2: " << para2;
    std::cout << ", after minus: " << --para2 << std::endl;
}

int main(int argc, char* argv[])
{
    const int arg1 = 1;
    int arg2 = 2;
    int& arg3 = arg2;
    const int& arg4 = arg2;

    // test using arg1 & arg2
    flip(func1, arg1, arg2);
    flip(func2, arg1, arg2);
    flip(func3, arg1, arg2);
    flip(func4, arg1, arg2);
    flip(func5, arg1, 42);
    flip(func6, arg1, 42);

    // test using arg1 & arg3
    flip(func1, arg1, arg3);
    flip(func2, arg1, arg3);
    flip(func3, arg1, arg3);
    flip(func4, arg1, arg3);

    // test using arg1 & arg4
    flip(func1, arg1, arg4);
    flip(func2, arg1, arg4);
    flip(func4, arg1, arg4);

    return 0;
}
