#include <iostream>
#include <vector>

using namespace std;

bool searchNum(vector<int>::iterator TempItr1, vector<int>::iterator TempItr2, int TempNum)
{
    bool ReturnVal = false;
    auto TempItrBgn = (TempItr1 <= TempItr2) ? TempItr1 : TempItr2;
    auto TempItrEnd = (TempItr1 <= TempItr2) ? TempItr2 : TempItr1;
    for(;TempItrBgn != TempItrEnd; TempItrBgn++)
    {
        if(*TempItrBgn == TempNum)
        {
            ReturnVal = true;
            break;
        }
        ReturnVal = false;
    }

    return ReturnVal;
}

int main()
{
    vector<int> VecNum{8, 4, 5, 3, 7, 9, 1, 0, 2, 6};
    int TargetNum = 6;
    bool Result = searchNum(VecNum.begin(), VecNum.end(), TargetNum);
    cout << Result << endl;
    return 0;
}
