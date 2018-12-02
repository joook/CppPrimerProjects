#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

void readWords(const string &FileName, vector<string> &VecStr)
{
    ifstream InFileStream;
    string TempWord;

    InFileStream.open(FileName);
    while(InFileStream >> TempWord)
    {
        VecStr.push_back(TempWord);
    }
    InFileStream.close();

}

bool longerThanStd(const string &Word, const vector<string>::size_type StdLength)
{
    return Word.size() > StdLength;
}

int main(int argc, char *argv[])
{
    string FileName;
    vector<string> VecStr;
    string::size_type StdLength;
    vector<string>::size_type WordCnt;

    if(argc == 2)
    {
        FileName = argv[1];
        readWords(FileName, VecStr);
        StdLength = 5;
    }
    else if(argc == 3)
    {
        FileName = argv[1];
        readWords(FileName, VecStr);
        StdLength = stoi(argv[2]);
    }
    else
    {
        throw runtime_error("Invalid input format, quit.");
    }

    WordCnt = count_if(VecStr.cbegin(), VecStr.cend(), 
        bind(longerThanStd, _1, StdLength));
    cout << "The number of words longer than " << StdLength;
    cout << " is: " << WordCnt << "." << endl;

    return 0;
}
