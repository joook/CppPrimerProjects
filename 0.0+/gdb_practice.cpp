#include <iostream>

using namespace std;
 
void selfPlus(int &k)
{
    int i = 2;
    for(k = 0; k < 5; k++)
    {
        i *= 2;
    }
    k += i;
}
 
int main()
{
    int p = 0;
    cout << "Input a number: ";
    cin >> p;
    selfPlus(p);
    cout << "After self plus, it is: " << p << endl;
    return 0;
}

