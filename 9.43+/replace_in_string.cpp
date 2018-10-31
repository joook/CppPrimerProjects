#include <iostream>

using namespace std;

void getString(string &WholeString)
{
    string TempLine;
    while(getline(cin, TempLine))
    {
        WholeString = WholeString + TempLine + '\n';
    }
    cin.clear();
}

void replaceString(string &WholeString, string TgtString, string RplString)
{
    auto Position = WholeString.find(TgtString);
    while(Position != string::npos)
    {
        WholeString.erase(Position, TgtString.size());
        WholeString.insert(Position, RplString);
        Position = WholeString.find(TgtString, Position);
    }
}

int main()
{
    string WholeString, TgtString, RplString;

    cout << "Input a string: " << endl;
    getString(WholeString);
    cout << "Input the word you want to replace: " << endl;
    cin >> TgtString;
    cout << "Input the word you want to replace with: " << endl;
    cin >> RplString;
    replaceString(WholeString, TgtString, RplString);
    cout << "Now the string is: " << endl;
    cout << WholeString << endl;

    return 0;
}
