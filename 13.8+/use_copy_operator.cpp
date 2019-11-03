#include <iostream>
#include <string>
#include <memory>

using namespace std;

class StrPtr
{
public:
    StrPtr(const string &InitStr = string())
    : m_StrPtr(new string(InitStr))
    , m_Pos(0)
    {
    }

    //if operator= is not defined(using a default operator=), 
    //the usage in main() will cause segment fault
    StrPtr & operator=(const StrPtr &InitPtr)
    {
        std::string *TempPtr = new string(*(InitPtr.m_StrPtr));
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

private:
    string *m_StrPtr;
    size_t m_Pos;
};

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

int main()
{
    StrPtr Str2;

    {
        StrPtr Str1("1st string");
        Str1.setPos(4);
        Str2 = Str1;
    }

    Str2.print();

    return 0;
}
