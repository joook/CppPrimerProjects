#include <iostream>
#include "pointerlike_string_ptr.h"

using namespace std;

int main()
{
    StrPtr Str1("string 1st");
    Str1.setPos(6);
    StrPtr Str2("string 2nd");
    Str2.setPos(0);

    StrPtr Str3 = Str1;
    Str3.print();

    Str3 = Str2;
    Str3.print();

    return 0;
}
