#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

int main()
{
    initializer_list<int> Nums = {1, 2, 3, 4};

    vector<int> NumVec(Nums);
    //vector<int> NumVec(Nums.begin(), Nums.end());

    for(auto Itr = NumVec.begin(); Itr != NumVec.cend(); Itr++)
    {
        cout << *Itr << endl;
    }

    return 0;
}
