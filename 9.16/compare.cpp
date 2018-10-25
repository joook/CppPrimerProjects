#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    bool CompareResult = false;
    list<int> TempList = {1, 2, 3};
    vector<int> TempVector1 = {1, 2, 3};
    vector<int> TempVector2(TempList.begin(), TempList.end());

    CompareResult = (TempVector1 == TempVector2);
    cout << ((CompareResult == true) ? "Equal." : "Not equal.") << endl;

    return 0;
}
