#include <iostream>
int main()
{
    int a = 8;
    const int &b = a;
    a = 6;
    std::cout << "b = " << b << std::endl;

    const int &d = 42;
    std::cout << "d = " << d << std::endl;

    return 0;
}
