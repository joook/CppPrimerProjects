#include <iostream>
#include "plus.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    int cnt;
    while(1)
    {
        cnt = numplus();
        cout << "Function called." << endl;
        cout << "Go on? y or n." << endl;
        char c;
        cin >> c;
        if(!cin || c != 'y')
            break;
    }
    cout << "Function has been called " << cnt;
    cout << (cnt > 1 ? " times." : " time.") << endl;

    return 0;
}
