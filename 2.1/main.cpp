#include <iostream>
#include "typedefine.h"
int main()
{
    u16 a = 65535;
    unsigned b = -1;
    int c = 0x25;
    char d = 'd';
    std::string e = "\t\115";
    u16 f = 65539u;
    u16 g = 10.9f;
    std::cout << "u16(65535) = " << a << std::endl;
    std::cout << "u8(-1) = " << b << std::endl;
    std::cout << "int(0x25) = " << c << std::endl;
    std::cout << "char('d') = " << d << std::endl;
    std::cout << "string(\"\\t\\115\") = " << e << std::endl;
    std::cout << "u16(65539u) = " << f << std::endl;
    std::cout << "u16(10.9f) = " << g << std::endl;
}
