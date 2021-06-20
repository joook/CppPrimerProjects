#ifndef _MY_SHARED_PTR_H_
#define _MY_SHARED_PTR_H_

template <typename T>
class MySharedPtr;

template <typename T, typename... Args>
MySharedPtr<T> makeShared(Args&&... args);

template <typename T>
class MySharedPtr
{
template <typename... Args>
friend MySharedPtr<T> makeShared(Args&&... args);

template <typename V, typename U>
friend bool operator== (const MySharedPtr<V>& ptr1, const MySharedPtr<U>& ptr2);
template <typename V, typename U>
friend bool operator!= (const MySharedPtr<V>& ptr1, const MySharedPtr<U>& ptr2);
template <typename V, typename U>
friend bool operator< (const MySharedPtr<V>& ptr1, const MySharedPtr<U>& ptr2);
template <typename V, typename U>
friend bool operator<= (const MySharedPtr<V>& ptr1, const MySharedPtr<U>& ptr2);
template <typename V, typename U>
friend bool operator> (const MySharedPtr<V>& ptr1, const MySharedPtr<U>& ptr2);
template <typename V, typename U>
friend bool operator>= (const MySharedPtr<V>& ptr1, const MySharedPtr<U>& ptr2);

public:
    MySharedPtr();
    // not explicit, so that you can use a nullptr as a MySharedPtr implicitly
    // bug here, can not use it this way
    MySharedPtr(std::nullptr_t initPtr) : MySharedPtr() {}
    // explicit, so that you can not use a T* as a MySharedPtr implicitly,  
    // you have to call this function to construct a MySharedPtr 
    // also, a pointer used to initialize a MySharedPtr must point to dynamic memory, 
    // i.e. it is returned by new
    explicit MySharedPtr(T* initPtr);
    MySharedPtr(const MySharedPtr& oriPtr);
    MySharedPtr(MySharedPtr&& oriPtr);
    MySharedPtr& operator= (const MySharedPtr& oriPtr);
    MySharedPtr& operator= (MySharedPtr&& oriPtr);
    ~MySharedPtr();

    inline T* get() const { return m_Ptr; }

    inline T& operator* () const;
    inline T* operator-> () const;

    inline size_t useCount() const { return m_UseCount; }
    inline operator bool () const { return (m_Ptr != nullptr); }

private:
    inline void show() const;

private:
    T* m_Ptr;
    size_t* m_UseCount;
};

template <typename T>
MySharedPtr<T>::MySharedPtr()
    : m_Ptr{nullptr}
    , m_UseCount{new size_t(0)}
{
    std::cout << "MySharedPtr<T> constructed." << std::endl;
    show();
}

template <typename T>
MySharedPtr<T>::MySharedPtr(T* initPtr)
    : m_Ptr{initPtr}
    , m_UseCount{new size_t(1)}
{
    std::cout << "MySharedPtr<T> constructed." << std::endl;

    if (m_Ptr == nullptr)
    {
        *m_UseCount = 0;
    }
    else
    {
        // do nothing
    }

    show();
}

template <typename T>
MySharedPtr<T>::MySharedPtr(const MySharedPtr<T>& oriPtr)
    : m_Ptr{oriPtr.m_Ptr}
    , m_UseCount{oriPtr.m_UseCount}
{
    std::cout << "MySharedPtr<T> copy-constructed." << std::endl;

    if (m_Ptr == nullptr)
    {
        // do not increase use count
    }
    else
    {
        // increase use count
        (*m_UseCount)++;
    }

    show();
}

template <typename T>
MySharedPtr<T>::MySharedPtr(MySharedPtr<T>&& oriPtr)
    : m_Ptr{oriPtr.m_Ptr}
    , m_UseCount{oriPtr.m_UseCount}
{
    std::cout << "MySharedPtr<T> move-constructed." << std::endl;

    oriPtr.m_Ptr = nullptr;
    oriPtr.m_UseCount = nullptr;
    show();
}

