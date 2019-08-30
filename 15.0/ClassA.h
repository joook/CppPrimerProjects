#include <iostream>

class ClassA
{
public:
    ClassA();
    virtual ~ClassA();
    inline int getState() { return m_State; }
    inline void setState(int NewState) { m_State = NewState; }

private:
    int m_State;
};

class ClassB: public ClassA
{
public:
    ClassB();
    ~ClassB();
};
