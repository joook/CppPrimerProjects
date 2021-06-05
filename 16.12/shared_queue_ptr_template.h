#ifndef _SHARED_QUEUE_PTR_TEMPLATE_H_
#define _SHARED_QUEUE_PTR_TEMPLATE_H_

#include <vector>
#include <string>
#include <memory>

#include "shared_queue_template.h"

// SharedQueuePtr is a pointer to SharedQueue,
// the usage of SharedQueuePtr is the same with SharedQueue,
// like push(), pop(), front()...
// except that QueuePtr could point to nothing,
// and in this condition dereferencing it will throw an exception.
// Thus the right way to use SharedQueuePtr is to use it in a try-catch statement.
template <typename T>
class SharedQueuePtr
{
public:
    SharedQueuePtr();
    SharedQueuePtr(const SharedQueue<T>& queue);
    ~SharedQueuePtr() = default;
    SharedQueuePtr(SharedQueuePtr<T>& originalPtr) = default;
    SharedQueuePtr(SharedQueuePtr<T>&& originalPtr) = default;
    SharedQueuePtr& operator=(SharedQueuePtr<T>& originalPtr) = default;
    SharedQueuePtr& operator=(SharedQueuePtr<T>&& originalPtr) = default;

    bool isNull() const { return m_SharedQueuePtrImpl.expired(); }
    const std::shared_ptr<std::vector<T>> getQueue() const;
    std::shared_ptr<std::vector<T>> getQueue();
    void pushItem(const T& newItem) { getQueue()->push_back(newItem); }
    void pushItem(T&& newItem) { getQueue()->push_back(std::move(newItem)); }
    void popItem();
    const T& frontItem() const;
    T& frontItem();
    size_t size() const { return getQueue()->size(); }
    bool isEmpty() const { return getQueue()->empty(); }

private:
    std::weak_ptr<std::vector<T>> m_SharedQueuePtrImpl;
};

template <typename T>
SharedQueuePtr<T>::SharedQueuePtr()
    :m_SharedQueuePtrImpl{}
{
}

template <typename T>
SharedQueuePtr<T>::SharedQueuePtr(const SharedQueue<T>& queue)
    :m_SharedQueuePtrImpl{queue.m_SharedQueueImpl}
{
}

template <typename T>
const std::shared_ptr<std::vector<T>> SharedQueuePtr<T>::getQueue() const
{
    auto tmpSharedPtr = m_SharedQueuePtrImpl.lock();
    if (tmpSharedPtr)
    {
        return tmpSharedPtr;
    }
    else
    {
        throw std::runtime_error("Error: queue pointer is null.");
    }
}

template <typename T>
std::shared_ptr<std::vector<T>> SharedQueuePtr<T>::getQueue()
{
    auto tmpSharedPtr = m_SharedQueuePtrImpl.lock();
    if (tmpSharedPtr)
    {
        return tmpSharedPtr;
    }
    else
    {
        throw std::runtime_error("Error: queue pointer is null.");
    }
}

template <typename T>
void SharedQueuePtr<T>::popItem()
{
    auto tmpQueue = getQueue();
    if (tmpQueue->empty())                                                     
    {
        //do nothing
    }
    else
    {
        auto itrBeg = tmpQueue->begin();
        tmpQueue->erase(itrBeg);
    }
}

template <typename T>
const T& SharedQueuePtr<T>::frontItem() const
{
    auto tmpQueue = getQueue();
    if (tmpQueue->empty())
    {
        throw std::runtime_error("Error: queue is empty.");
    }
    else
    {
        return *(tmpQueue->begin());
    }
}

template <typename T>
T& SharedQueuePtr<T>::frontItem()
{
    auto tmpQueue = getQueue();
    if (tmpQueue->empty())
    {
        throw std::runtime_error("Error: queue is empty.");
    }
    else
    {
        return *(tmpQueue->begin());
    }
}

#endif
