#include "access_specifier.h"
#include <iostream>

using namespace std;

void printMem(Base &BaseObj)
{
    cout << BaseObj.m_PublicMember << endl;
    //cout << BaseObj.m_ProtectedMember << endl;
    //cout << BaseObj.m_PrivateMember << endl;
}

int main()
{
    Pub Obj1;
    Prot Obj2;
    Priv Obj3;

    printMem(Obj1);
    //printMem(Obj2);
    //printMem(Obj3);

    return 0;
}
