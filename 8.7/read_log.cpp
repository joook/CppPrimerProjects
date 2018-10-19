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

void writeFile(ofstream &FileOstream, string &FileName, vector<string> &TempVec)
{
    string TempStr;
    FileOstream.open(FileName, ofstream::app);
    for(auto it = TempVec.begin(); it != TempVec.end(); it++)
    {
        FileOstream << *it << endl;
    }
    FileOstream.close();
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
    else if(argc == 3)
    {
        string IfileName = argv[1];
        string OfileName = argv[2];
        ifstream FileIstream;
        ofstream FileOstream;
        vector<string> TempVec;
        readFile(FileIstream, IfileName, TempVec);
        writeFile(FileOstream, OfileName, TempVec);
    }
    else
    {
        cout << "You need to input file name." << endl;
        cout << "If the file name is \"log.txt\", "  << endl;
        cout << "you should type in: readlog log.txt." << endl;
        cout << "If you want to read one file into another, " << endl;
        cout << "and the input file name is \"log.txt\", "  << endl;
        cout << "and the output file name is \"log_1.txt\", "  << endl;
        cout << "you should type in: readlog log.txt log_1.txt." << endl;
    }

    return 0;
}
