#include <iostream>
#include "swap.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    int a, b;

    cout << "Input two numbers: " << endl;
    cin >> a >> b;

    swapnum(&a, &b);
    cout << "After swapped: " << endl;
    cout << a << " " << b << endl;

    return 0;
}
