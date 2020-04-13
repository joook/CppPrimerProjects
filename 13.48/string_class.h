#ifndef STRING_CLASS_H_
#define STRING_CLASS_H_

#include <memory>
#include <utility>

class Str
{
public:
    Str();
    Str(const char *StrPtr);
    Str(size_t Length, const char Char);
    Str(const Str &OriStr);
    Str(Str &&OriStr) noexcept;
    Str & operator=(const Str &OriStr);
    ~Str();
public:
    void pushBack(const char &NewChar);
    char *begin() { return m_First; }
    char *end() { return m_FirstFree; }
    char &at(size_t Pos);
    size_t size() { return (m_FirstFree-m_First); }
    size_t capacity() { return (m_Last-m_First); }
    const char *c_str();
private:
    void checkMemory();
    void reallocateMemory();
    void reserveMemory(size_t NewCapacity);
    std::pair<char *, char *> copyMemory(const char *OriBegin, const char *OriEnd);
    void freeMemory();
private:
    static std::allocator<char> m_Allocator;
    char *m_First;
    char *m_FirstFree;
    char *m_Last;
};

#endif
