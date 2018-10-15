#include <iostream>

using namespace std;

istream &readStream(istream &TempIS)
{
    char TempChar;
    string TempStr;
    /*
    //This will not work if you input EOF.
    while(~TempIS.eof())
    {
        TempIS >> TempChar;
        cout << TempChar << endl;
    }
    */
    /*
    while(TempIS >> TempChar && ~TempIS.eof())
    {
        cout << TempChar << endl;
    }
    */
    while(TempIS >> TempStr && ~TempIS.eof())
    {
        cout << TempStr << endl;
    }
    TempIS.clear();
    return TempIS;
}

int main()
{
    readStream(cin);
    return 0;
}
