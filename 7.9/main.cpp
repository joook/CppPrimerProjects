#include "person_info.h"

using namespace std;

int main()
{
    PersonInfo XiaoQian;
    if(readPersonInfo(cin, XiaoQian))
    {
        cout << "Get person info." << endl;
        printPersonInfo(cout, XiaoQian);
    }
    else
    {
        cout << "No person info." << endl;
    }
    return 0;
}
