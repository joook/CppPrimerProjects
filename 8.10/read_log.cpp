#include <iostream>
#include <fstream>
#include <sstream>
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

void readVector(vector<string> &TempVec)
{
    for(auto it = TempVec.begin(); it != TempVec.end(); it++)
    {
        string TempWord;
        istringstream TempIStrStream(*it);
        while(TempIStrStream >> TempWord)
        {
            cout << "S: " << TempWord << endl;
        }
    }

}

int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        string FileName = argv[1];
        ifstream FileIstream;
        vector<string> TempVec;
        readFile(FileIstream, FileName, TempVec);
        readVector(TempVec);
    }
    else
    {
        cout << "You need to input file name." << endl;
        cout << "If the file name is \"log.txt\", "  << endl;
        cout << "you should type in: readlog log.txt." << endl;
    }

    return 0;
}
