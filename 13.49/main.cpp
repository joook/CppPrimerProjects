#include "string_vector_class.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    StrVec Vec1({"NNN0", "NNN1", "NNN2"});

    StrVec Vec2;
    Vec2 = Vec1;
    Vec2 = {"NNN3", "NNN4", "NNN5"};

    return 0;
}
