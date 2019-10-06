#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

shared_ptr<vector<int>> readNum()
{
    shared_ptr<vector<int>> pNumVec = make_shared<vector<int>>();
    int Num;
    cout << "Input some numbers, divided by space. " << endl;
    while(cin >> Num)
    {
        pNumVec->push_back(Num);
    }
    return pNumVec;
}

void printNum(shared_ptr<vector<int>> pNumVec)
{
    cout << "The numbers in vector are: " << endl;
    for(const auto &Num : *pNumVec)
    {
        cout << Num << " ";
    }
    cout << endl;
}

int main()
{
    shared_ptr<vector<int>> pNumVec = readNum();
    printNum(pNumVec);
    return 0;
}
