#include <iostream>

int main()
{
    int i, j;
    int *p = &j;
    double d;

    *p = d = i = 10;

    std::cout << *p << d << i << std::endl;

    return 0;
}
