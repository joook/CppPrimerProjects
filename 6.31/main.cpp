#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

const string &longerstring(const string &s1, const string &s2)
{
    return (s1 >= s2 ? s1 : s2);
}

int main()
{
    string s1, s2;

    cout << "Input 2 string: " << endl;
    getline(cin, s1);
    getline(cin, s2);
    cout << "The longer string is: " << endl;
    cout << longerstring(s1, s2) << endl;

    return 0;
}
