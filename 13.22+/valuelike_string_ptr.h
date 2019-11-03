#include <string>
#include <memory>

class StrPtr
{
public:
    StrPtr(const std::string &InitStr = std::string())
    : m_StrPtr(new std::string(InitStr))
    , m_Pos(0)
    {
    }

    //if you copy this StrPtr, the new StrPtr point to its own string
    StrPtr(const StrPtr &InitPtr)
    : m_StrPtr(new std::string(*(InitPtr.m_StrPtr)))
    , m_Pos(InitPtr.m_Pos)
    {
    }

    //if you copy this StrPtr, the new StrPtr point to its own string
    StrPtr & operator=(const StrPtr &InitPtr)
    {
        auto TempPtr = new std::string(*(InitPtr.m_StrPtr));
        delete m_StrPtr;

        m_StrPtr = TempPtr;
        m_Pos = InitPtr.m_Pos;

        return *this;
    }

    ~StrPtr()
    {
        delete m_StrPtr;
    }

    void print();

    void setPos(size_t NewPos)
    {
        m_Pos = NewPos;
    }

    void setStr(const std::string &NewStr)
    {
        *m_StrPtr = NewStr;
    }

private:
    std::string *m_StrPtr;
    size_t m_Pos;
};

