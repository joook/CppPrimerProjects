#include "string_vector_class.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    StrVec Vec1;
    for(int i = 0; i < 10; i++)
    {
        Vec1.pushBack("PPP"+to_string(i));
    }

    cout << "Strings in the original vector are: " << endl;
    for(auto Begin = Vec1.begin(); Begin != Vec1.end(); Begin++)
    {
        cout << *Begin << endl;
    }

    StrVec Vec2 = Vec1;

    cout << "Strings in the copied vector are: " << endl;
    for(auto Begin = Vec2.begin(); Begin != Vec2.end(); Begin++)
    {
        cout << *Begin << endl;
    }

    return 0;
}
