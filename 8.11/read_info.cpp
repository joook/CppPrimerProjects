#include <iostream>
#include <sstream>
#include <vector>
#include "person_info.h"

using namespace std;

int main()
{
    vector<PersonInfo> Contacts;
    string TempLine;
    string TempPhone;
    istringstream TempISStream;

    while(getline(cin, TempLine))
    {
        PersonInfo TempPsn;

        TempISStream.clear();
        TempISStream.str(TempLine);
        TempISStream >> TempPsn.Name;
        while(TempISStream >> TempPhone)
        {
            TempPsn.PhoneNums.push_back(TempPhone);
        }

        Contacts.push_back(TempPsn);
    }

    cout << "All contacts: " << endl;
    for(auto it = Contacts.begin(); it != Contacts.end(); it++)
    {
        cout << (*it).Name << endl;
    }

    return 0;
}
