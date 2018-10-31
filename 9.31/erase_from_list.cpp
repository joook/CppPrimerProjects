#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> AllNum = {1, 2, 3, 4, 5, 6, 7};

    auto Itr = AllNum.begin();
    while(Itr != AllNum.end())
    {
        if(*Itr % 2)
        {
            Itr = AllNum.insert(Itr, *Itr);
            /*
            this will not work:
            Itr += 2;
            Itr = Itr+2;
            */
            Itr++;
            Itr++;
        }
        else
        {
            Itr = AllNum.erase(Itr);
        }
    }

    Itr = AllNum.begin();
    while(Itr != AllNum.end())
    {
        cout << *Itr << " ";
        Itr++;
    }
    cout << endl;

    return 0;
}
