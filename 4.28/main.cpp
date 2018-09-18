#include <iostream>

int main()
{
    int a;
    short b;
    long c;
    long long d;
    char e;
    float f;
    double g;
    long double h;
    bool i;
    int *j;
    double *k;
    std::cout << "Size of int: " << sizeof a << std::endl;
    std::cout << "Size of short: " << sizeof b << std::endl;
    std::cout << "Size of long: " << sizeof c << std::endl;
    std::cout << "Size of long long: " << sizeof d << std::endl;
    std::cout << "Size of char: " << sizeof e << std::endl;
    std::cout << "Size of float: " << sizeof f << std::endl;
    std::cout << "Size of double: " << sizeof g << std::endl;
    std::cout << "Size of long double: " << sizeof h << std::endl;
    std::cout << "Size of bool: " << sizeof i << std::endl;
    std::cout << "Size of *int: " << sizeof j << std::endl;
    std::cout << "Size of *double: " << sizeof k << std::endl;
    return 0;
}
