#include <iostream>

using std::string;

int main()
{
    int i = 4;
    double d = 5.5;
    const string *ps;
    char *pc;
    void *pv;

    i = static_cast<int>(d);
    std::cout << "d = " << d << std::endl;

    pv = const_cast<void*>(static_cast<const void*>(ps));
    pv = static_cast<void*>(const_cast<string*>(ps));

    i = static_cast<int>(*pc);

    pv = static_cast<void*>(&d);

    pc = static_cast<char*>(pv);

    return 0;
}
