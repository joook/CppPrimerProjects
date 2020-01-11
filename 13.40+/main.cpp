#include "string_vector_class.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    StrVec Vec1({"NNN0", "NNN1", "NNN2"});
    for(int i = 0; i < 5; i++)
    {
        Vec1.pushBack("PPP"+to_string(i));
    }

    StrVec Vec2 = Vec1;
    Vec2.resize(12, "TTT0");

    cout << "Strings in the copied vector are: " << endl;
    for(auto Begin = Vec2.begin(); Begin != Vec2.end(); Begin++)
    {
        cout << *Begin << endl;
    }

    return 0;
}
