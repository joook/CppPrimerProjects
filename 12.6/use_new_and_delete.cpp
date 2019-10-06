#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> *readNum()
{
    vector<int> *pNumVec = new vector<int>();
    int Num;
    cout << "Input some numbers, divided by space. " << endl;
    while(cin >> Num)
    {
        pNumVec->push_back(Num);
    }
    return pNumVec;
}

void printNum(const vector<int> *pNumVec)
{
    cout << "The numbers in vector are: " << endl;
    for(const auto &Num : *pNumVec)
    {
        cout << Num << " ";
    }
    cout << endl;
}

void dumpNum(vector<int> *pNumVec)
{
    delete pNumVec;
    pNumVec = nullptr;
}

int main()
{
    vector<int> *pNumVec = readNum();
    printNum(pNumVec);
    dumpNum(pNumVec);

    return 0;
}
