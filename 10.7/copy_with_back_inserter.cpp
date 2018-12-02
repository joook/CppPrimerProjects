#include <iostream>
//#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> VecInt1 = {1, 1, 2, 3, 5, 8};
    vector<int> VecInt2 = {};

    /*
    This is wrong, VecInt2 is shorter than VecInt1,
    you cannot copy items from VecInt1 to VecInt2.
    */
    //copy(VecInt1.cbegin(), VecInt1.cend(), VecInt2.begin());
    /*
    This is right, we insert items to the back of VecInt2.
    */
    copy(VecInt1.cbegin(), VecInt1.cend(), back_inserter(VecInt2));

    for(auto Itr = VecInt2.cbegin(); Itr != VecInt2.cend(); Itr++)
    {
        cout << *Itr << " ";
    }
    cout << endl;

    return 0;
}
