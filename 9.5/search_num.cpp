#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator searchNum(vector<int>::iterator TempItr1, vector<int>::iterator TempItr2, int TempNum)
{
    auto TempItrBgn = (TempItr1 <= TempItr2) ? TempItr1 : TempItr2;
    auto TempItrEnd = (TempItr1 <= TempItr2) ? TempItr2 : TempItr1;
    for(;TempItrBgn != TempItrEnd; TempItrBgn++)
    {
        if(*TempItrBgn == TempNum)
        {
            break;
        }
    }

    return TempItrBgn;
}

int main()
{
    vector<int> VecNum{8, 4, 5, 3, 7, 9, 1, 0, 2, 6};
    int TargetNum = 10;
    vector<int>::iterator Result = searchNum(VecNum.begin(), VecNum.end(), TargetNum);
    if(Result == VecNum.end())
    {
        cout << "Not found." << endl;
    }
    else
    {
        cout << "Found it." << endl;
    }
    return 0;
}
