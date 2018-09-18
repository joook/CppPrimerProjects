#include <iostream>

int main()
{
    signed int a = 12;
    unsigned int b = 20;
    std::cout << "(signed int)a - (unsigned int)b = " << a-b << std::endl;
    std::cout << "(unsigned int)b - (signed int)a = " << b-a << std::endl;
    signed short c = 12;
    unsigned short d = 20;
    std::cout << "(signed short)c - (unsigned short)d = " << c-d << std::endl;
    std::cout << "(unsigned short)d - (signed short)c = " << d-c << std::endl;
    return 0;
}
