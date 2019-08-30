#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <functional>

using namespace std;

#define RET_OK (0u)
#define RET_FAIL (1u)

int readInput(const string &FileName, vector<int> &LenVec)
{
    int Ret = RET_FAIL;

    ifstream TempStream(FileName);
    if(TempStream.is_open())
    {
        LenVec.clear();
        int TempNum;
        while(TempStream >> TempNum)
        {
            LenVec.push_back(TempNum);
        }
        TempStream.close();

        Ret = RET_OK;
    }
    else
    {
        cout << "Cannot open file." << endl;
        Ret = RET_FAIL;
    }

    return Ret;
}

int writeOutput(const string &FileName, vector<int> &LenVec)
{
    int Ret = RET_FAIL;

    ofstream TempStream(FileName, ios::trunc);
    if(TempStream.is_open())
    {
        for(auto Itr = LenVec.begin(); Itr != LenVec.cend(); Itr++)
        {
            TempStream << *Itr << " ";
        }

        TempStream.close();
        Ret = RET_OK;
    }
    else
    {
        cout << "Cannot open file." << endl;
        Ret = RET_FAIL;
    }

    return Ret;
}

bool compare(int TargetLength, int Length)
{
    return (Length > TargetLength);
}

int compareLength(int TargetLength, const vector<int> &LengthVec, vector<int> &ResultVec)
{
    int Ret = RET_OK;

    auto Pos = LengthVec.begin();
    auto EndPos = LengthVec.cend();
    while(1)
    {
        Pos = find_if(Pos, EndPos, bind(compare, TargetLength, placeholders::_1));
        if(Pos != EndPos)
        {
            cout << "Got a length: " << *Pos << endl;
            ResultVec.push_back(*Pos);
            Pos++;
        }
        else
        {
            break; //break while
        }
    }

    return Ret;
}

int main(int argc, char *argv[])
{
    string Word;
    size_t WordLength = 0;
    string InputFile = "/home/nrjza/CppPrimerProjects/10.24/input.txt";
    string OutputFile = "/home/nrjza/CppPrimerProjects/10.24/output.txt";
    vector<int> LengthVec;
    vector<int> ResultVec;

    if(argc == 2)
    {
        Word = argv[1];
        WordLength = Word.size();

        if(readInput(InputFile, LengthVec) == RET_OK)
        {
            cout << "Read input done." << endl;
        }
        else
        {
            cout << "Read input error." << endl;
            return RET_FAIL;
        }

        if(compareLength(WordLength, LengthVec, ResultVec) == RET_OK)
        {
            cout << "Compare length done." << endl;
        }
        else
        {
            cout << "Compare length error." << endl;
            return RET_FAIL;
        }

        if(writeOutput(OutputFile, ResultVec) == RET_OK)
        {
            cout << "Running function success, the result is recorded in: " << endl;
            cout << OutputFile << endl;
        }
        else
        {
            cout << "Write output error." << endl;
            return RET_FAIL;
        }
    }
    else
    {
        cout << "Invalid calling format, please check." << endl;
    }

    return RET_OK;
}

