#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    int i = 0, j = 0;

    while(i != 10)
    {
        j += 2;
        i++;
    }
    cout << j << endl;

    for(; cin >> i;)
    {
        j += i;
    }
    cout << j << endl;

    return 0;
}
