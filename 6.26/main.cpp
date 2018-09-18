#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(int argc, char *argv[])
{
    string opt;

    for(int i = 1; i !=argc; i++)
    {
        opt = opt + argv[i] + " ";
    }

    cout << opt << endl;

    return 0;
}
