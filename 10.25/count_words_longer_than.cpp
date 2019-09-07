#include <iostream>
#include <string>
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

bool longerThan(const string &WordA, const string &WordB)
{
    return WordA.size() > WordB.size();
}

bool longerThanStd(const string &Word, const string::size_type StdLength)
{
    return Word.size() > StdLength;
}

void biggies(vector<string> &VecStr, const string::size_type StdLength)
{
    stable_sort(VecStr.begin(), VecStr.end(), 
        bind(longerThan, _2, _1)); //after sort, shorter word is in the front

    auto Itr = find_if(VecStr.begin(), VecStr.end(), 
        bind(longerThanStd, _1, StdLength));

    vector<string>::size_type WordCnt = VecStr.cend()-Itr;
    cout << "The number of words longer than " << StdLength;
    cout << " is: " << WordCnt << "." << endl;
}

int main(int argc, char *argv[])
{
    string FileName;
    vector<string> VecStr;
    string::size_type StdLength;

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

    biggies(VecStr, StdLength);

    return 0;
}
