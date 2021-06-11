#ifndef _MY_VECTOR_H_
#define _MY_VECTOR_H_ 

#include <memory>
#include <string>
#include <utility>
#include <initializer_list>
#include <iostream>

template <typename T>
class MyVector
{
public:
    MyVector();
    MyVector(std::initializer_list<T> initList);
    MyVector(const MyVector& oriVector);
    MyVector(MyVector&& oriVector) noexcept;
    MyVector& operator=(const MyVector& oriVector);
    MyVector& operator=(MyVector&& oriVector) noexcept;
    ~MyVector();

public:
    void pushBack(const T& newItem);
    void pushBack(T&& newItem);
    T* begin() { return m_First; }
    T* end() { return m_FirstFree; }
    size_t size() { return (m_FirstFree-m_First); }
    size_t capacity() { return (m_Last-m_First); }
    void resize(size_t newSize);
    void resize(size_t newSize, const T& initItem);
    void reserve(size_t newCapacity);

private:
    void checkMemory();
    void reallocateMemory();
    void reserveMemory(size_t newCapacity);
    std::pair<T*, T*> copyMemory(const T* oriBegin, const T* oriEnd);
    void freeMemory();

private:
    static std::allocator<T> m_Allocator;
    T* m_First;
    T* m_FirstFree;
    T* m_Last;
};

template <typename T>
std::allocator<T> MyVector<T>::m_Allocator{};

template <typename T>
MyVector<T>::MyVector()
: m_First(nullptr)
, m_FirstFree(nullptr)
, m_Last(nullptr)
{
    std::cout << "A MyVector<T> is constructed." << std::endl;
    std::cout << "Size: " << size() << ", capacity: " << capacity() << std::endl;
}

template <typename T>
MyVector<T>::MyVector(std::initializer_list<T> initList)
: m_First(nullptr)
, m_FirstFree(nullptr)
, m_Last(nullptr)
{
    /*
    for(auto itr = initList.begin(); itr != initList.end(); itr++)
    {
        pushBack(*itr);
    }
    */
    if(initList.begin() != initList.end())
    {
        //iterator can be used as a pointer
        auto newMemory = copyMemory(initList.begin(), initList.end());
        m_First = newMemory.first;
        m_FirstFree = newMemory.second;
        m_Last = newMemory.second;
    }
    else
    {
    }

    std::cout << "A MyVector<T> is constructed." << std::endl;
    std::cout << "Size: " << size() << ", capacity: " << capacity() << std::endl;
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& oriVector)
{
    auto newMemory = copyMemory(oriVector.m_First, oriVector.m_FirstFree);
    m_First = newMemory.first;
    m_FirstFree = newMemory.second;
    m_Last = newMemory.second;

    std::cout << "A MyVector<T> is copied." << std::endl;
    std::cout << "Size: " << size() << ", capacity: " << capacity() << std::endl;
}

template <typename T>
MyVector<T>::MyVector(MyVector<T>&& oriVector) noexcept
{
    m_First = oriVector.m_First;
    m_FirstFree = oriVector.m_FirstFree;
    m_Last = oriVector.m_FirstFree;

    oriVector.m_First = nullptr;
    oriVector.m_FirstFree = nullptr;
    oriVector.m_FirstFree = nullptr;

    std::cout << "A MyVector<T> is moved." << std::endl;
    std::cout << "Size: " << size() << ", capacity: " << capacity() << std::endl;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& oriVector)
{
    auto newMemory = copyMemory(oriVector.m_First, oriVector.m_FirstFree);

    freeMemory();

    m_First = newMemory.first;
    m_FirstFree = newMemory.second;
    m_Last = newMemory.second;

    std::cout << "A MyVector<T> is assigned." << std::endl;
    std::cout << "Size: " << size() << ", capacity: " << capacity() << std::endl;

    return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& oriVector) noexcept
{
    if(this != &oriVector)
    {
        freeMemory();

        m_First = oriVector.m_First;
        m_FirstFree = oriVector.m_FirstFree;
        m_Last = oriVector.m_FirstFree;

        oriVector.m_First = nullptr;
        oriVector.m_FirstFree = nullptr;
        oriVector.m_FirstFree = nullptr;
    }
    else
    {
    }

    std::cout << "A MyVector<T> is move-assigned." << std::endl;
    std::cout << "Size: " << size() << ", capacity: " << capacity() << std::endl;

    return *this;
}

