#ifndef _SHARED_STRING_QUEUE_CLASS_PTR_H_
#define _SHARED_STRING_QUEUE_CLASS_PTR_H_

#include <list>
#include <string>
#include <memory>
#include "shared_string_queue_class.h"

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
