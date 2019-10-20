#include <iostream>

using namespace std;

class UniqueItem
{
friend void printId(const UniqueItem &Item);

public:
    UniqueItem()
    : m_SelfId(++m_IdCount)
    {
    }

    UniqueItem(UniqueItem &OriginalItem)
    : m_SelfId(++m_IdCount)
    {
    }

    ~UniqueItem()
    {
    }

private:
    static int m_IdCount;
    int m_SelfId;
};

//define and init static member
int UniqueItem::m_IdCount = 0;

void printId(const UniqueItem &Item)
{
    cout << Item.m_SelfId << endl;
}

int main()
{
    UniqueItem Item1;
    UniqueItem Item2 = Item1;
    printId(Item1);
    printId(Item2);
    return 0;
}
