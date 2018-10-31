#include <iostream>
#include <list>

using namespace std;

void readString(list<string> &TempList)
{
    string TempString;
    while(getline(cin, TempString))
    {
        TempList.push_back(TempString);
    }
}

void printList(list<string> &TempList)
{
    for(auto TempItr = TempList.begin();
        TempItr != TempList.end();
        TempItr++)
    {
        cout << *TempItr << endl;
    }
}

int main()
{
    list<string> TempList;

    cout << "Input some string: " << endl;
    readString(TempList);
    printList(TempList);

    return 0;
}
