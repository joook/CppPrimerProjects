#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
    if(argc > 2)
    {
        cout << "Too many arguments, quit." << endl;
        return -1;
    }
    else if(argc < 2)
    {
        cout << "Too few arguments, quit." << endl;
        return -1;
    }
    else
    {
    }

    string str1 = argv[1];

    //if(argv[1] == "-h")   //This doesn't work.
    if(str1 == "-h")
    {
        cout << "-----[Help Doc]-----" << endl;
    }
    else
    {
        cout << "Invalid arguments, quit." << endl;
    }

    return 0;
}
