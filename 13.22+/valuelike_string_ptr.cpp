#include <iostream>
#include "valuelike_string_ptr.h"

using namespace std;

void StrPtr::print()
{
    if(m_Pos < m_StrPtr->size())
    {
        string PrintStr = m_StrPtr->substr(m_Pos);
        cout << PrintStr << endl;
    }
    else
    {
    }
}
