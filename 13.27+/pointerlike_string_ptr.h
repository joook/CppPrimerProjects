#include <string>
#include <memory>

class StrPtr
{
public:
    StrPtr(const std::string &InitStr);

    StrPtr(StrPtr &InitPtr);

    StrPtr & operator=(StrPtr &InitPtr);

    ~StrPtr();

    void print();

    void setPos(size_t NewPos) { m_Pos = NewPos; }

private:
    std::string *m_StrPtr;
    size_t *m_PtrCount; //count how many StrPtr is pointing to this string
    size_t m_Pos;
};

