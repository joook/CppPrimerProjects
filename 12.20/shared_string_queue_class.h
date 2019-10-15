#ifndef _SHARED_STRING_QUEUE_CLASS_H_
#define _SHARED_STRING_QUEUE_CLASS_H_

#include <list>
#include <string>
#include <memory>
#include <initializer_list>

class SharedStringQueuePtr;

//SharedStringQueue is a shared string queue,
//when original queue is copied,
//the new queue share the same queue with it,
//an operate will change them at the same time
class SharedStringQueue
{
friend class SharedStringQueuePtr;

public:
    SharedStringQueue();
    SharedStringQueue(std::initializer_list<std::string> InitList);
    ~SharedStringQueue() {}

    void pushStr(const std::string &NewStr);
    void popStr();
    const std::string &frontStr();
    size_t size();
    bool isEmpty();
private:
    std::shared_ptr<std::list<std::string>> m_SharedPtr;
};

#endif

