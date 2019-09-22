#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

void insertFamilyName(map<string, vector<string>> &FamilyMap, const string &FamilyName)
{
    FamilyMap[FamilyName];
}

void insertGivenName(map<string, vector<string>> &FamilyMap, const string &FamilyName, const string &GivenName)
{
    FamilyMap[FamilyName].push_back(GivenName);
}

void printFamilyTree(const map<string, vector<string>> &FamilyMap)
{
    for(auto Pair : FamilyMap)
    {
        string FamilyName = Pair.first;
        vector<string> GivenNameVec = Pair.second;
        cout << FamilyName << endl;
        size_t FamilyNameLength = FamilyName.size();
        string Space(FamilyNameLength, ' ');
        for(string GivenName : GivenNameVec)
        {
            cout << Space << "-" << GivenName << " " << FamilyName << endl;
        }
    }
}

int main()
{
    map<string, vector<string>> FamilyMap;
    string FamilyName;
    vector<string> GivenNameVec;
    char c;

    while(1)
    {
        cout << "Type in family name: " << endl;
        cin >> FamilyName;
        insertFamilyName(FamilyMap, FamilyName);
        while((c = cin.get()) && (c != '\n') && (c != EOF))
        {
        }

        cout << "Type in given names, divided by space: " << endl;
        string GivenNames;
        string GivenName;
        getline(cin, GivenNames);
        istringstream StringStream(GivenNames);
        while(StringStream >> GivenName)
        {
            insertGivenName(FamilyMap, FamilyName, GivenName);
        }
        while((c = cin.get()) && (c != '\n') && (c != EOF))
        {
        }

        cout << "Go on and input another family? y or n." << endl;
        char ContinueFlag;
        cin >> ContinueFlag;
        if(!cin || ContinueFlag != 'y')
        {
            break; //break while
        }
        else
        {
            //go on
        }
    }

    cout << "Now the family map is:" << endl;
    printFamilyTree(FamilyMap);
    return 0;
}
