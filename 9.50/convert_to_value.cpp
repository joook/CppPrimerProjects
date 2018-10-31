#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

void getNum(vector<string> &InputNum)
{
    string TempString;
    cout << "Input some numbers, divided by space: " << endl;
    while(cin >> TempString)
    {
        InputNum.push_back(TempString);
    }
}

int main()
{
    vector<string> InputNum;
    int Sum = 0;

    getNum(InputNum);

    try
    {
        for(auto Itr = InputNum.begin(); Itr != InputNum.end(); Itr++)
        {
            Sum += stoi(*Itr);
        }
        cout << "The sum is: " << Sum << endl;
    }
    catch(invalid_argument Err)
    {
        cerr << Err.what() << endl;
        cout << "The input is not number." << endl;
    }
    catch(out_of_range Err)
    {
        cerr << Err.what() << endl;
        cout << "The input number is too large." << endl;
    }

    return 0;
}
