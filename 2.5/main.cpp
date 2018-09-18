#include <iostream>

int main()
{
    std::cout << "*" << 'a' << "*" << std::endl;
    std::cout << "*" << L'a' << "*" << std::endl;
    std::cout << "*" << "a" << "*" << std::endl;
    std::cout << "*" << L"a" << "*" << std::endl;

    std::cout << "*" << -10u << "*" << std::endl;
    return 0;
}
