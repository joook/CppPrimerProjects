#include <iostream>
#include <initializer_list>
#include <vector>
#include "add.h"

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::initializer_list;

int main()
{
    unsigned int NumCnt;
    float num;
    vector<float> NumVec;

    cout << "Input numbers you wanna add: " << endl;
    while(cin >> num)
    {
        NumVec.push_back(num);
    }

    float sum;
    switch(NumVec.size())
    {
        case 0:
            cout << "Too few numbers, quit." << endl;
            break;
        case 1:
            sum = add({NumVec[0]});
            cout << "The sum is: " << sum << endl;
            break;
        case 2:
            sum = add({NumVec[0], NumVec[1]});
            cout << "The sum is: " << sum << endl;
            break;
        case 3:
            sum = add({NumVec[0], NumVec[1], NumVec[2]});
            cout << "The sum is: " << sum << endl;
            break;
        case 4:
            sum = add({NumVec[0], NumVec[1], NumVec[2], NumVec[3]});
            cout << "The sum is: " << sum << endl;
            break;
        default:
            cout << "Too many numbers, quit." << endl;
            break;
    }

    return 0;
}
