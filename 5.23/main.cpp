#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::string;

bool input(int &a, int &b)
{
    cout << "Input 1st number: ";
    cin >> a;
    cout << "Input 2nd number: ";
    cin >> b;

    return true;
}

int fun(int a, int b)
{
    if(b == 0)
    {
        throw std::runtime_error("The divide number is invalid, quit.");
    }
    else
    {
    }
    return a/b;
}

int main()
{
    int a;
    int b;

    while(input(a, b))
    {
        try
        {
            int f = fun(a, b);
            cout << "1st number divided by 2nd number is: " << f << endl;
        }
        catch(std::runtime_error err)
        {
            cerr << err.what() << endl;
        }
        cout << "Calculate again? y or n." << endl;
        char c;
        cin >> c;
        if(!cin || c == 'n')
            break;
    }

    return 0;
}
