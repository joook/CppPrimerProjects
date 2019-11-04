#include <string>
#include <memory>

class StrPtr
{
friend void swap(StrPtr &Ptr1, StrPtr &Ptr2);

public:
    StrPtr(const std::string &InitStr);

    StrPtr(const StrPtr &InitPtr);

    StrPtr & operator=(const StrPtr &InitPtr);

    ~StrPtr();

    std::string & operator*();

    void print();

    void setPos(size_t NewPos) { m_Pos = NewPos; }

    void setStr(const std::string &NewStr) { *m_StrPtr = NewStr; }

private:
    std::string *m_StrPtr;
    size_t m_Pos;
};

void swap(StrPtr &Ptr1, StrPtr &Ptr2);

