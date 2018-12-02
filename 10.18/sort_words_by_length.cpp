#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void print(const vector<string> &TempVec)
{
    vector<string>::const_iterator Itr = TempVec.begin();
    for(;Itr != TempVec.end(); Itr++)
    {
        cout << *Itr << " ";
    }
    cout << endl;
}

void print(vector<string>::iterator ItrBeg, vector<string>::iterator ItrEnd)
{
    for(;ItrBeg != ItrEnd; ItrBeg++)
    {
        cout << *ItrBeg << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    string FileName;
    ifstream FileStream;
    string TempWord;
    vector<string> TempVec;
    string::size_type StandardSize = 5;

    if(argc == 2)
    {
        FileName = argv[1];
    }
    else
    {
        throw invalid_argument("Format is: sort [FileName], try again.");
    }

    FileStream.open(FileName);
    while(FileStream >> TempWord)
    {
        TempVec.push_back(TempWord);
    }
    FileStream.close();
    cout << "After input, the vector is: " << endl;
    print(TempVec);

    sort(TempVec.begin(), TempVec.end(), 
        [](const string &a, const string &b){return a.size() < b.size();});
    cout << "After sort by length, the vector is: " << endl;
    print(TempVec);

    vector<string>::iterator Itr = 
        find_if(TempVec.begin(), TempVec.end(),
        [StandardSize](const string &a){return a.size() > StandardSize;});
    cout << "The words longer than " << StandardSize;
    cout << " characters are: " << endl;
    print(Itr, TempVec.end());

    return 0;
}
