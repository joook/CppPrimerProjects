#include "string_class.h"
#include <stdexcept>

using namespace std;

allocator<char> Str::m_Allocator;

Str::Str()
: m_First(nullptr)
, m_FirstFree(nullptr)
, m_Last(nullptr)
{
    reallocateMemory();
}

Str::Str(const char *StrPtr)
{
    /*
    char *Ptr = StrPtr;
    while((Ptr != nullptr) && (*Ptr != '\0'))
    {
        pushBack(*Ptr);
    }
    */

    if(StrPtr != nullptr)
    {
        char *EndPtr = const_cast<char *>(StrPtr);
        while(*EndPtr != '\0')
        {
            EndPtr++;
        }
        auto NewMemory = copyMemory(StrPtr, EndPtr);
        m_First = NewMemory.first;
        m_FirstFree = NewMemory.second;
        m_Last = NewMemory.second;
    }
    else
    {
    }
}

Str::Str(size_t Length, const char Char)
{
    for(size_t i = 0; i != Length; i++)
    {
        pushBack(Char);
    }
}

Str::Str(const Str &OriStr)
: m_First(nullptr)
, m_FirstFree(nullptr)
, m_Last(nullptr)
{
    auto Pair = copyMemory(OriStr.m_First, OriStr.m_FirstFree);
    m_First = Pair.first;
    m_FirstFree = Pair.second;
    m_Last = Pair.second;
}

Str & Str::operator=(const Str &OriStr)
{
    auto Pair = copyMemory(OriStr.m_First, OriStr.m_FirstFree);

    freeMemory();

    m_First = Pair.first;
    m_FirstFree = Pair.second;
    m_Last = Pair.second;

    return *this;
}

Str::~Str()
{
    freeMemory();
}

void Str::pushBack(const char &NewChar)
{
    checkMemory();
    m_Allocator.construct(m_FirstFree, NewChar);
    m_FirstFree++;
}

char &Str::at(size_t Pos)
{
    if(Pos < size())
    {
        return *(m_First+Pos);
    }
    else
    {
        throw range_error("Try to refer to a position beyond range.");
    }
}

const char *Str::c_str()
{
    auto Pair = copyMemory(m_First, m_FirstFree);
    if((Pair.first != nullptr) && (Pair.second != nullptr))
    {
        if((Pair.first == Pair.second) || (*(Pair.second-1) != '\0'))
        {
            m_Allocator.construct(Pair.second, '\0');
        }
        else
        {
            //do nothing
        }
        return Pair.first;
    }
    else
    {
        throw runtime_error("Refered before initial.");
    }
}

void Str::checkMemory()
{
    if(size() == capacity())
    {
        reallocateMemory();
    }
    else
    {
        //do nothing
    }
}

void Str::reallocateMemory()
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

void Str::reserveMemory(size_t NewCapacity)
{
    if(NewCapacity > capacity())
    {
        char *NewFirst = m_Allocator.allocate(NewCapacity);
        char *NewPtr = NewFirst;
        char *OriPtr = m_First;
        for(size_t i = 0; i != size(); i++)
        {
            m_Allocator.construct(NewPtr, move(*OriPtr));
            NewPtr++;
            OriPtr++;
        }

        freeMemory();
        m_First = NewFirst;
        m_FirstFree = NewPtr;
        m_Last = NewFirst+NewCapacity;
    }
    else
    {
        //do nothing
    }
}

pair<char *, char *> Str::copyMemory(const char *OriBegin, const char *OriEnd)
{
    pair<char *, char *> Pair = { nullptr, nullptr };
    if((OriBegin != nullptr) && (OriEnd != nullptr) && (OriBegin <= OriEnd))
    {
        size_t Size = OriEnd-OriBegin;
        char *NewBegin = m_Allocator.allocate(Size);
        /*
        char *NewPtr = NewBegin;
        char *OriPtr = OriBegin;
        for(size_t i = 0; i != Size; i++)
        {
            m_Allocator.construct(NewPtr, *OriPtr);
            NewPtr++;
            OriPtr++;
        }
        */
        uninitialized_copy(OriBegin, OriEnd, NewBegin);
        Pair.first = NewBegin;
        Pair.second = NewBegin+Size;
    }
    else
    {
        //do nothing
    }
    return Pair;
}

void Str::freeMemory()
{
    if((m_First != nullptr) && (m_FirstFree != nullptr) && (m_First <= m_FirstFree))
    {
        for(char *Ptr = m_First; Ptr != m_FirstFree; Ptr++)
        {
            m_Allocator.destroy(Ptr);
        }
        m_Allocator.deallocate(m_First, capacity());
        m_First = nullptr;
        m_FirstFree = nullptr;
        m_Last = nullptr;
    }
    else
    {
        m_First = nullptr;
        m_FirstFree = nullptr;
        m_Last = nullptr;
    }
}

