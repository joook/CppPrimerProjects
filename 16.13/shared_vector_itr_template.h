#ifndef _SHARED_VECTOR_ITR_TEMPLATE_H_
#define _SHARED_VECTOR_ITR_TEMPLATE_H_

#include <vector>
#include <memory>

#include "shared_vector_template.h"

template <typename T>
bool operator== (const SharedVectorItr<T>& itr1, const SharedVectorItr<T>& itr2);
template <typename T>
bool operator!= (const SharedVectorItr<T>& itr1, const SharedVectorItr<T>& itr2);
template <typename T>
bool operator< (const SharedVectorItr<T>& itr1, const SharedVectorItr<T>& itr2);
template <typename T>
bool operator> (const SharedVectorItr<T>& itr1, const SharedVectorItr<T>& itr2) ;

// SharedVectorItr is a iterator to a T-type SharedVector item,
// the vector may not exist, and the item may not exist either,
// in both cases, an exception would be throwed if you try to access the item.
template <typename T>
class SharedVectorItr
{
friend bool operator== <T>(const SharedVectorItr<T>& itr1, const SharedVectorItr<T>& itr2);
friend bool operator!= <T>(const SharedVectorItr<T>& itr1, const SharedVectorItr<T>& itr2);
friend bool operator< <T>(const SharedVectorItr<T>& itr1, const SharedVectorItr<T>& itr2);
friend bool operator> <T>(const SharedVectorItr<T>& itr1, const SharedVectorItr<T>& itr2);

public:
    SharedVectorItr();
    SharedVectorItr(const SharedVector<T>& vec, size_t pos);
    ~SharedVectorItr() = default;
    SharedVectorItr(SharedVectorItr<T>& originalItr) = default;
    SharedVectorItr(SharedVectorItr<T>&& originalItr) = default;
    SharedVectorItr& operator=(SharedVectorItr<T>& originalItr) = default;
    SharedVectorItr& operator=(SharedVectorItr<T>&& originalItr) = default;

    //bool isNull() const { return m_SharedVectorPtr.expired(); }
    const std::shared_ptr<std::vector<T>> getVector() const;
    std::shared_ptr<std::vector<T>> getVector();

    const T& operator*() const;
    T& operator*();
    SharedVectorItr& operator++() { m_CurrentPosition++; }
    SharedVectorItr& operator++(int) { m_CurrentPosition++; }
    SharedVectorItr& operator--()
    {
        if (m_CurrentPosition > 0)
        {
            m_CurrentPosition--;
        }
        else
        {
            // do nothing
        }
    }

private:
    bool checkSize(size_t pos) const;

private:
    std::weak_ptr<std::vector<T>> m_SharedVectorPtr;
    size_t m_CurrentPosition;
};

template <typename T>
SharedVectorItr<T>::SharedVectorItr()
    : m_SharedVectorPtr{}
    , m_CurrentPosition{0}
{
}

template <typename T>
SharedVectorItr<T>::SharedVectorItr(const SharedVector<T>& vec, size_t pos)
    : m_SharedVectorPtr{vec.m_SharedVectorImpl}
    , m_CurrentPosition{pos}
{
}

template <typename T>
const std::shared_ptr<std::vector<T>> SharedVectorItr<T>::getVector() const
{
    auto tmpSharedPtr = m_SharedVectorPtr.lock();
    if (tmpSharedPtr)
    {
        return tmpSharedPtr;
    }
    else
    {
        throw std::runtime_error("Error: shared vector doesn't exist.");
    }
}

template <typename T>
std::shared_ptr<std::vector<T>> SharedVectorItr<T>::getVector()
{
    auto tmpSharedPtr = m_SharedVectorPtr.lock();
    if (tmpSharedPtr)
    {
        return tmpSharedPtr;
    }
    else
    {
        throw std::runtime_error("Error: shared vector doesn't exist.");
    }
}

template <typename T>
bool SharedVectorItr<T>::checkSize(size_t pos) const
{
    if (pos < getVector()->size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
const T& SharedVectorItr<T>::operator* () const
{
    if (checkSize(m_CurrentPosition))
    {
        return getVector()->at(m_CurrentPosition);
    }
    else
    {
        throw std::runtime_error("Error: shared vector iterator out of range.");
    }
}

template <typename T>
T&  SharedVectorItr<T>::operator* ()
{
    if (checkSize(m_CurrentPosition))
    {
        return getVector()->at(m_CurrentPosition);
    }
    else
    {
        throw std::runtime_error("Error: shared vector iterator out of range.");
    }
}

template <typename T>
bool operator== (const SharedVectorItr<T>& itr1, const SharedVectorItr<T>& itr2)
{
    return (itr1.m_CurrentPosition == itr2.m_CurrentPosition);
}

template <typename T>
bool operator!= (const SharedVectorItr<T>& itr1, const SharedVectorItr<T>& itr2)
{
    return (itr1.m_CurrentPosition != itr2.m_CurrentPosition);
}

template <typename T>
bool operator< (const SharedVectorItr<T>& itr1, const SharedVectorItr<T>& itr2)
{
    return (itr1.m_CurrentPosition < itr2.m_CurrentPosition);
}

template <typename T>
bool operator> (const SharedVectorItr<T>& itr1, const SharedVectorItr<T>& itr2)
{
    return (itr1.m_CurrentPosition > itr2.m_CurrentPosition);
}

#endif
