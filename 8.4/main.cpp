#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readFile(ifstream &ReadOnlyFile, vector<string> &VecStr)
{
    string TempStr;
    ReadOnlyFile.open("main.cpp");
    while(getline(ReadOnlyFile, TempStr))
    {
        VecStr.push_back(TempStr);
    }
    ReadOnlyFile.close();
}

int main()
{
    ifstream ReadOnlyFile;
    vector<string> VecStr;
    readFile(ReadOnlyFile, VecStr);
    for(auto it = VecStr.begin(); it != VecStr.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}
