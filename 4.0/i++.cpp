#include <iostream>

int preAdd(int &k)
{
    k = k+1;
    return k;
}

int postAdd(int &i)
{
    int Temp = i;
    i = i+1;
    return Temp;
}

int main()
{
    int k = 0;
    int i = 0;
    k = ++k;
    //k = preAdd(k);
    i = i++;
    //i = postAdd(i);
    std::cout << "After k = ++k, k = " << k << std::endl;
    std::cout << "After i = i++, i = " << i << std::endl;
    return 0;
}
