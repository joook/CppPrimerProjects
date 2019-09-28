#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

using namespace std;

class SharedStringQueue
{
public:
    SharedStringQueue();
    SharedStringQueue(initializer_list<string> InitList);
    ~SharedStringQueue() {}

    void pushStr(const string &NewStr);
    void popStr();
    const string &frontStr();
    size_t size();
    bool isEmpty();
private:
    shared_ptr<vector<string>> m_pQueue;
};

SharedStringQueue::SharedStringQueue()
: m_pQueue(make_shared<vector<string>>())
{
}

SharedStringQueue::SharedStringQueue(initializer_list<string> InitList)
: m_pQueue(make_shared<vector<string>>(InitList))
{
}

void SharedStringQueue::pushStr(const string &NewStr)
{
    m_pQueue->push_back(NewStr);
}

void SharedStringQueue::popStr()
{
    auto ItrBeg = m_pQueue->begin();
    m_pQueue->erase(ItrBeg);
}

const string &SharedStringQueue::frontStr()
{
    return *(m_pQueue->begin());
}

size_t SharedStringQueue::size()
{
    return m_pQueue->size();
}

bool SharedStringQueue::isEmpty()
{
    return m_pQueue->empty();
}

int main()
{
    SharedStringQueue OriQueue({"cat", "dog", "pig"});
    SharedStringQueue TempQueue;
    TempQueue = OriQueue;
    TempQueue.pushStr("mouse");
    TempQueue.popStr();
    cout << "Front str: " << TempQueue.frontStr() << endl;
    OriQueue.popStr();
    cout << "Front str: " << TempQueue.frontStr() << endl;
    TempQueue.popStr();
    cout << "Front str: " << OriQueue.frontStr() << endl;
    return 0;
}
