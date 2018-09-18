#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> VecIntIn;
    vector<int> VecIntOut;
    int Input;

    while(cin >> Input)
    {
        VecIntIn.push_back(Input);
    }
    auto ItBegIn = VecIntIn.begin();
    auto ItEndIn = VecIntIn.end();
    auto ItMidIn = VecIntIn.begin() + VecIntIn.size()/2;

    /*
    for(; ItBegIn+1 != ItEndIn; ++ItBegIn)
    {
        VecIntOut.push_back(*ItBegIn + *(ItBegIn+1));
    }
    */
    for(; ItBegIn < ItEndIn; ++ItBegIn, --ItEndIn)
    {
        VecIntOut.push_back(*ItBegIn + *(ItEndIn-1));
    }
    auto ItBegOut = VecIntOut.begin();
    auto ItEndOut = VecIntOut.end();

    //cout << "The sums of adjacent numbers are: " << endl;
    cout << "The sums of symmetrical numbers are: " << endl;
    for(; ItBegOut !=ItEndOut; ++ItBegOut)
    {
        cout << *ItBegOut << endl;
    }

    return 0;
}
