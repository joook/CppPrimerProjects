#include <iostream>
#include <vector>

using namespace std;

void insertToHead(vector<int> &NumQueue, istream &IStream)
{
    int TempNum;
    auto Itr = NumQueue.begin();
    while(IStream >> TempNum)
    {
        Itr = NumQueue.insert(Itr, TempNum);
    }
}

void printVector(const vector<int> &NumQueue)
{
    for(auto Itr = NumQueue.cbegin();
        Itr != NumQueue.cend();
        Itr++)
    {
        cout << *Itr << endl;
    }
}

int main()
{
    vector<int> NumQueue;

    cout << "Push some numbers into the stack: " << endl;
    insertToHead(NumQueue, cin);
    cout << "The numbers in the stack: " << endl;
    printVector(NumQueue);

    return 0;
}
