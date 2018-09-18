#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    string WholeStr = "";
    string str;
    int ffCnt = 0, flCnt = 0, frCnt = 0;

    while(getline(cin, str))
    {
        WholeStr = WholeStr + str + '\n';
    }

    for(auto it = WholeStr.begin(); it != WholeStr.end(); it++)
    {
        if(*it == 'f')
        {
            if(it + 1 != WholeStr.end())
            {
                switch(*(it+1))
                {
                    case 'f':
                        ffCnt++;
                        break;
                    case 'l':
                        flCnt++;
                        break;
                    case 'r':
                        frCnt++;
                        break;
                    default:
                        break;
                }
            }
            else
            {
            }
        }
        else
        {
        }
    }

    cout << "\'ff\' appears " << ffCnt << " time";
    cout << ((ffCnt > 1) ? "s;" : ";") << endl;
    cout << "\'fl\' appears " << flCnt << " time";
    cout << ((flCnt > 1) ? "s;" : ";") << endl;
    cout << "\'fr\' appears " << frCnt << " time";
    cout << ((frCnt > 1) ? "s;" : ";") << endl;

    return 0;
}