template <typename T>
MySharedPtr<T>& MySharedPtr<T>::operator= (const MySharedPtr<T>& oriPtr)
{
    std::cout << "MySharedPtr<T> copy-assigned." << std::endl;

    if (oriPtr.m_Ptr == nullptr)
    {
        // do not increase use count
    }
    else
    {
        // increase use count
        (*(oriPtr.m_UseCount))++;
    }

    if (m_Ptr == nullptr)
    {
        // do not decrease use count
    }
    else
    {
        // decrease use count
        (*m_UseCount)--;
    }

    if(*m_UseCount == 0)
    {
        delete m_Ptr;
        delete m_UseCount;
    	std::cout << "MySharedPtr<T> source deleted." << std::endl;
    }
    else
    {
        // do nothing
    }

    m_Ptr = oriPtr.m_Ptr;
    m_UseCount = oriPtr.m_UseCount;
    show();

    return *this;
}

template <typename T>
MySharedPtr<T>& MySharedPtr<T>::operator= (MySharedPtr<T>&& oriPtr)
{
    std::cout << "MySharedPtr<T> move-assigned." << std::endl;

    if (&oriPtr == this)
    {
        // do nothing
        return *this;
    }
    else
    {
        // go on
    }

    if (m_Ptr == nullptr)
    {
        // do not decrease use count
    }
    else
    {
        // decrease use count
        (*m_UseCount)--;
    }

    if(*m_UseCount == 0)
    {
        delete m_Ptr;
        delete m_UseCount;
    	std::cout << "MySharedPtr<T> source deleted." << std::endl;
    }
    else
    {
        // do nothing
    }

    m_Ptr = oriPtr.m_Ptr;
    m_UseCount = oriPtr.m_UseCount;
    oriPtr.m_Ptr = nullptr;
    oriPtr.m_UseCount = nullptr;
    show();

    return *this;
}

template <typename T>
MySharedPtr<T>::~MySharedPtr()
{
    std::cout << "MySharedPtr<T> destructed." << std::endl;

    if (m_Ptr == nullptr)
    {
        // do not decrease use count
    }
    else
    {
        // decrease use count
        (*m_UseCount)--;
    }

    if(*m_UseCount == 0)
    {
        delete m_Ptr;
        delete m_UseCount;
    	std::cout << "MySharedPtr<T> source deleted." << std::endl;
    }
    else
    {
        // do nothing
    }
}

template <typename T>
T& MySharedPtr<T>::operator* () const
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

template <typename T>
T* MySharedPtr<T>::operator-> () const
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

template <typename T>
void MySharedPtr<T>::show() const
{
    std::cout << "m_Ptr: " << m_Ptr << std::endl;
    std::cout << "*m_UseCount: " << *m_UseCount << std::endl;
}

template <typename T, typename... Args>
MySharedPtr<T> makeShared(Args&&... args)
{
    return MySharedPtr<T>(new T(std::forward<Args>(args)...));
}

template <typename T, typename U>
bool operator== (const MySharedPtr<T>& ptr1, const MySharedPtr<U>& ptr2)
{
    return (ptr1.m_Ptr == ptr2.m_Ptr);
}

template <typename T, typename U>
bool operator!= (const MySharedPtr<T>& ptr1, const MySharedPtr<U>& ptr2)
{
    return (ptr1.m_Ptr != ptr2.m_Ptr);
}

template <typename T, typename U>
bool operator< (const MySharedPtr<T>& ptr1, const MySharedPtr<U>& ptr2)
{
    return (ptr1.m_Ptr < ptr2.m_Ptr);
}

template <typename T, typename U>
bool operator<= (const MySharedPtr<T>& ptr1, const MySharedPtr<U>& ptr2)
{
    return (ptr1.m_Ptr <= ptr2.m_Ptr);
}

template <typename T, typename U>
bool operator> (const MySharedPtr<T>& ptr1, const MySharedPtr<U>& ptr2)
{
    return (ptr1.m_Ptr > ptr2.m_Ptr);
}

template <typename T, typename U>
bool operator>= (const MySharedPtr<T>& ptr1, const MySharedPtr<U>& ptr2)
{
    return (ptr1.m_Ptr >= ptr2.m_Ptr);
}

#endif
