#include <iostream>
#include "valuelike_string_ptr.h"

using namespace std;

StrPtr::StrPtr(const string &InitStr = string())
: m_StrPtr(new string(InitStr))
, m_Pos(0)
{
}

//if you copy this StrPtr, the new StrPtr point to its own string
StrPtr::StrPtr(const StrPtr &InitPtr)
: m_StrPtr(new string(*(InitPtr.m_StrPtr)))
, m_Pos(InitPtr.m_Pos)
{
}

//if you copy this StrPtr, the new StrPtr point to its own string
StrPtr & StrPtr::operator=(const StrPtr &InitPtr)
{
    auto TempPtr = new string(*(InitPtr.m_StrPtr));
    delete m_StrPtr;

    m_StrPtr = TempPtr;
    m_Pos = InitPtr.m_Pos;

    return *this;
}

StrPtr::~StrPtr()
{
    delete m_StrPtr;
}

string & StrPtr::operator*()
{
    return *m_StrPtr;
}

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

void swap(StrPtr &Ptr1, StrPtr &Ptr2)
{
    swap(Ptr1.m_StrPtr, Ptr2.m_StrPtr);
    swap(Ptr1.m_Pos, Ptr2.m_Pos);
}
