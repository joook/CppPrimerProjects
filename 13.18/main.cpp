#include "employee.h"

using namespace std;

int main()
{
    Employee Member1("Jimmy");
    Member1.printInfo();
    Employee Member2;
    Member2.printInfo();
    Employee Member3("Nancy");
    Member3.printInfo();
    Employee Member4("Frank");
    Member4.printInfo();

    return 0;
}
