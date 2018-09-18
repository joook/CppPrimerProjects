#include <iostream>
#include "allfuncs.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    string s;
    string line;

    cout << "Input a string: " << endl;
    while(getline(cin, line))
    {
        s = s + line + '\n';
    }

    cout << "The string ";
    cout << (checkcap(s) ? "has " : "has no ");
    cout << "capital inside." << endl;

    lower(s);
    cout << "Reform the string to lower form is: " << endl;
    cout << s << endl;

    return 0;
}
