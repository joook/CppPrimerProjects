#include <iostream>
#include <string>

#include "print.h"

int main()
{
    int i = 0;
    int* p = &i;
    double d = 3.3;
    std::string s = "abcd";

    print(i, p, d, s);

    return 0;
}
