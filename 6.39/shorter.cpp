#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

const string &shorter(const string &s1, const string &s2);
string &shorter(string &s1, string &s2);

int main()
{
    string s1, s2;

    cout << "Input two string: " << endl;
    getline(cin, s1);
    getline(cin, s2);

    cout << "The shorter string is: " << endl;
    cout << shorter(s1, s2) << endl;

    return 0;
}

const string &shorter(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

string &shorter(string &s1, string &s2)
{
    auto &s = shorter(const_cast<const string &>(s1), 
                      const_cast<const string &>(s2));
    return const_cast<string &>(s);
}
