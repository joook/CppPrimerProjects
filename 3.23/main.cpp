#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> VecStr(5, "dem");
    string str;
    vector<int> VecInt{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    for(auto it = VecStr.begin(); it != VecStr.end(); ++it)
    {
        cout << *it << endl;
    }

    for(auto it = VecInt.begin(); it != VecInt.end(); ++it)
    {
        *it = *it * 2;
        cout << *it << endl;
    }

    return 0;
}
