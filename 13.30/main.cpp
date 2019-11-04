#include <iostream>
#include "valuelike_string_ptr.h"

using namespace std;

int main()
{
    StrPtr Str1("string 1st");
    Str1.setPos(6);
    StrPtr Str2("string 2nd");
    Str2.setPos(3);

    Str1.print();
    Str2.print();

    swap(Str1, Str2);

    Str1.print();
    Str2.print();

    return 0;
}
