#include <list>
#include <string>
#include <memory>
#include <initializer_list>
#include "shared_string_queue_class.h"

using namespace std;

SharedStringQueue::SharedStringQueue()
: m_SharedPtr(make_shared<list<string>>())
{
}

SharedStringQueue::SharedStringQueue(initializer_list<string> InitList)
: m_SharedPtr(make_shared<list<string>>(InitList))
{
}

void SharedStringQueue::pushStr(const string &NewStr)
{
    m_SharedPtr->push_back(NewStr);
}

void SharedStringQueue::popStr()
{
    if(m_SharedPtr->empty())
    {
        //do nothing
    }
    else
    {
        auto ItrBeg = m_SharedPtr->begin();
        m_SharedPtr->erase(ItrBeg);
    }
}

const string &SharedStringQueue::frontStr()
{
    if(m_SharedPtr->empty())
    {
        throw runtime_error("Error: queue is empty.");
    }
    else
    {
        return *(m_SharedPtr->begin());
    }
}

size_t SharedStringQueue::size()
{
    return m_SharedPtr->size();
}

bool SharedStringQueue::isEmpty()
{
    return m_SharedPtr->empty();
}

