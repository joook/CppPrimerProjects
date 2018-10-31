#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<char> TempVector = {'s', 't', 'a', 'r'};
    string TgtString(TempVector.data(), TempVector.size());

    cout << TgtString << endl;

    return 0;
}
