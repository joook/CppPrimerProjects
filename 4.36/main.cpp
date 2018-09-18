#include <iostream>

int main()
{
    int i = 4;
    double d = 5.5;
    std::cout << (i *= static_cast<int>(d)) << std::endl;

    return 0;
}
