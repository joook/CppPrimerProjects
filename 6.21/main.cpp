#include <iostream>

int compare(int a, const int *p)
{
    return (a > *p ? a : *p);
}

int main()
{
    int a = 1;
    int b = 2;

    std::cout << compare(a, &b) << std::endl;

    return 0;
}
