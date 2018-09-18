#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

void print(const char *);
void print(const string &);
void print(const vector<string> &, int);

int main()
{
    char c = '\'';
    string s = "not about money";
    char *cp = &c;
    //char *cp = &s; //This doesn't work.
    vector<string> v{"aa", "bb", "cc"}; //This needs "-std=c++11".

    print(cp);
    print(s);
    print(v, 2);

    return 0;
}

void print(const char *cp)
{
    cout << *cp << endl;
}

void print(const string &s)
{
    cout << s << endl;
}

void print(const vector<string> &v, int i)
{
    cout << v[i] << endl;
}
