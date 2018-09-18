#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int i = 1;

    cout << "i = " << i << endl;
    cout << "i++ = " << i++ << ", i = " << i << endl;
    i = 1;
    cout << "i = " << i << endl;
    cout << "++i = " << ++i << ", i = " << i << endl;
    //i = 1;
    //cout << "i = " << i << endl;
    //cout << "++(i++) = " << ++(i++) << ", i = " << i << endl;

    return 0;
}
