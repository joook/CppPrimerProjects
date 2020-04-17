#include <iostream>
#include "valuelike_string_ptr.h"

using namespace std;

int main()
{
    StrPtr Str1("A string.");

    Str1 = std::move(Str1);

    StrPtr Str2 = Str1;

    StrPtr Str3 = std::move(Str2);

    return 0;
}
