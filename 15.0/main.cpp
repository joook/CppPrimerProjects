#include "ClassA.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    ClassB TempClassB;
    TempClassB.setState(1);
    cout << "State: " << TempClassB.getState() << endl;
    TempClassB.setState(2);
    cout << "State: " << TempClassB.getState() << endl;

    return 0;
}
