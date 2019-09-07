#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> SourceVec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto Itr = SourceVec.end(); Itr != SourceVec.cbegin(); Itr--)
    {
        cout << *(Itr-1) << " ";
    }
    cout << endl;

    return 0;
}
