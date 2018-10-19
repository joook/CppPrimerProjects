#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readFile(ifstream &FileIstream, string &FileName, vector<string> &TempVec)
{
    string TempStr;
    FileIstream.open(FileName);
    while(getline(FileIstream, TempStr))
    {
        TempVec.push_back(TempStr);
    }
    FileIstream.close();
}

int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        string FileName = argv[1];
        ifstream FileIstream;
        vector<string> TempVec;
        readFile(FileIstream, FileName, TempVec);
        for(auto it = TempVec.begin(); it != TempVec.end(); it++)
        {
            cout << *it << endl;
        }
    }
    else
    {
        cout << "You need to input file name." << endl;
        cout << "e.g.: If the file name is \"log.txt\", "  << endl;
        cout << "you should type in: readlog log.txt." << endl;
    }

    return 0;
}
