#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int TempNum;
    int TargetNum;
    vector<int> NumVec;

    cout << "Input some int numbers, divided by space: " << endl;
    while(cin >> TempNum)
    {
        NumVec.push_back(TempNum);
    }
    /*
    Clear is necessary if you want to input something else.
    */
    cin.clear();

    cout << "Input the number you want to count: " << endl;
    cin >> TargetNum;

    auto ItrBeg = NumVec.begin();
    auto ItrEnd = NumVec.end();
    auto Count = count(ItrBeg, ItrEnd, TargetNum);
    cout << "The number " << TargetNum << " appears " << Count << " times." << endl;

    return 0;
}
