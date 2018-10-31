#include <iostream>
#include <deque>
#include <list>

using namespace std;

void readNum(list<int> &AllNum)
{
    int TempInt;
    while(cin >> TempInt)
    {
        AllNum.push_back(TempInt);
    }
}

void copyByParity(list<int> &AllNum, deque<int> &OddNum, deque<int> &EvenNum)
{
    for(auto Itr = AllNum.begin(); Itr != AllNum.end(); Itr++)
    {
        if(*Itr%2)
        {
            OddNum.push_back(*Itr);
        }
        else if((*Itr-1)%2)
        {
            EvenNum.push_back(*Itr);
        }
        else
        {
        }
    }
}

void printNum(deque<int> &NumDeque)
{
    for(auto Itr = NumDeque.begin(); Itr != NumDeque.end(); Itr++)
    {
        cout << *Itr << " ";
    }
}

int main()
{
    list<int> AllNum;
    deque<int> OddNum;
    deque<int> EvenNum;

    cout << "Input some numbers(divided by space): " << endl;
    readNum(AllNum);
    copyByParity(AllNum, OddNum, EvenNum);
    cout << "Odd numbers: " << endl;
    printNum(OddNum);
    cout << endl;
    cout << "Even numbers: " << endl;
    printNum(EvenNum);
    cout << endl;

    return 0;
}
