#include <iostream>
#include <initializer_list>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::initializer_list;

float add(initializer_list<float> Nums)
{
    float Sum;
    for(auto it = Nums.begin(); it != Nums.end(); it++)
    {
        Sum += *it;
    }
    return Sum;
}

int main()
{
    float Num;
    vector<float> NumVec;
    char c;
    float Sum;

    cout << "Input numbers you wanna add: " << endl;
    //input of float will not end at \n, so type in ctrl+d at end
    while(cin >> Num)
    {
        NumVec.push_back(Num);
    }
    while((c = cin.get()) && (c != '\n') && (c != EOF))
    {
    }

    switch(NumVec.size())
    {
        case 0:
            cout << "Too few numbers, quit." << endl;
            break;
        case 1:
            Sum = add({NumVec[0]});
            cout << "The sum is: " << Sum << endl;
            break;
        case 2:
            Sum = add({NumVec[0], NumVec[1]});
            cout << "The sum is: " << Sum << endl;
            break;
        case 3:
            Sum = add({NumVec[0], NumVec[1], NumVec[2]});
            cout << "The sum is: " << Sum << endl;
            break;
        case 4:
            Sum = add({NumVec[0], NumVec[1], NumVec[2], NumVec[3]});
            cout << "The sum is: " << Sum << endl;
            break;
        default:
            cout << "Too many numbers, quit." << endl;
            break;
    }

    return 0;
}
