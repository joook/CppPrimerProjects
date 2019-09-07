#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

void printList(const list<int> &NumList)
{
    for(auto Itr = NumList.begin(); Itr != NumList.cend(); Itr++)
    {
        cout << *Itr << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> NumVec;
    for(int i = 1; i < 10; i++)
    {
        NumVec.push_back(i);
    }

    list<int> NumList1;
    list<int> NumList2;
    list<int> NumList3;
    copy(NumVec.cbegin(), NumVec.cend(), inserter(NumList1, NumList1.end()));
    copy(NumVec.cbegin(), NumVec.cend(), front_inserter(NumList2));
    copy(NumVec.cbegin(), NumVec.cend(), back_inserter(NumList3));

    printList(NumList1);
    printList(NumList2);
    printList(NumList3);

    return 0;
}
