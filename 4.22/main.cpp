#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> VecInt;
    int k;

    while(cin >> k)
    {
        VecInt.push_back(k);
    }
    if(VecInt.size() == 0)
    {
        cout << "No valid input, quit." << endl;
        return -1;
    }
    else
    {
    }

    int i = 0;
    /*
    for(auto it = VecInt.begin(); it != VecInt.end(); ++it)
    { 
        cout << "The " << i+1;
        cout << (((i+1)%10 == 1) ? "st" : 
            ((i+1)%10 == 2) ? "nd" : 
            ((i+1)%10 == 3) ? "rd" : "th");
        cout << " grade is " << *it;
        cout << " , it belongs to [";
        cout << ((*it < 60) ? "Fail" : 
            ((*it < 70) ? "Low Pass" : 
            ((*it > 90) ? "High Pass" : "Mid Pass")));
        cout << "] zone." << endl;
        i++;
    }
    */
    for(auto it = VecInt.begin(); it != VecInt.end(); ++it)
    {
        string str;
        if(*it < 60)
        {
            str = "Fail";
        }
        else if(*it < 70)
        {
            str = "Low Pass";
        }
        else if(*it > 90)
        {
            str = "High Pass";
        }
        else
        {
            str = "Mid Pass";
        }
        cout << "The " << i+1;
        cout << (((i+1)%10 == 1) ? "st" : 
            ((i+1)%10 == 2) ? "nd" : 
            ((i+1)%10 == 3) ? "rd" : "th");
        cout << " grade is " << *it;
        cout << " , it belongs to [" << str;
        cout << "] zone." << endl;
        i++;
    }

    return 0;
}
