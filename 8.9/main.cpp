#include <iostream>
#include <sstream>

using namespace std;

istream &readStream(istream &TempIS)
{
    char TempChar;
    string TempStr;
    while(TempIS >> TempStr && ~TempIS.eof())
    {
        cout << TempStr << endl;
    }
    TempIS.clear();
    return TempIS;
}

int main()
{
    string TempStr = "A regular string.";

    istringstream IStrStream(TempStr);
    readStream(IStrStream);

    return 0;
}
