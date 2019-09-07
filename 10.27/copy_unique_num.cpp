#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

#define RET_OK (0u)
#define RET_FAIL (1u)

int readInput(const string &FileName, vector<int> &NumVec)
{
    int Ret = RET_FAIL;

    ifstream FileStream(FileName);
    if(FileStream.is_open())
    {
        NumVec.clear();
        int TempNum;
        while(FileStream >> TempNum)
        {
            NumVec.push_back(TempNum);
        }
        FileStream.close();
        cout << "Read file done." << endl;
        Ret = RET_OK;
    }
    else
    {
        cout << "Cannot open file." << endl;
        Ret = RET_FAIL;
    }

    return Ret;
}

int writeOutput(const string &FileName, vector<int> &NumVec)
{
    int Ret = RET_FAIL;

    ofstream FileStream(FileName, ios::trunc);
    if(FileStream.is_open())
    {
        for(auto Itr = NumVec.begin(); Itr != NumVec.cend(); Itr++)
        {
            FileStream << *Itr << " ";
        }
        FileStream.close();
        cout << "Write file done." << endl;
        Ret = RET_OK;
    }
    else
    {
        cout << "Cannot open file." << endl;
        Ret = RET_FAIL;
    }

    return Ret;
}

void copyUnique(vector<int> &SourceVec, vector<int> &TargetVec)
{
    TargetVec.clear();
    sort(SourceVec.begin(), SourceVec.end());
	unique_copy(SourceVec.cbegin(), SourceVec.cend(), back_inserter(TargetVec));
}

int main()
{
    string InputFile = "./input.txt";
    string OutputFile = "./output.txt";
    vector<int> SourceVec;
    vector<int> ResultVec;

    if(readInput(InputFile, SourceVec) == RET_OK)
    {
        cout << "Read input done." << endl;
    }
    else
    {
        cout << "Read input error." << endl;
        return RET_FAIL;
    }

    copyUnique(SourceVec, ResultVec);

    if(writeOutput(OutputFile, ResultVec) == RET_OK)
    {
        cout << "Running function success, the result is recorded in: " << endl;
        cout << OutputFile << "." << endl;
    }
    else
    {
        cout << "Write output error." << endl;
        return RET_FAIL;
    }

    return RET_OK;
}














