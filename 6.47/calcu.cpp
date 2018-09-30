#include "calcu.h"

int multi(int a, int b)
{
    int fa = 1, fb = 1;
    for(; a > 1; a--)
    {
        fa = fa * a;
        #ifndef NDEBUG
        cerr << "[" << __FILE__ << "(" << __LINE__ << ")]" ;
        cerr << __func__ << ": factorial a is " << fa << endl;
        #endif
    }
    for(; b > 1; b--)
    {
        fb = fb * b;
        #ifndef NDEBUG
        cerr << "[" << __FILE__ << "(" << __LINE__ << ")]" ;
        cerr << __func__ << ": factorial b is " << fb << endl;
        #endif
    }
    return fa*fb;
}

