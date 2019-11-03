#include <string>
#include <iostream>

class Employee
{
public:
    Employee() = default;
    Employee(const std::string Name);
    ~Employee();
    void printInfo();
private:
    std::string m_Name;
    int m_PrivateID;
    static int m_IDCount;
};

int Employee::m_IDCount = 0;

Employee::Employee(const std::string Name)
: m_Name(Name)
, m_PrivateID(++m_IDCount)
{
}

Employee::~Employee()
{
}

void Employee::printInfo()
{
    std::cout << "Employee name: " << m_Name << std::endl;
    std::cout << "Employee id: " << m_PrivateID << std::endl;
}




