#ifndef STRING_VECTOR_CLASS_H
#define STRING_VECTOR_CLASS_H

#include <memory>
#include <string>
#include <utility>
#include <initializer_list>

class StrVec
{
public:
    StrVec();
    StrVec(std::initializer_list<std::string> InitList);
    StrVec(const StrVec &OriStrVec);
    StrVec & operator=(const StrVec &OriStrVec);
    StrVec(StrVec &&OriStrVec) noexcept;
    StrVec & operator=(StrVec &&OriStrVec) noexcept;
    ~StrVec();
public:
    void pushBack(const std::string &NewStr);
    void pushBack(std::string &&NewStr);
    std::string *begin() { return m_First; }
    std::string *end() { return m_FirstFree; }
    size_t size() { return (m_FirstFree-m_First); }
    size_t capacity() { return (m_Last-m_First); }
    void resize(size_t NewSize);
    void resize(size_t NewSize, const std::string &InitStr);
    void reserve(size_t NewCapacity);
private:
    void checkMemory();
    void reallocateMemory();
    void reserveMemory(size_t NewCapacity);
    std::pair<std::string *, std::string *> copyMemory(const std::string *OriBegin, const std::string *OriEnd);
    void freeMemory();
private:
    static std::allocator<std::string> m_Allocator;
    std::string *m_First;
    std::string *m_FirstFree;
    std::string *m_Last;
};

#endif
