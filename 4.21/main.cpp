#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    vector<int> VecInt;
    int k;

    while(cin >> k)
    {
        VecInt.push_back(k);
    }

    for(auto it = VecInt.begin(); it != VecInt.end(); ++it)
    {
        (*it % 2) ? (*it = *it * 2) : 0;
    }

    for(auto it = VecInt.begin(); it != VecInt.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
