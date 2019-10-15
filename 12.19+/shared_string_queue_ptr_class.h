#ifndef _SHARED_STRING_QUEUE_CLASS_PTR_H_
#define _SHARED_STRING_QUEUE_CLASS_PTR_H_

#include <list>
#include <string>
#include <memory>
#include "shared_string_queue_class.h"

//SharedStringQueuePtr is a pointer to SharedStringQueue,
//the usage of QueuePtr is the same with Queue,
//like push(), pop(), front()...
//except that QueuePtr could point to nothing,
//and in this condition dereferencing it will throw an exception.
//Thus the right way to use QueuePtr is to use it in a try-catch statement.
class SharedStringQueuePtr
{
public:
    SharedStringQueuePtr();
    SharedStringQueuePtr(SharedStringQueue Queue);
    ~SharedStringQueuePtr();

    bool isNull();
    std::shared_ptr<std::list<std::string>> getQueue();
    void pushStr(const std::string &NewStr);
    void popStr();
    const std::string &frontStr();
    size_t size();
    bool isEmpty();

private:
    std::weak_ptr<std::list<std::string>> m_WeakPtr;
};

#endif
