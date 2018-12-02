#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string TempStr;
    string TargetStr;
    vector<string> StrVec;

    cout << "Input some strings, each string begins on a new line: " << endl;
    while(getline(cin, TempStr))
    {
        StrVec.push_back(TempStr);
    }
    /*
    Clear is necessary if you want to input something else.
    */
    cin.clear();

    cout << "Input the string you want to count: " << endl;
    getline(cin, TargetStr);

    auto ItrBeg = StrVec.begin();
    auto ItrEnd = StrVec.end();
    auto Count = count(ItrBeg, ItrEnd, TargetStr);
    cout << "The string \"" << TargetStr << "\" appears " << Count << " times." << endl;

    return 0;
}
