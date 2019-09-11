#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <sstream>

using namespace std;

void readInput(const string &FileName, vector<pair<string, int>> &RankVec)
{
    ifstream FileStream(FileName);
    if(FileStream.is_open())
    {
        RankVec.clear();
        string Line;
        //see a better answer in answer book
        while(getline(FileStream, Line))
        {
            istringstream StringStream(Line);
            string Animal;
            int Rank;
            StringStream >> Animal >> Rank;
            pair<string, int> Pair = {Animal, Rank};
            RankVec.push_back(Pair);
        }
        FileStream.close();
    }
    else
    {
        cout << "Cannot open file, quit." << endl;
    }
}

void printVec(const vector<pair<string, int>> &RankVec)
{
    for(const auto &Pair : RankVec)
    {
        cout << "<" << Pair.first << ", " << Pair.second << ">" << endl;
    }
}

int main(int argc, char *argv[])
{
    string FileName;
    vector<pair<string, int>> RankVec;

    if(argc == 2)
    {
        FileName = argv[1];
        readInput(FileName, RankVec);
        printVec(RankVec);
    }
    else
    {
        cout << "Input format error, quit." << endl;
    }

    return 0;
}
