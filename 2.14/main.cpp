#include <iostream>

int i = 999999, sum = 0;
int main()
{
    int i = 555;
    for(i = 0; i != 10; i++)
        sum += i;
    std::cout << i << " " << ::i << " " << sum << std::endl;
    return 0;
}
