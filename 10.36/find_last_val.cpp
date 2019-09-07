#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    list<int> NumList{0, 1, 0, 2, 0, 3, 0, 4, 0, 5};
    auto Itr = NumList.cbegin();
    auto ResultItr = NumList.cbegin();
    while(1)
    {
        Itr = find(Itr, NumList.cend(), 0);
        if(Itr != NumList.cend())
        {
            ResultItr = Itr;
            Itr++;
        }
        else
        {
            cout << "Got the last 0." << endl;
            //the two sentence below will cause error
            //cout << "the value before it is: " << *(ResultItr-1) << endl;
            //cout << "the value after it is: " << *(ResultItr+1) << endl;
            cout << "the value before it is: " << *(--ResultItr) << endl;
            cout << "the value before it is: " << *(++(++ResultItr)) << endl;
            break; //break while
        }
    }
    return 0;
}
