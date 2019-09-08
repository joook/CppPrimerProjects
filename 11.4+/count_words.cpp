#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

void removePunc(string &Word)
{
    set<char> Punctuation = {',', '.', '!', '?', ';', ':', '"', '\''};
    auto Itr = Word.begin();
    while(Itr != Word.cend())
    {
        if(Punctuation.find(*Itr) != Punctuation.cend())
        {
            Itr = Word.erase(Itr);
        }
        else
        {
            Itr++;
        }
    }
}

void replaceCap(string &Word)
{
    for(char &Char : Word)
    {
        if(Char >= 'A' && Char <= 'Z')
        {
            Char = Char + 32;
        }
        else
        {
        }
    }
}

void readInput(const string &FileName, vector<string> &WordVec)
{
    ifstream FileStream(FileName);
    if(FileStream.is_open())
    {
        string Word;
        while(FileStream >> Word)
        {
            removePunc(Word);
            replaceCap(Word);
            WordVec.push_back(Word);
        }

        FileStream.close();
    }
    else
    {
        throw runtime_error("Cannot open file, quit.");
    }
}

void createMap(const vector<string> &WordVec, map<string, size_t> &WordMap)
{
    WordMap.clear();
    for(auto TempWord : WordVec)
    {
        WordMap[TempWord]++;
    }
}

int main(int argc, char *argv[])
{
    string FileName;
    vector<string> WordVec;
    map<string, size_t> WordMap;

    if(argc == 2)
    {
        FileName = argv[1];

        readInput(FileName, WordVec);

        createMap(WordVec, WordMap);

        for(auto &Pair : WordMap)
        {
            cout << Pair.first << " appears " << Pair.second;
            cout << ((Pair.second > 1) ? " times" : " time") << endl;
        }
    }
    else
    {
        throw runtime_error("Invalid input format, quit.");
    }

    return 0;
}
