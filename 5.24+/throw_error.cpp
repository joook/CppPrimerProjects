#include <iostream>
#include <stdexcept>

using namespace std;

int divideNum(int Dividend, int Divider)
{
    if(Divider == 0)
    {
        /*
        Throw error, without try/catch,
        will terminate the function;
        Throw error, with try/catch,
        can keep the function running if you want,
        and can also terminate the function if needed.
        */
        throw runtime_error("The divider cannot be 0.");
    }
    else
    {
    }
    return Dividend/Divider;
}

int main()
{
    int Dividend, Divider, Quotient;
    char c;

    //cin.tie(&cout);

    cout << "Input dividend: " << endl;
    cin >> Dividend;

    while((c = cin.get()) && (c != '\n') && (c != EOF))
    {
    }

    cout << "Input divider: " << endl;
    cin >> Divider;

    Quotient = divideNum(Dividend, Divider);
    cout << "Quotient is: " << endl << Quotient << endl;

    return 0;
}
