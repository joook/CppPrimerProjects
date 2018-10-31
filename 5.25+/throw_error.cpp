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

bool askTryAgain()
{
    bool ReturnVal;
    char TryAgain;
    cout << "Try again? (y or n)" << endl;
    cin >> TryAgain;
    if(!cin || TryAgain == 'n')
    {
        ReturnVal = false;
    }
    else
    {
        ReturnVal = true;
    }
    return ReturnVal;
}

int main()
{
    int Dividend, Divider, Quotient;

    while(true)
    {
        cout << "Input dividend: " << endl;
        cin >> Dividend;
        cout << "Input divider: " << endl;
        cin >> Divider;
        try
        {
            Quotient = divideNum(Dividend, Divider);
            cout << "Quotient is: " << endl << Quotient << endl;
        }
        catch(runtime_error Err)
        {
            cerr << Err.what() << endl;
        }
        if(askTryAgain())
        {
        }
        else
        {
            break;
        }
    }

    return 0;
}
