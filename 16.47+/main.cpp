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

void printFlip()
{
}

int main(int argc, char* argv[])
{
    const int arg1 = 1;
    int arg2 = 2;
    int& arg3 = arg2;
    const int& arg4 = arg2;

    // test using arg1 & arg2
    printFlip(func1, arg1, arg2);
    printFlip(func2, arg1, arg2);
    printFlip(func3, arg1, arg2);
    printFlip(func4, arg1, arg2);
    printFlip(func5, arg1, 42);
    printFlip(func6, arg1, 42);

    // test using arg1 & arg3
    printFlip(func1, arg1, arg3);
    printFlip(func2, arg1, arg3);
    printFlip(func3, arg1, arg3);
    printFlip(func4, arg1, arg3);

    // test using arg1 & arg4
    printFlip(func1, arg1, arg4);
    printFlip(func2, arg1, arg4);
    //printFlip(func3, arg1, arg4); // cannot compile
    printFlip(func4, arg1, arg4);

    // test flipWithFlaw1
    printFlipWithFlaw1(func3, arg1, arg2); // calculate error
    //printFlipWithFlaw1(func5, arg1, arg2); // cannot compile
    //printFlipWithFlaw1(func6, arg1, arg2); // cannot compile

    // test flipWithFlaw2
    printFlipWithFlaw2(func3, arg1, arg2); // calculate right
    //printFlipWithFlaw2(func5, arg1, arg2); // cannot compile
    //printFlipWithFlaw2(func6, arg1, arg2); // cannot compile

    // test flipWithFlaw3
    printFlipWithFlaw3(func3, arg1, arg2); // calculate right
    //printFlipWithFlaw3(func5, arg1, arg2); // cannot compile
    //printFlipWithFlaw3(func6, arg1, arg2); // cannot compile

    return 0;
}
