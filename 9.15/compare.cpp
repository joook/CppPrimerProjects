#include <iostream>
#include <vector>

using namespace std;

int main()
{
    bool CompareResult = false;
    vector<int> TempVector1 = {1, 2, 3};
    vector<int> TempVector2 = {3, 2, 1};

    CompareResult = (TempVector1 == TempVector2);
    cout << ((CompareResult == true) ? "Equal." : "Not equal.") << endl;

    return 0;
}
