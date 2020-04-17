#include "string_vector_class.h"
#include <iostream>

using namespace std;

allocator<string> StrVec::m_Allocator;

StrVec::StrVec()
: m_First(nullptr)
, m_FirstFree(nullptr)
, m_Last(nullptr)
{
    cout << "A StrVec is constructed." << endl;
}

StrVec::StrVec(initializer_list<string> InitList)
: m_First(nullptr)
, m_FirstFree(nullptr)
, m_Last(nullptr)
{
    /*
    for(auto Itr = InitList.begin(); Itr != InitList.end(); Itr++)
    {
        pushBack(*Itr);
    }
    */
    if(InitList.begin() != InitList.end())
    {
        //iterator can be used as a pointer
        auto NewMemory = copyMemory(InitList.begin(), InitList.end());
        m_First = NewMemory.first;
        m_FirstFree = NewMemory.second;
        m_Last = NewMemory.second;
    }
    else
    {
    }

    cout << "A StrVec is constructed." << endl;
}

StrVec::StrVec(const StrVec &OriStrVec)
{
    auto NewMemory = copyMemory(OriStrVec.m_First, OriStrVec.m_FirstFree);
    m_First = NewMemory.first;
    m_FirstFree = NewMemory.second;
    m_Last = NewMemory.second;

    cout << "A StrVec is copied." << endl;
}

StrVec &StrVec::operator=(const StrVec &OriStrVec)
{
    auto NewMemory = copyMemory(OriStrVec.m_First, OriStrVec.m_FirstFree);

    freeMemory();

    m_First = NewMemory.first;
    m_FirstFree = NewMemory.second;
    m_Last = NewMemory.second;

    cout << "A StrVec is assigned." << endl;

    return *this;
}

StrVec::StrVec(StrVec &&OriStrVec) noexcept
{
    m_First = OriStrVec.m_First;
    m_FirstFree = OriStrVec.m_FirstFree;
    m_Last = OriStrVec.m_FirstFree;

    OriStrVec.m_First = nullptr;
    OriStrVec.m_FirstFree = nullptr;
    OriStrVec.m_FirstFree = nullptr;

    cout << "A StrVec is moved." << endl;
}

StrVec &StrVec::operator=(StrVec &&OriStrVec) noexcept
{
    if(this != &OriStrVec)
    {
        freeMemory();

        m_First = OriStrVec.m_First;
        m_FirstFree = OriStrVec.m_FirstFree;
        m_Last = OriStrVec.m_FirstFree;

        OriStrVec.m_First = nullptr;
        OriStrVec.m_FirstFree = nullptr;
        OriStrVec.m_FirstFree = nullptr;
    }
    else
    {
    }

    cout << "A StrVec is move-assigned." << endl;

    return *this;
}

StrVec::~StrVec()
{
    freeMemory();
}

void StrVec::pushBack(const string &NewStr)
{
    checkMemory();
    m_Allocator.construct(m_FirstFree, NewStr);
    m_FirstFree++;

    cout << "A string is pushed-back." << endl;
}

void StrVec::pushBack(string &&NewStr)
{
    checkMemory();
    m_Allocator.construct(m_FirstFree, std::move(NewStr));
    m_FirstFree++;

    cout << "A string is move-pushed-back." << endl;
}

void StrVec::resize(size_t NewSize)
{
    resize(NewSize, "");
}

void StrVec::resize(size_t NewSize, const std::string &InitStr)
{
    while(NewSize > capacity())
    {
        reallocateMemory();
    }

    if(NewSize < size())
    {
        for(int i = 0; i != size()-NewSize; i++)
        {
            m_Allocator.destroy(m_First+NewSize+i);
        }
        m_FirstFree = m_First+NewSize;
    }
    else
    {
        for(int i = 0; i != NewSize-size(); i++)
        {
            m_Allocator.construct(m_FirstFree+i, InitStr);
        }
        m_FirstFree = m_First+NewSize;
    }
}

void StrVec::reserve(size_t NewCapacity)
{
    reserveMemory(NewCapacity);
}

void StrVec::checkMemory()
{
    if(size() == capacity())
    {
        reallocateMemory();
    }
    else
    {
    }
}

void StrVec::reallocateMemory()
{
    size_t NewCapacity;
    if(capacity() != 0)
    {
        NewCapacity = 2*capacity();
    }
    else
    {
        NewCapacity = 1;
    }

    reserveMemory(NewCapacity);
}

void StrVec::reserveMemory(size_t NewCapacity)
{
    if(NewCapacity > capacity())
    {
        string *NewFirst = m_Allocator.allocate(NewCapacity);

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
        m_Last = NewFirst+NewCapacity;
    }
    else
    {
        //do nothing
    }
}

pair<string *, string *> StrVec::copyMemory(const string *OriBegin, const string *OriEnd)
{
    pair<string *, string *> NewMemory = { nullptr, nullptr };

    if((OriBegin != nullptr) && (OriBegin <= OriEnd))
    {
        size_t Size = OriEnd-OriBegin;
        string *NewBegin = m_Allocator.allocate(Size);
        /*
        auto Target = NewBegin;
        auto Source = OriBegin;
        for(size_t i = 0; i != Size; i++)
        {
            m_Allocator.construct(Target, *Source);
            Target++;
            Source++;
        }
        */

        //pointer can be used as an iterator
        uninitialized_copy(OriBegin, OriEnd, NewBegin);

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


