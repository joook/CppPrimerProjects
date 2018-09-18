#include <iostream>

int main()
{
    int i = 15, &j = i;
    j = 16;
    std::cout << "i = " << i << std::endl;
    int &k = j;
    k = 17;
    std::cout << "i = " << i << std::endl;
    std::cout << "j = " << j << std::endl;
    i = 18;
    std::cout << "j = " << j << std::endl;
    std::cout << "k = " << k << std::endl;

    double l = 6.66, &m = l;
    k = m;
    std::cout << "j = " << j << std::endl;
    std::cout << "k = " << k << std::endl;

    return 0; 
}
