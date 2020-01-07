#ifndef STRING_VECTOR_CLASS_H
#define STRING_VECTOR_CLASS_H

#include <memory>
#include <string>
#include <utility>

class StrVec
{
public:
    StrVec();
    StrVec(const StrVec &OriStrVec);
    StrVec & operator=(const StrVec &OriStrVec);
    ~StrVec();
public:
    void pushBack(const std::string &NewStr);
    std::string *begin() { return m_First; }
    std::string *end() { return m_FirstFree; }
    size_t size() { return (m_FirstFree-m_First); }
    size_t capacity() { return (m_Last-m_First); }
private:
    void checkCapacity();
    void reallocateMemory();
    std::pair<std::string *, std::string *> copyMemory(std::string *OriBegin, std::string *OriEnd);
    void freeMemory();
private:
    static std::allocator<std::string> m_Allocator;
    std::string *m_First;
    std::string *m_FirstFree;
    std::string *m_Last;
};

#endif
