#include <iostream>

int main()
{
    int i(3.14);
    int j{3.14};
    int k = 3.14;
    int l = {3.14};
    std::cout << "i = " << i << std::endl;
    std::cout << "j = " << j << std::endl;
    std::cout << "k = " << k << std::endl;
    std::cout << "l = " << l << std::endl;

    int n;
    int m = n = 1;
    std::cout << "m = " << m << std::endl;
    std::cout << "n = " << n << std::endl;

    bool opt;
    bool p = opt;
    std::cout << "p = " << p << std::endl;

    std::cin >> int qqq;

    return 0;
}
