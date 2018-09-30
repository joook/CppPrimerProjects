#include <iostream>
#include <vector>

typedef int Func(int, int);
typedef int (*FuncP)(int, int);

using namespace std;
using Func2 = int(int, int);
using FuncP2 = int(*)(int, int);

int f(int, int)
{
    return 0;
}

int main()
{
    vector<FuncP> v1;
    vector<FuncP2> v2;
    vector<decltype(f) *> v3;

    v1.push_back(f);
    v2.push_back(f);
    v3.push_back(f);

    return 0;
}
