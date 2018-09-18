#include <iostream>

int main()
{
    const int a = 8;
    auto b = 2, c = 2.5;
    const auto d = &a;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    return 0;
}
