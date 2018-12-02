#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> VecInt = {1, 1, 1};

    /*
    No error or warning during compiling, but the code below will not work, 
    only the 3 existing item will be filled with value "2".
    */
    /*
    VecInt.reserve(10);
    fill_n(VecInt.begin(), 10, 2);
    */
    /*
    Using the code below can fill the vector with ten 2s.
    */
    VecInt.clear();
    fill_n(back_inserter(VecInt), 10, 2);
    for(auto Itr = VecInt.cbegin(); Itr != VecInt.cend(); Itr++)
    {
        cout << *Itr << " ";
    }
    cout << endl;

    return 0;
}
