#ifndef _MY_UNIQUE_PTR_H_
#define _MY_UNIQUE_PTR_H_

#include <functional>

template <typename T, typename D = std::function<void(T*)>>
class MyUniquePtr
{
template <typename V, typename U>
friend bool operator== (const MyUniquePtr<V>& ptr1, const MyUniquePtr<U>& ptr2);
template <typename V>
friend bool operator== (std::nullptr_t ptr1, const MyUniquePtr<V>& ptr2);
template <typename V>
friend bool operator== (const MyUniquePtr<V>& ptr1, std::nullptr_t ptr2);
template <typename V, typename U>
friend bool operator!= (const MyUniquePtr<V>& ptr1, const MyUniquePtr<U>& ptr2);
template <typename V>
friend bool operator!= (std::nullptr_t ptr1, const MyUniquePtr<V>& ptr2);
template <typename V>
friend bool operator!= (const MyUniquePtr<V>& ptr1, std::nullptr_t ptr2);
template <typename V, typename U>
friend bool operator< (const MyUniquePtr<V>& ptr1, const MyUniquePtr<U>& ptr2);
template <typename V>
friend bool operator< (std::nullptr_t ptr1, const MyUniquePtr<V>& ptr2);
template <typename V>
friend bool operator< (const MyUniquePtr<V>& ptr1, std::nullptr_t ptr2);
template <typename V, typename U>
friend bool operator<= (const MyUniquePtr<V>& ptr1, const MyUniquePtr<U>& ptr2);
template <typename V>
friend bool operator<= (std::nullptr_t ptr1, const MyUniquePtr<V>& ptr2);
template <typename V>
friend bool operator<= (const MyUniquePtr<V>& ptr1, std::nullptr_t ptr2);
template <typename V, typename U>
friend bool operator> (const MyUniquePtr<V>& ptr1, const MyUniquePtr<U>& ptr2);
template <typename V>
friend bool operator> (std::nullptr_t ptr1, const MyUniquePtr<V>& ptr2);
template <typename V>
friend bool operator> (const MyUniquePtr<V>& ptr1, std::nullptr_t ptr2);
template <typename V, typename U>
friend bool operator>= (const MyUniquePtr<V>& ptr1, const MyUniquePtr<U>& ptr2);
template <typename V>
friend bool operator>= (std::nullptr_t ptr1, const MyUniquePtr<V>& ptr2);
template <typename V>
friend bool operator>= (const MyUniquePtr<V>& ptr1, std::nullptr_t ptr2);

public:
    MyUniquePtr();
    // not explicit, so that you can use a nullptr as a MyUniquePtr<T> implicitly
    MyUniquePtr(std::nullptr_t initPtr) : MyUniquePtr() {}
    // explicit, so that you can not use a T* as a MyUniquePtr<T> implicitly,  
    // you have to call this function to construct a MyUniquePtr<T> 
    // also, a pointer used to initialize a MyUniquePtr<T> must point to dynamic memory, 
    // i.e. it is returned by new
    explicit MyUniquePtr(T* initPtr);
    MyUniquePtr(T* initPtr, const D& deleter);
    MyUniquePtr(const MyUniquePtr& oriPtr) = delete;
    MyUniquePtr(MyUniquePtr&& oriPtr);
    MyUniquePtr& operator= (const MyUniquePtr& oriPtr) = delete;
    MyUniquePtr& operator= (MyUniquePtr&& oriPtr);
    ~MyUniquePtr();

    inline T* get() const { return m_Ptr; }

    inline T& operator* () const;
    inline T* operator-> () const;

    inline operator bool () const { return (m_Ptr != nullptr); }

private:
    inline void show();

private:
    T* m_Ptr;
    D m_Deleter;
};

template <typename T, typename D>
MyUniquePtr<T, D>::MyUniquePtr()
    : m_Ptr{nullptr}
    , m_Deleter([](T* ptr){ delete ptr; })
{
    std::cout << "MyUniquePtr<T> constructed." << std::endl;
    show();
}

template <typename T, typename D>
MyUniquePtr<T, D>::MyUniquePtr(T* initPtr)
    : m_Ptr{initPtr}
    , m_Deleter([](T* ptr){ delete ptr; })
{
    std::cout << "MyUniquePtr<T> constructed." << std::endl;
    show();
}

template <typename T, typename D>
MyUniquePtr<T, D>::MyUniquePtr(T* initPtr, const D& deleter)
    : m_Ptr{initPtr}
    , m_Deleter(deleter)
{
    std::cout << "MyUniquePtr<T> constructed." << std::endl;
    show();
}

template <typename T, typename D>
MyUniquePtr<T, D>::MyUniquePtr(MyUniquePtr<T, D>&& oriPtr)
    : m_Ptr{oriPtr.m_Ptr}
    , m_Deleter{oriPtr.m_Deleter}
{
    std::cout << "MyUniquePtr<T> move-constructed." << std::endl;

    oriPtr.m_Ptr = nullptr;
    show();
}

