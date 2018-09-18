#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    string WholeStr = "";
    string str;
    int ACnt = 0, ECnt = 0, ICnt = 0, OCnt = 0, UCnt = 0;
    int SpaceCnt = 0, TabCnt = 0, EndlCnt = 0, OtherCnt = 0;

    /*
    //This doesn't work.
    char c;
    while(cin >> c)
    {
        WholeStr = WholeStr + c;
    }
    */

    while(getline(cin, str))
    {
        WholeStr = WholeStr + str + '\n';
    }

    for(auto c : WholeStr)
    {
        switch(c)
        {
            case 'A':
            case 'a':
                ACnt++;
                break;
            case 'E':
            case 'e':
                ECnt++;
                break;
            case 'I':
            case 'i':
                ICnt++;
                break;
           case 'O':
            case 'o':
                OCnt++;
                break;
            case 'U':
            case 'u':
                UCnt++;
                break;
            case ' ':
                SpaceCnt++;
                break;
            case '\t':
                TabCnt++;
                break;
            case '\n':
                EndlCnt++;
                break;
            default:
                OtherCnt++;
                break;
        }
    }

    cout << "Vowel a appears " << ACnt << " time";
    cout << ((ACnt > 1) ? "s;" : ";") << endl;
    cout << "Vowel e appears " << ECnt << " time";
    cout << ((ECnt > 1) ? "s;" : ";") << endl;
    cout << "Vowel i appears " << ICnt << " time";
    cout << ((ICnt > 1) ? "s;" : ";") << endl;
    cout << "Vowel o appears " << OCnt << " time";
    cout << ((OCnt > 1) ? "s;" : ";") << endl;
    cout << "Vowel u appears " << UCnt << " time";
    cout << ((UCnt > 1) ? "s;" : ";") << endl;
    cout << "Space appears " << SpaceCnt << " time";
    cout << ((SpaceCnt > 1) ? "s;" : ";") << endl;
    cout << "Tab appears " << TabCnt << " time";
    cout << ((TabCnt > 1) ? "s;" : ";") << endl;
    cout << "End of line appears " << EndlCnt << " time";
    cout << ((EndlCnt > 1) ? "s;" : ";") << endl;

    return 0;
}
