#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string s = "word";
    string pl = s + s[s.size() - 1] == 's' ? "" : "s";

    return 0;
}
