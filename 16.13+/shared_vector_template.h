#ifndef _SHARED_VECTOR_TEMPLATE_H_
#define _SHARED_VECTOR_TEMPLATE_H_

#include <vector>
#include <memory>
#include <initializer_list>

template <typename T>
class SharedVectorItr;

// SharedVector is a shared vector for T-type item,
// when original vector is copied,
// the new vector share the same vector with it,
// an operate will change them at the same time
template <typename T>
class SharedVector
{
friend class SharedVectorItr<T>;

public:
    SharedVector();
    SharedVector(const std::initializer_list<T>& initList);
    ~SharedVector() = default;
    SharedVector(const SharedVector<T>& originalVector) = default;
    SharedVector(SharedVector<T>&& originalVector) = default;
    SharedVector& operator=(const SharedVector<T>& originalVector) = default;
    SharedVector& operator=(SharedVector<T>&& originalVector) = default;

    const SharedVectorItr<T> begin() const { return SharedVectorItr<T>{*this, 0}; }
    SharedVectorItr<T> begin() { return SharedVectorItr<T>{*this, 0}; }
    const SharedVectorItr<T> end() const { return SharedVectorItr<T>{*this, size()}; }
    SharedVectorItr<T> end() { return SharedVectorItr<T>{*this, size()};}

    size_t size() const { return m_SharedVectorImpl->size(); }
    bool isEmpty() const { return m_SharedVectorImpl->empty(); }

    const T& frontItem() const { return m_SharedVectorImpl->front(); }
    T& frontItem() { return m_SharedVectorImpl->front(); }
    const T& backItem() const  { return m_SharedVectorImpl->back(); }
    T& backItem() { return m_SharedVectorImpl->back(); }
    const T& at(size_t i) const { return m_SharedVectorImpl->at(i); }
    T& at(size_t i) { return m_SharedVectorImpl->at(i); }

    void pushBackItem(const T& newItem) { m_SharedVectorImpl->push_back(newItem); }
    void pushBackItem(T&& newItem) { m_SharedVectorImpl->push_back(std::move(newItem)); }
    void popBackItem() { m_SharedVectorImpl->pop_back(); }

private:
    std::shared_ptr<std::vector<T>> m_SharedVectorImpl;
};

template <typename T>
SharedVector<T>::SharedVector()
    : m_SharedVectorImpl{std::make_shared<std::vector<T>>()}
{
}

template <typename T>
SharedVector<T>::SharedVector(const std::initializer_list<T>& initList)
    : m_SharedVectorImpl{std::make_shared<std::vector<T>>(initList)}
{
}

#endif

