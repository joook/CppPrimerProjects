#include <iostream>
#include <vector>
#include <list>

using namespace std;

void eraseOddNum(list<int> &NumList)
{
    auto Itr = NumList.begin();
    while(Itr != NumList.end())
    {
        if(*Itr % 2)
        {
            Itr = NumList.erase(Itr);
        }
        else
        {
            Itr++;
        }
    }
}

void eraseEvenNum(vector<int> &NumVector)
{
    auto Itr = NumVector.begin();
    while(Itr != NumVector.end())
    {
        if((*Itr+1) % 2)
        {
            Itr = NumVector.erase(Itr);
        }
        else
        {
            Itr++;
        }
    }
}

void printNum(const list<int> &NumQueue)
{
    for(auto Itr = NumQueue.begin();
        Itr != NumQueue.end();
        Itr++)
    {
        cout << *Itr << endl;
    }
}

void printNum(const vector<int> &NumQueue)
{
    for(auto Itr = NumQueue.begin();
        Itr != NumQueue.end();
        Itr++)
    {
        cout << *Itr << endl;
    }
}

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    /*
    this doesn't work:
    list<int> NumList(ia);
    vector<int> NumVector(ia);

    this doesn't work either:
    list<int> NumList = ia;
    vector<int> NumVector = ia;
    */

    /*
    this works,
    be careful, it is "ia+12", not "ia+11"
    */
    list<int> NumList;
    vector<int> NumVector;
    NumList.assign(ia, ia+12);
    NumVector.insert(NumVector.end(), ia, ia+12);

    eraseOddNum(NumList);
    eraseEvenNum(NumVector);

    cout << "Number in the list: " << endl;
    printNum(NumList);
    cout << "Number in the vector: " << endl;
    printNum(NumVector);

    return 0;
}
