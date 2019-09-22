#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

void readRule(const string &RuleFile, map<string, string> &RuleMap)
{
    ifstream FileStream(RuleFile);
    if(FileStream.is_open())
    {
        RuleMap.clear();

        string Line;
        while(getline(FileStream, Line))
        {
            size_t Pos = Line.find("->");
            if(Pos != string::npos)
            {
                string Key = Line.substr(0, Pos);
                string Value = Line.substr(Pos+2);
                RuleMap[Key] = Value;
            }
            else
            {
                //dump line
            }
        }

        FileStream.close();
    }
    else
    {
        cout << "Can not open rule file." << endl;
    }
}

void readText(const string &TextFile, vector<vector<string>> &TextVec)
{
    ifstream FileStream(TextFile);
    if(FileStream.is_open())
    {
        TextVec.clear();
        
        string Line;
        vector<string> LineVec;
        while(getline(FileStream, Line))
        {
            LineVec.clear();

            istringstream StringStream(Line);
            string Word;
            while(StringStream >> Word)
            {
                LineVec.push_back(Word);
            }

            TextVec.push_back(LineVec);
        }

        FileStream.close();
    }
    else
    {
        cout << "Can not open text file." << endl;
    }
}

void replaceWord(const map<string, string> &RuleMap, vector<vector<string>> &TextVec)
{
    for(auto &LineVec : TextVec)
    {
        for(const auto Pair : RuleMap)
        {
            replace(LineVec.begin(), LineVec.end(), Pair.first, Pair.second);
        }
    }
}

void printText(const vector<vector<string>> &TextVec)
{
    for(const auto &Line : TextVec)
    {
        for(const auto &Word : Line)
        {
            cout << Word << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    string RuleFile = "./rule.txt";
    string TextFile = "./text.txt";
    map<string, string> RuleMap;
    vector<vector<string>> TextVec;

    readRule(RuleFile, RuleMap);
    readText(TextFile, TextVec);

    cout << "Before replace, text is: " << endl;
    printText(TextVec);

    replaceWord(RuleMap, TextVec);

    cout << "After replace, text is: " << endl;
    printText(TextVec);

    return 0;
}
