#include <iostream>
#include "valuelike_string_ptr.h"

using namespace std;

StrPtr::StrPtr(const string &InitStr = string())
: m_StrPtr(new string(InitStr))
, m_Pos(0)
{
    cout << "StrPtr constructed." << endl;
}

//if you copy a StrPtr, the new StrPtr point to its own string
StrPtr::StrPtr(const StrPtr &InitPtr)
: m_StrPtr(new string(*(InitPtr.m_StrPtr)))
, m_Pos(InitPtr.m_Pos)
{
    cout << "StrPtr copied." << endl;
}

//if you copy a StrPtr, the new StrPtr point to its own string
StrPtr &StrPtr::operator=(const StrPtr &InitPtr)
{
    auto TempPtr = new string(*(InitPtr.m_StrPtr));
    delete m_StrPtr;

    m_StrPtr = TempPtr;
    m_Pos = InitPtr.m_Pos;

    cout << "StrPtr assigned." << endl;

    return *this;
}

//if you move a StrPtr, the new StrPtr point to initial string
StrPtr::StrPtr(StrPtr &&InitPtr) noexcept
: m_StrPtr(InitPtr.m_StrPtr)
, m_Pos(InitPtr.m_Pos)
{
    InitPtr.m_StrPtr = nullptr;

    cout << "StrPtr moved." << endl;
}

//if you move a StrPtr, the new StrPtr point to initial string
StrPtr &StrPtr::operator=(StrPtr &&InitPtr) noexcept
{
    if(this != &InitPtr)
    {
        m_StrPtr = InitPtr.m_StrPtr;
        m_Pos = InitPtr.m_Pos;

        InitPtr.m_StrPtr = nullptr;
    }
    else
    {
    }

    cout << "StrPtr move-assigned." << endl;

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
