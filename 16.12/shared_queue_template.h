#ifndef _SHARED_QUEUE_TEMPLATE_H_
#define _SHARED_QUEUE_TEMPLATE_H_

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

template <typename T>
class SharedQueuePtr;

// SharedQueue is a shared queue for T-type item,
// when original queue is copied,
// the new queue share the same queue with it,
// an operate will change them at the same time
template <typename T>
class SharedQueue
{
friend class SharedQueuePtr<T>;

public:
    SharedQueue();
    SharedQueue(const std::initializer_list<T>& initList);
    ~SharedQueue() = default;
    SharedQueue(SharedQueue<T>& originalQueue) = default;
    SharedQueue(SharedQueue<T>&& originalQueue) = default;
    SharedQueue& operator=(SharedQueue<T>& originalQueue) = default;
    SharedQueue& operator=(SharedQueue<T>&& originalQueue) = default;

    void pushItem(const T& newItem);
    void pushItem(T&& newItem);
    void popItem();
    const T& frontItem() const;
    T& frontItem();
    size_t size() const { return m_SharedQueueImpl->size(); }
    bool isEmpty() const { return m_SharedQueueImpl->empty(); }

private:
    std::shared_ptr<std::vector<T>> m_SharedQueueImpl;
};

template <typename T>
SharedQueue<T>::SharedQueue()
    : m_SharedQueueImpl{std::make_shared<std::vector<T>>()}
{
}

template <typename T>
SharedQueue<T>::SharedQueue(const std::initializer_list<T>& initList)
    : m_SharedQueueImpl{std::make_shared<std::vector<T>>(initList)}
{
}

template <typename T>
void SharedQueue<T>::pushItem(const T& newItem)
{
    m_SharedQueueImpl->push_back(newItem);
}

template <typename T>
void SharedQueue<T>::pushItem(T&& newItem)
{
    m_SharedQueueImpl->push_back(std::move(newItem));
}

template <typename T>
void SharedQueue<T>::popItem()
{
    if (isEmpty())
    {
        //do nothing
    }
    else
    {
        auto itrBeg = m_SharedQueueImpl->begin();
        m_SharedQueueImpl->erase(itrBeg);
    }
}

template <typename T>
const T& SharedQueue<T>::frontItem() const
{
    if (isEmpty())
    {
        throw std::runtime_error("Error: queue is empty.");
    }
    else
    {
        return *(m_SharedQueueImpl->begin());
    }
}

template <typename T>
T& SharedQueue<T>::frontItem()
{
    if (isEmpty())
    {
        throw std::runtime_error("Error: queue is empty.");
    }
    else
    {
        return *(m_SharedQueueImpl->begin());
    }
}

#endif

