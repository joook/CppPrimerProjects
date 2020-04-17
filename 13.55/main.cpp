#include "string_vector_class.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    StrVec Vec1;
    string Str = "B0";

    Vec1.pushBack(Str);

    StrVec Vec2 = Vec1;

    Vec2.pushBack("E0");

    return 0;
}
