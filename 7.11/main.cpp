#include "person_info.h"

using namespace std;

int main()
{
    PersonInfo TempPrsn001;
    PersonInfo TempPrsn002("Prsn002");
    PersonInfo TempPrsn003("Prsn003", "PrsnAdd003");
    cout << "TempPrsn004 info needs input." << endl;
    PersonInfo TempPrsn004(cin);

    cout << "--------------------------------" << endl;
    cout << "[Person Info List]" << endl;
    printPersonInfo(cout, TempPrsn001);
    printPersonInfo(cout, TempPrsn002);
    printPersonInfo(cout, TempPrsn003);
    printPersonInfo(cout, TempPrsn004);

    /*
    cout << "Input TempPrsn001 info." << endl;
    if(readPersonInfo(cin, TempPrsn001))
    {
        cout << "Person info got." << endl;
        printPersonInfo(cout, TempPrsn001);
    }
    else
    {
        cout << "No person info." << endl;
    }
    */
    return 0;
}
