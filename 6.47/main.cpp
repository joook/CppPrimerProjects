#include <iostream>
#include "calcu.h"

using namespace std;

int main()
{
    int a, b;

    #ifndef NDEBUG
    cerr << "[" << __FILE__ << "(" << __LINE__ << ")]" ;
    cerr << __func__ << ": ";
    #endif
    cout << "Input a number: " << endl;
    cin >> a;
    #ifndef NDEBUG
    cerr << "[" << __FILE__ << "(" << __LINE__ << ")]" ;
    cerr << __func__ << ": ";
    #endif
    cout << "Input another number: " << endl;
    cin >> b;

    cout << "Product of factorials is: " << multi(a, b) << endl;

    return 0;
}

