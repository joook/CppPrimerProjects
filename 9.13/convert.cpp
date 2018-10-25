#include <iostream>
#include <vector>
#include <list>

using namespace std;

void printVector(vector<double>::iterator TempItr1, vector<double>::iterator TempItr2)
{
    auto TempItrBgn = (TempItr1 <= TempItr2) ? TempItr1 : TempItr2;
    auto TempItrEnd = (TempItr1 <= TempItr2) ? TempItr2 : TempItr1;
    for(; TempItrBgn != TempItrEnd; TempItrBgn++)
    {
        cout << *TempItrBgn << endl;
    }
}

int main()
{
    list<int> TempList = {10, 11, 12, 13, 14};
    vector<int> TempVector1 = {15, 16, 17, 18};

    vector<double> TempVector2(TempList.begin(), TempList.end());
    vector<double> TempVector3(TempVector1.begin(), TempVector1.end());
    printVector(TempVector2.begin(), TempVector2.end());
    printVector(TempVector3.begin(), TempVector3.end());

    return 0;
}
