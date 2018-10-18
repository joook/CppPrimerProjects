#include <iostream>

using namespace std;

void getAccountNumber(istream &TempIs, string &AccNum)
{
    char TempChar;
    while(TempIs >> TempChar)
    {
        if(TempChar >= 48 && TempChar <= 57)
        {
            AccNum = AccNum + TempChar;
        }
        else if(TempIs.bad())
        {
            cout << "Bad stream, try again." << endl;
        }
        else if(TempIs.eof())
        {
            cout << "Input finished." << endl;
        }
        else
        {
            cout << "Input invalid." << endl;
        }
    }
}

int main()
{
    string AccNum001 = "";

    getAccountNumber(cin, AccNum001);
    cout << "Account Number: " << AccNum001 << endl;

    return 0;
}
