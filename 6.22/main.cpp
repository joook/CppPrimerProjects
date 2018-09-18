#include <iostream>

void swapptr(int *&p1, int *&p2)
{
    auto temp = p1;
    p1 = p2;
    p2 = temp;
}

int main()
{
    int a = 1, b = 2;
    int *pa = &a, *pb = &b;
    //int *&rpa = pa, *&rpb = pb;

    swapptr(pa, pb);
    //swapptr(rpa, rpb);

    std::cout << *pa << " " << *pb << std::endl;

    return 0;
}
