#include "ClassA.h"

ClassA::ClassA()
{
    m_State = 0;
}

ClassA::~ClassA()
{
}

ClassB::ClassB(): ClassA()
{
}

ClassB::~ClassB()
{
}
