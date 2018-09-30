#include <iostream>
#include <vector>

typedef int MathFunc(int, int);
typedef int (*MathFuncPtr)(int, int);

using namespace std;

int pls(int a, int b)
{
    return (a+b);
}

int mins(int a, int b)
{
    return (a-b);
}

int multi(int a, int b)
{
    return (a*b);
}

int divi(int a, int b)
{
    return ((b != 0) ? (a/b) : 0);
}

int main()
{
    int a, b;

    cout << "Input a number: " << endl;
    cin >> a;
    cout << "Input another number: " << endl;
    cin >> b;

    vector<MathFuncPtr> mathfunc_vec;
    mathfunc_vec.push_back(pls);
    mathfunc_vec.push_back(mins);
    mathfunc_vec.push_back(multi);
    mathfunc_vec.push_back(divi);


    for(auto it = mathfunc_vec.begin(); it != mathfunc_vec.end(); it++)
    {
        int res = (**it)(a, b);
        cout << "res = " << res << endl;
    }


    return 0;
}

