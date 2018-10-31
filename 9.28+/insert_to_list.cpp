#include <iostream>
#include <vector>

using namespace std;

void getNumQueue(vector<int> &NumQueue)
{
    int TempNum;
    while(cin >> TempNum)
    {
        NumQueue.push_back(TempNum);
    }
    cin.clear(); //this is necessary
}

void insertAfter(vector<int> &NumQueue, int InsertNum, int TargetNum)
{
    int TempNum;
    auto Itr = NumQueue.begin();
    while(Itr != NumQueue.end())
    {
        if(*Itr == TargetNum)
        {
            Itr = NumQueue.insert(Itr+1, InsertNum);
        }
        else
        {
            Itr++;
        }
    }
}

void printVector(const vector<int> &NumQueue)
{
    for(auto Itr = NumQueue.cbegin();
        Itr != NumQueue.cend();
        Itr++)
    {
        cout << *Itr << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> NumQueue;
    int InsertNum;
    int TargetNum;

    cout << "Input number queue: " << endl;
    getNumQueue(NumQueue);
    cout << "Input the number you want to insert: " << endl;
    cin >> InsertNum;
    cout << "Input the number you want to insert after: " << endl;
    cin >> TargetNum;
    insertAfter(NumQueue, InsertNum, TargetNum);
    cout << "Now the number queue is: " << endl;
    printVector(NumQueue);

    return 0;
}
