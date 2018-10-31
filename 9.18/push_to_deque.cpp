#include <iostream>
#include <deque>

using namespace std;

void readString(deque<string> &TempDeque)
{
    string TempString;
    while(getline(cin, TempString))
    {
        TempDeque.push_back(TempString);
    }
}

void printDeque(deque<string> &TempDeque)
{
    for(auto TempItr = TempDeque.begin();
        TempItr != TempDeque.end();
        TempItr++)
    {
        cout << *TempItr << endl;
    }
}

int main()
{
    deque<string> TempDeque;

    cout << "Input some string: " << endl;
    readString(TempDeque);
    printDeque(TempDeque);

    return 0;
}
