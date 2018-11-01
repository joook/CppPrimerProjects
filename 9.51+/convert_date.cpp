#include <iostream>
#include <stdexcept>
#include <vector>
#include "date.h"

using namespace std;

int main()
{
    string TempString;

    cout << "Input a date: " << endl;
    getline(cin, TempString);
    try
    {
        YearMonthDate Date001(TempString);
        cout << "It's standard form is: " << endl;
        cout << Date001.getYear() << ".";
        cout << Date001.getMonth() << ".";
        cout << Date001.getDate() << endl;
    }
    catch(out_of_range Err)
    {
        cerr << Err.what() << endl;
    }

    return 0;
}
