#include <iostream>
#include <string>
#include <memory>

class StrPtr
{
friend void swap(StrPtr &Ptr1, StrPtr &Ptr2);
friend bool operator<(const StrPtr &Ptr1, const StrPtr &Ptr2);

public:
    StrPtr(const std::string &InitStr);

    StrPtr(const StrPtr &InitPtr);

    StrPtr & operator=(const StrPtr &InitPtr);

    ~StrPtr();

    std::string & operator*();
    const std::string & operator*() const;

    void print() const;

    void setPos(size_t NewPos) { m_Pos = NewPos; }

    void setStr(const std::string &NewStr) { *m_StrPtr = NewStr; }

private:
    std::string *m_StrPtr;
    size_t m_Pos;
};

inline void swap(StrPtr &Ptr1, StrPtr &Ptr2)
{
    std::cout << "Now swap: " << *Ptr1 << " and " << *Ptr2 << std::endl;
    std::swap(Ptr1.m_StrPtr, Ptr2.m_StrPtr);
    std::swap(Ptr1.m_Pos, Ptr2.m_Pos);
}

inline bool operator<(const StrPtr &Ptr1, const StrPtr &Ptr2)
{
    std::cout << "Now compare: " << *Ptr1 << " and " << *Ptr2 << std::endl;
    return (*(Ptr1.m_StrPtr) < *(Ptr2.m_StrPtr));
}

