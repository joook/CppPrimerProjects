#include <iostream>

class ClassA
{
public:
    ClassA();
    virtual ~ClassA() = default;
    inline int getState() { return m_State; }
    inline void setState(int NewState) { m_State = NewState; }

private:
    int m_State;
};

class ClassB: public ClassA
{
public:
    ClassB() = default;
    ~ClassB() = default;
};
