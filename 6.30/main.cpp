#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int addvert(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;

    return (a+b);
}

int main()
{
    int a, b;

    cout << "Input 2 numbers: " << endl;
    cin >> a >> b;
    cout << "The sum is: " << addvert(a, b) << endl;
    cout << "Now a = " << a << endl;
    cout << "and b = " << b << endl;
    
    return 0;
}
