#include <iostream>

int main()
{
    const int a = 3;
    const auto &b = a;
    const auto *c = &a;
    std::cout << a << std::endl << b << std::endl << c << std::endl;

    return 0;
}