template <typename T, typename D>
MyUniquePtr<T, D>& MyUniquePtr<T, D>::operator= (MyUniquePtr<T, D>&& oriPtr)
{
    std::cout << "MyUniquePtr<T> move-assigned." << std::endl;

    if (&oriPtr == this)
    {
        // do nothing
        return *this;
    }
    else
    {
        // go on
    }

    std::cout << "MyUniquePtr<T> source deleted." << std::endl;
    m_Deleter(m_Ptr);

    m_Ptr = oriPtr.m_Ptr;
    m_Deleter = oriPtr.m_Deleter;
    oriPtr.m_Ptr = nullptr;
    show();

    return *this;
}

template <typename T, typename D>
MyUniquePtr<T, D>::~MyUniquePtr()
{
    std::cout << "MyUniquePtr<T> destructed." << std::endl;

    std::cout << "MyUniquePtr<T> source deleted." << std::endl;
    m_Deleter(m_Ptr);
}

template <typename T, typename D>
T& MyUniquePtr<T, D>::operator* () const
{
    if (m_Ptr == nullptr)
    {
        throw std::runtime_error("Error: null pointer.");
    }
    else
    {
        return *m_Ptr;
    }
}

template <typename T, typename D>
T* MyUniquePtr<T, D>::operator-> () const
{
    if (m_Ptr == nullptr)
    {
        throw std::runtime_error("Error: null pointer.");
    }
    else
    {
        return m_Ptr;
    }
}

template <typename T, typename D>
void MyUniquePtr<T, D>::show()
{
    std::cout << "m_Ptr: " << m_Ptr << std::endl;
}

template <typename V, typename U>
bool operator== (const MyUniquePtr<V>& ptr1, const MyUniquePtr<U>& ptr2)
{
    return (ptr1.m_Ptr == ptr2.m_Ptr);
}

template <typename V>
bool operator== (std::nullptr_t ptr1, const MyUniquePtr<V>& ptr2)
{
    return (nullptr == ptr2.m_Ptr);
}

template <typename V>
bool operator== (const MyUniquePtr<V>& ptr1, std::nullptr_t ptr2)
{
    return (ptr1.m_Ptr == nullptr);
}

template <typename V, typename U>
bool operator!= (const MyUniquePtr<V>& ptr1, const MyUniquePtr<U>& ptr2)
{
    return (ptr1.m_Ptr != ptr2.m_Ptr);
}

template <typename V>
bool operator!= (std::nullptr_t ptr1, const MyUniquePtr<V>& ptr2)
{
    return (nullptr != ptr2.m_Ptr);
}

template <typename V>
bool operator!= (const MyUniquePtr<V>& ptr1, std::nullptr_t ptr2)
{
    return (ptr1.m_Ptr != nullptr);
}

template <typename V, typename U>
bool operator< (const MyUniquePtr<V>& ptr1, const MyUniquePtr<U>& ptr2)
{
    return (ptr1.m_Ptr < ptr2.m_Ptr);
}

template <typename V>
bool operator< (std::nullptr_t ptr1, const MyUniquePtr<V>& ptr2)
{
    return (nullptr < ptr2.m_Ptr);
}

template <typename V>
bool operator< (const MyUniquePtr<V>& ptr1, std::nullptr_t ptr2)
{
    return (ptr1.m_Ptr < nullptr);
}

template <typename V, typename U>
bool operator<= (const MyUniquePtr<V>& ptr1, const MyUniquePtr<U>& ptr2)
{
    return (ptr1.m_Ptr <= ptr2.m_Ptr);
}

template <typename V>
bool operator<= (std::nullptr_t ptr1, const MyUniquePtr<V>& ptr2)
{
    return (nullptr <= ptr2.m_Ptr);
}

template <typename V>
bool operator<= (const MyUniquePtr<V>& ptr1, std::nullptr_t ptr2)
{
    return (ptr1.m_Ptr <= nullptr);
}

template <typename V, typename U>
bool operator> (const MyUniquePtr<V>& ptr1, const MyUniquePtr<U>& ptr2)
{
    return (ptr1.m_Ptr > ptr2.m_Ptr);
}

template <typename V>
bool operator> (std::nullptr_t ptr1, const MyUniquePtr<V>& ptr2)
{
    return (nullptr > ptr2.m_Ptr);
}

template <typename V>
bool operator> (const MyUniquePtr<V>& ptr1, std::nullptr_t ptr2)
{
    return (ptr1.m_Ptr > nullptr);
}

template <typename V, typename U>
bool operator>= (const MyUniquePtr<V>& ptr1, const MyUniquePtr<U>& ptr2)
{
    return (ptr1.m_Ptr >= ptr2.m_Ptr);
}

template <typename V>
bool operator>= (std::nullptr_t ptr1, const MyUniquePtr<V>& ptr2)
{
    return (nullptr >= ptr2.m_Ptr);
}

template <typename V>
bool operator>= (const MyUniquePtr<V>& ptr1, std::nullptr_t ptr2)
{
    return (ptr1.m_Ptr >= nullptr);
}

#endif
