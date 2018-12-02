#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const char CStr1[] = "Traditional C string 1";
    const char CStr2[] = "Traditional C string 1";
    string CppStr1 = "Cpp string 1";
    string CppStr2 = "Cpp string 1";

    cout << "Two C strings are ";
    cout << ((strcmp(CStr1, CStr2) == 0) ? "equal." : "not equal.") << endl;

    cout << "Two Cpp strings are ";
    cout << ((CppStr1 == CppStr2) ? "equal." : "not equal.") << endl;

    return 0;
}
