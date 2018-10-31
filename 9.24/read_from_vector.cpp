#include <iostream>
#include <vector>

using namespace std;

void makeVector(vector<string> &TempVector)
{
    string TempString;
    cout << "Input some strings: " << endl;
    while(cin >> TempString)
    {
        TempVector.push_back(TempString);
    }
}

bool checkVector(const vector<string> &TempVector)
{
    return ((TempVector.size() == 0) ? false : true);
}

int main()
{
    vector<string> TempVector;

    makeVector(TempVector);
    if(checkVector(TempVector) == true)
    {
        cout << "The 1st item in the vector is: " << endl;
        cout << "using \"at()\": " << TempVector.at(0) << endl;
        cout << "using \"[]\": " << TempVector[0] << endl;
        cout << "using \"begin()\": " << *TempVector.begin() << endl;
        cout << "using \"front()\": " << TempVector.front() << endl;
    }
    else
    {
        cout << "No input, quit." << endl;
    }

    return 0;
}
