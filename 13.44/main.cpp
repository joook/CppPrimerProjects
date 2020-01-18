#include "string_class.h"
#include <iostream>

using namespace std;

int main()
{
    Str Str1("abcd");
    Str Str2 = "efgh";
    Str Str3 = Str1;
    Str Str4;
    Str4 = Str2;
    Str3.pushBack('i');

    cout << "*(Str1.begin()): " << *(Str1.begin()) << endl;
    cout << "Str2.at(2): " << Str2.at(2) << endl;
    cout << "Str3.size(): " << Str3.size() << endl;
    cout << "Str3.capacity(): " << Str3.capacity() << endl;
    cout << "Str4.c_str(): " << Str4.c_str() << endl;

    return 0;
}
