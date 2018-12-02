#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void print(vector<string> &TempVec)
{
    auto Itr = TempVec.begin();
    for(;Itr != TempVec.end(); Itr++)
    {
        cout << *Itr << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    string FileName;
    ifstream FileStream;
    string TempWord;
    vector<string> TempVec;

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

    sort(TempVec.begin(), TempVec.end());
    cout << "After sort, the vector is: " << endl;
    print(TempVec);

    auto ItrEnd = unique(TempVec.begin(), TempVec.end());
    cout << "After unique, the vector is: " << endl;
    print(TempVec);

    TempVec.erase(ItrEnd, TempVec.end());
    cout << "After erase, the vector is: " << endl;
    print(TempVec);

    return 0;
}
