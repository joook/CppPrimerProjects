#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    list<char*> TempList = {"f0", "f1", "f2"};
    vector<string> TempVector(TempList.begin(), TempList.end());
    for(auto TempItr = TempVector.begin(); TempItr != TempVector.end();
        TempItr++)
    {
        cout << *TempItr << endl;
    }

    return 0;
}
