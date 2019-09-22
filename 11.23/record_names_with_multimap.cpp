#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

void insertName(multimap<string, vector<string>> &FamilyMap, const string &FamilyName, const vector<string> &GivenNameVec)
{
    FamilyMap.insert(make_pair(FamilyName, GivenNameVec));
    //FamilyMap.insert({FamilyName, GivenNameVec});
}

void printFamilyTree(const multimap<string, vector<string>> &FamilyMap)
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
    multimap<string, vector<string>> FamilyMap;
    string FamilyName;
    vector<string> GivenNameVec;
    char c;

    while(1)
    {
        cout << "Type in family name: " << endl;
        cin >> FamilyName;
        while((c = cin.get()) && (c != '\n') && (c != EOF))
        {
        }

        cout << "Type in given names, divided by space: " << endl;
        string GivenNames;
        string GivenName;
        getline(cin, GivenNames);
        istringstream StringStream(GivenNames);
        GivenNameVec.clear();
        while(StringStream >> GivenName)
        {
            GivenNameVec.push_back(GivenName);
        }

        insertName(FamilyMap, FamilyName, GivenNameVec);

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
