#include <iostream>
#include <vector>

typedef bool Func(int);
typedef bool (*FuncP)(int);

using namespace std;

Func func;
FuncP funcp;
//Func un(char);//This will cause an error
FuncP un(char);
void uk(char, Func);
void us(char, bool (int));
void ue(char, FuncP);

bool f1(int k)
{
    return (k > 0);
}

bool f2(int k)
{
    return (k <= 0);
}

int main()
{
    bool ret;
    int k = -1;

    funcp = f1;
    ret = (*funcp)(k);
    cout << ret << endl;

    funcp = f2;
    ret = (*funcp)(k);
    cout << ret << endl;

    return 0;
}
