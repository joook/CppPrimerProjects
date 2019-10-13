#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main()
{
    //memory will not be freed when exception throws
    vector<string> *TempPtr1 = new vector<string>();
    //memory will be freed when exception throws
    unique_ptr<vector<string>> TempPtr2(new vector<string>());

    int Order;
    cout << "Push 1st string or 2nd string? 1 or 2." << endl;
    cin >> Order;
    if(Order == 1)
    {
        TempPtr1->push_back("First String");
    }
    else if(Order == 2)
    {
        TempPtr2->push_back("Second String");
    }
    else
    {
        throw runtime_error("Input invalid, please check.");
    }

    cout << "Now the string in vector is: " << endl;
    for(const auto Str : *TempPtr1)
    {
        cout << Str << endl;
    }
    for(const auto Str : *TempPtr2)
    {
        cout << Str << endl;
    }

    delete TempPtr1;

    return 0;
}