template <typename T>
MyVector<T>::~MyVector()
{
    freeMemory();
}

template <typename T>
void MyVector<T>::pushBack(const T& newItem)
{
    checkMemory();
    m_Allocator.construct(m_FirstFree, newItem);
    m_FirstFree++;

    std::cout << "A T is pushed-back." << std::endl;
    std::cout << "Size: " << size() << ", capacity: " << capacity() << std::endl;
}

template <typename T>
void MyVector<T>::pushBack(T&& newItem)
{
    checkMemory();
    m_Allocator.construct(m_FirstFree, std::move(newItem));
    m_FirstFree++;

    std::cout << "A T is move-pushed-back." << std::endl;
    std::cout << "Size: " << size() << ", capacity: " << capacity() << std::endl;
}

template <typename T>
void MyVector<T>::resize(size_t newSize)
{
    resize(newSize, T{});
}

template <typename T>
void MyVector<T>::resize(size_t newSize, const T& initItem)
{
    while(newSize > capacity())
    {
        reallocateMemory();
    }

    if(newSize < size())
    {
        for(int i = 0; i != size()-newSize; i++)
        {
            m_Allocator.destroy(m_First+newSize+i);
        }
        m_FirstFree = m_First+newSize;
    }
    else
    {
        for(int i = 0; i != newSize-size(); i++)
        {
            m_Allocator.construct(m_FirstFree+i, initItem);
        }
        m_FirstFree = m_First+newSize;
    }
}

template <typename T>
void MyVector<T>::reserve(size_t newCapacity)
{
    reserveMemory(newCapacity);
}

template <typename T>
void MyVector<T>::checkMemory()
{
    // this check function is only for pushBack, 
    // if you need to insert more than 1 item, you need another check function
    if(size() == capacity())
    {
        reallocateMemory();
    }
    else
    {
    }
}

template <typename T>
void MyVector<T>::reallocateMemory()
{
    size_t newCapacity;
    if(capacity() != 0)
    {
        newCapacity = 2*capacity();
    }
    else
    {
        newCapacity = 1;
    }

    reserveMemory(newCapacity);
}

template <typename T>
void MyVector<T>::reserveMemory(size_t newCapacity)
{
    if(newCapacity > capacity())
    {
        T* newFirst = m_Allocator.allocate(newCapacity);

        T* target = newFirst;
        T* source = m_First;
        for(size_t i = 0; i != size(); i++)
        {
            m_Allocator.construct(target, std::move(*source));
            target++;
            source++;
        }

        freeMemory();

        m_First = newFirst;
        m_FirstFree = target;
        m_Last = newFirst+newCapacity;
    }
    else
    {
        //do nothing
    }
}

template <typename T>
std::pair<T*, T*> MyVector<T>::copyMemory(const T* oriBegin, const T* oriEnd)
{
    std::pair<T*, T*> newMemory = {nullptr, nullptr};

    if((oriBegin != nullptr) && (oriBegin <= oriEnd))
    {
        size_t size = oriEnd-oriBegin;
        T* newBegin = m_Allocator.allocate(size);
        /*
        auto target = newBegin;
        auto source = oriBegin;
        for(size_t i = 0; i != size; i++)
        {
            m_Allocator.construct(target, *source);
            target++;
            source++;
        }
        */

        //pointer can be used as an iterator
        std::uninitialized_copy(oriBegin, oriEnd, newBegin);

        newMemory.first = newBegin;
        newMemory.second = newBegin+size;
    }
    else
    {
    }

    return newMemory;
}

template <typename T>
void MyVector<T>::freeMemory()
{
    if(m_First != nullptr)
    {
        for(T* ptr = m_First; ptr != m_FirstFree; ptr++)
        {
            m_Allocator.destroy(ptr);
        }
        m_Allocator.deallocate(m_First, (m_Last-m_First));
    }
    else
    {
        //do nothing
    }
}

#endif
