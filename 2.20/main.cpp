#include <iostream>

int main()
{
    int a = 4;
    int *p = &a;
    *p = *p**p;
    std::cout << "a = " << a << std::endl;

    return 0;
}
