#include <iostream>
#include <functional>

class Practice
{
public:
    Practice(){}
    virtual ~Practice(){}

    int addNum(int a, int b)
    {
        return (a+b);
    }

    int add()
    {
        int a = 10;
        int b = 20;
        auto addWithPlaceholder = std::bind(&Practice::addNum, this
        , std::placeholders::_1, std::placeholders::_2);
        return addWithPlaceholder(a, b);
    }

};

int main()
{
    Practice TempInstance;
    std::cout << TempInstance.add() << std::endl;
    
    auto addOutsideClass = std::mem_fn(&Practice::addNum);
    std::cout << addOutsideClass(&TempInstance, 20, 30) << std::endl;

    return 0;
}
