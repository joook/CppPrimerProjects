#include <iostream>
#include "pointerlike_string_ptr.h"

using namespace std;

StrPtr::StrPtr(const string &InitStr = string())
: m_StrPtr(new string(InitStr))
, m_PtrCount(new size_t(1))
, m_Pos(0)
{
    cout << "StrPtr constructed." << endl;

    cout << "*m_PtrCount: " << *m_PtrCount << endl;
}

//if you copy this StrPtr, the new StrPtr point to the same string
StrPtr::StrPtr(StrPtr &InitPtr)
: m_StrPtr(InitPtr.m_StrPtr)
, m_PtrCount(InitPtr.m_PtrCount)
, m_Pos(InitPtr.m_Pos)
{
    cout << "StrPtr copy constructed." << endl;

    (*(InitPtr.m_PtrCount))++;
    cout << "*m_PtrCount: " << *m_PtrCount << endl;
}

//if you copy this StrPtr, the new StrPtr point to the same string
StrPtr & StrPtr::operator=(StrPtr &InitPtr)
{
    cout << "StrPtr copied." << endl;

    (*(InitPtr.m_PtrCount))++;

    (*m_PtrCount)--;
    cout << "*m_PtrCount: " << *m_PtrCount << endl;
    if(*m_PtrCount == 0)
    {
        delete m_StrPtr;
        delete m_PtrCount;
    	cout << "StrPtr deleted." << endl;
    }
    else
    {
    }

    m_StrPtr = InitPtr.m_StrPtr;
    m_PtrCount = InitPtr.m_PtrCount;
    m_Pos = InitPtr.m_Pos;
    cout << "*m_PtrCount: " << *m_PtrCount << endl;

    return *this;
}

StrPtr::~StrPtr()
{
    cout << "StrPtr destructed." << endl;

    (*m_PtrCount)--;
    cout << "*m_PtrCount: " << *m_PtrCount << endl;
    if(*m_PtrCount == 0)
    {
        delete m_StrPtr;
        delete m_PtrCount;
    	cout << "StrPtr deleted." << endl;
    }
    else
    {
    }
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
