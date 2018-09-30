#include <iostream>

using namespace std;

void f()
{
    cout << "func1: f()" << endl;
}

void f(int)
{
    cout << "func2: f(int)" << endl;
}

void f(int, int)
{
    cout << "func3: f(int, int)" << endl;
}

void f(double, double = 3.14)
{
    cout << "func4: f(double, double)" << endl;
}

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
    }
    else if(argc == 2)
    {
        f(*argv[1]);
    }
    else if(argc == 3)
    {
        f(*argv[1], *argv[2]);
    }
    else
    {
    }
    cout << "**********************" << endl;
//    f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);

    return 0; 
}
