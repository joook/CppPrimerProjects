#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string StrInput;
    int VowelCnt = 0;

    cin >> StrInput;

    for(char c : StrInput)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            ++VowelCnt;
        }
        else
        {
        }
    }

    cout << "The number of vowels in the string is :" << VowelCnt << endl;

    return 0;
}
