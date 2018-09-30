#include <iostream>

using namespace std;

/*
int calc(int)
{
    cout << "calc(int)" << endl;
}

int calc(const int) //The compiler treat these 2 funcs as the same
{
    cout << "calc(const int)" << endl;
}
*/

int calc(int *p)
{
    cout << "calc(int *p)" << endl;
}

int calc(const int *p)
{
    cout << "calc(const int *p)" << endl;
}

int calc(int &r)
{
    cout << "calc(int &r)" << endl;
}

int calc(const int &r)
{
    cout << "calc(const int &r)" << endl;
}

int main()
{
    int k = 8;
    int *p = &k;
    int &r = k;
    const int k2 = 9;
    const int *p2 = &k;
    const int &r2 = k;
    //calc(k); //This cannot be compiled
    calc(p);
    calc(p2);
    calc(r);
    calc(r2);

    return 0;
}
