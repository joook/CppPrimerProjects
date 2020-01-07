#include "string_vector_class.h"
#include <iostream>

using namespace std;

allocator<string> StrVec::m_Allocator;

StrVec::StrVec()
: m_First(nullptr)
, m_FirstFree(nullptr)
, m_Last(nullptr)
{
}

StrVec::StrVec(const StrVec &OriStrVec)
{
    auto NewMemory = copyMemory(OriStrVec.m_First, OriStrVec.m_FirstFree);
    m_First = NewMemory.first;
    m_FirstFree = NewMemory.second;
    m_Last = NewMemory.second;
}

StrVec &StrVec::operator=(const StrVec &OriStrVec)
{
    auto NewMemory = copyMemory(OriStrVec.m_First, OriStrVec.m_FirstFree);

    freeMemory();

    m_First = NewMemory.first;
    m_FirstFree = NewMemory.second;
    m_Last = NewMemory.second;

    return *this;
}

StrVec::~StrVec()
{
    freeMemory();
}

void StrVec::pushBack(const string &NewStr)
{
    checkCapacity();
    m_Allocator.construct(m_FirstFree, NewStr);
    m_FirstFree++;
}

void StrVec::checkCapacity()
{
    if(size() < capacity())
    {
    }
    else
    {
        reallocateMemory();
    }
}

void StrVec::reallocateMemory()
{
    size_t Capacity;
    if(capacity() != 0)
    {
        Capacity = 2*capacity();
    }
    else
    {
        Capacity = 1;
    }

    string *NewFirst = m_Allocator.allocate(Capacity);

    auto Target = NewFirst;
    auto Source = m_First;
    for(size_t i = 0; i != size(); i++)
    {
        m_Allocator.construct(Target, std::move(*Source));
        Target++;
        Source++;
    }

    freeMemory();

    m_First = NewFirst;
    m_FirstFree = Target;
    m_Last = NewFirst+Capacity;
}

pair<string *, string *> StrVec::copyMemory(string *OriBegin, string *OriEnd)
{
    pair<string *, string *> NewMemory = { nullptr, nullptr };

    if((OriBegin != nullptr) && (OriBegin <= OriEnd))
    {
        size_t Size = OriEnd-OriBegin;
        string *NewBegin = m_Allocator.allocate(Size);

        auto Target = NewBegin;
        auto Source = OriBegin;
        for(size_t i = 0; i != Size; i++)
        {
            m_Allocator.construct(Target, *Source);
            Target++;
            Source++;
        }
        
        //uninitialized_copy(OriBegin, OriEnd, NewBegin);

        NewMemory.first = NewBegin;
        NewMemory.second = NewBegin+Size;
    }
    else
    {
    }

    return NewMemory;
}

void StrVec::freeMemory()
{
    if(m_First != nullptr)
    {
        for(string *Ptr = m_First; Ptr != m_FirstFree; Ptr++)
        {
            m_Allocator.destroy(Ptr);
        }
        m_Allocator.deallocate(m_First, (m_Last-m_First));
    }
    else
    {
        //do nothing
    }
}


