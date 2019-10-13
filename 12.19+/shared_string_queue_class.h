#ifndef _SHARED_STRING_QUEUE_CLASS_H_
#define _SHARED_STRING_QUEUE_CLASS_H_

#include <list>
#include <string>
#include <memory>
#include <initializer_list>

class SharedStringQueuePtr;

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

