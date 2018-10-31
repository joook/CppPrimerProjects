#include <iostream>

using namespace std;

string &appendToString(string &OrigString, string PreString, string PostString)
{
    /*
    this doesn't work:
    OrigString.insert(OrigString.begin(), PreString);
    */
    /*
    this works:
    OrigString.insert(OrigString.begin(), PreString.begin(), PreString.end());
    */
    OrigString.insert(0, PreString);
    OrigString.append(PostString);
    return OrigString;
}

int main()
{
    string Name = "Peter";
    string PreName = "Mr.";
    string PostName = "Jr.";

    string WholeName = appendToString(Name, PreName+" ", " "+PostName);
    cout << WholeName << endl;

    return 0;
}
