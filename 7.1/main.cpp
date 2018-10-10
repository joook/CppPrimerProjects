#include <iostream>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data tot;
    if(read(cin, tot))
    {
        Sales_data trans;
        while(read(cin, trans))
        {
            if(tot.isbn() == trans.isbn())
            {
                tot.combine(trans);
            }
            else
            {
                print(cout, tot) << endl;
                tot = trans;
            }
        }
        print() << endl;
    }
    else
    {
        cerr << "?" << endl;
    }
}
