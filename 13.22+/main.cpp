#include <iostream>
#include "valuelike_string_ptr.h"

using namespace std;

int main()
{
    StrPtr Str1("string 1st");
    Str1.setPos(6);

    StrPtr Str2 = Str1;
    Str2.print();

    Str2.setStr("string 2nd");
    Str2.print();

    *Str2 = "string 3rd";
    Str2.print();
    cout << *Str2 << endl;

    Str2 = "string 4th";
    Str2.print();
    cout << *Str2 << endl;

    return 0;
}
