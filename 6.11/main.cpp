#include <iostream>
#include "reset.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
    int k;

    cout << "Input a number: " << endl;
    cin >> k;

    resetnum(k);

    cout << "After reset, its value: " << endl;
    cout << k << endl;

    return 0;
}
