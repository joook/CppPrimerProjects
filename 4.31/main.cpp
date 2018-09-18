#include <iostream>

int main()
{
    int j = 0, k = 0;
    for(int i = 0; i != 1; ++i)
    {
        j++;
    }
    std::cout << "j = " << j << std::endl;
    for(int i = 0; i != 1; i++)
    {
        k++;
    }
    std::cout << "k = " << k << std::endl;

    return 0;
}
