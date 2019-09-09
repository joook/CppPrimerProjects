#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void removePunc(string &Line)
{
    set<char> Punctuation = {',', '.', '!', '?', ';', ':', '"', '\''};
    auto Itr = Line.begin();
    while(Itr != Line.cend())
    {
        if(Punctuation.find(*Itr) != Punctuation.cend())
        {
            Itr = Line.erase(Itr);
        }
        else
        {
            Itr++;
        }
    }
}

void replaceCap(string &Line)
{
    for(char &Char : Line)
    {
        if(Char >= 'A' && Char <= 'Z')
        {
            Char = Char-'A'+'a';
        }
        else
        {
        }
    }
}

void readInput(const string &FileName, map<size_t, string> &LineMap)
{
    ifstream FileStream(FileName);
    if(FileStream.is_open())
    {
        string Line;
        size_t n = 0;

        while(getline(FileStream, Line))
        {
            n++;
            removePunc(Line);
            replaceCap(Line);
            LineMap[n] = Line;
        }

        FileStream.close();
    }
    else
    {
        throw runtime_error("Cannot open file, quit.");
    }
}

void createMap(const map<size_t, string> &LineMap, map<string, set<size_t>> &WordMap)
{
    WordMap.clear();
    for(const auto &Pair : LineMap)
    {
        size_t LineNum = Pair.first;
        string Line = Pair.second;
        string Word;

        istringstream StringStream(Line);
        while(StringStream >> Word)
        {
            WordMap[Word].insert(LineNum);
        }
    }
}

void printMap(const map<string, set<size_t>> &WordMap)
{
    for(const auto &Pair : WordMap)
    {
        string Word = Pair.first;
        set<size_t> LineNums = Pair.second;
        cout << "\"" << Word << "\"" << " appears at: ";
        for(const auto &LineNum : LineNums)
        {
            cout << LineNum << ", ";
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    string FileName;
    map<size_t, string> LineMap;
    map<string, set<size_t>> WordMap;

    if(argc == 2)
    {
        FileName = argv[1];

        readInput(FileName, LineMap);

        createMap(LineMap, WordMap);

        printMap(WordMap);
    }
    else
    {
        throw runtime_error("Invalid input format, quit.");
    }

    return 0;
}

