#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    string WholeStr = "";
    string str;
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, otherCnt = 0;

    while(cin >> str)
    {
        WholeStr = WholeStr + str;
    }

    for(auto c : WholeStr)
    {
        switch(c)
        {
            case 'A':
            case 'a':
                aCnt++;
                break;
            case 'E':
            case 'e':
                eCnt++;
                break;
            case 'I':
            case 'i':
                iCnt++;
                break;
            case 'O':
            case 'o':
                oCnt++;
                break;
            case 'U':
            case 'u':
                uCnt++;
                break;
            default:
                otherCnt++;
                break;
        }
    }

    cout << "Vowel a appears " << aCnt << " time";
    cout << ((aCnt > 1) ? "s;" : ";") << endl;
    cout << "Vowel e appears " << eCnt << " time";
    cout << ((eCnt > 1) ? "s;" : ";") << endl;
    cout << "Vowel i appears " << iCnt << " time";
    cout << ((iCnt > 1) ? "s;" : ";") << endl;
    cout << "Vowel o appears " << oCnt << " time";
    cout << ((oCnt > 1) ? "s;" : ";") << endl;
    cout << "Vowel u appears " << uCnt << " time";
    cout << ((uCnt > 1) ? "s;" : ";") << endl;

    return 0;
}
