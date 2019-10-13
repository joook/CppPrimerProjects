#include <iostream>
#include "shared_string_queue_class.h"
#include "shared_string_queue_ptr_class.h"

using namespace std;

SharedStringQueuePtr::SharedStringQueuePtr()
{
}

SharedStringQueuePtr::SharedStringQueuePtr(SharedStringQueue Queue)
: m_WeakPtr(Queue.m_SharedPtr)
{
}

SharedStringQueuePtr::~SharedStringQueuePtr()
{
}

bool SharedStringQueuePtr::isNull()
{
    return m_WeakPtr.expired();
}

shared_ptr<list<string>> SharedStringQueuePtr::getQueue()
{
    shared_ptr<list<string>> TempSharedPtr = m_WeakPtr.lock();
    if(TempSharedPtr)
    {
        return TempSharedPtr;
    }
    else
    {
        throw runtime_error("Error: queue pointer is null.");
    }
}

void SharedStringQueuePtr::pushStr(const string &NewStr)
{
    getQueue()->push_back(NewStr);
}

void SharedStringQueuePtr::popStr()
{
    auto TempQueue = getQueue();
    if(TempQueue->empty())
    {
        //do nothing
    }
    else
    {
        auto ItrBeg = TempQueue->begin();
        TempQueue->erase(ItrBeg);
    }
}

const string &SharedStringQueuePtr::frontStr()
{
    auto TempQueue = getQueue();
    if(TempQueue->empty())
    {
        throw runtime_error("Error: queue is empty.");
    }
    else
    {
        return *(TempQueue->begin());
    }
}

size_t SharedStringQueuePtr::size()
{
    return getQueue()->size();
}

bool SharedStringQueuePtr::isEmpty()
{
    return getQueue()->empty();
}

