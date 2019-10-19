#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

#define RET_OK 0
#define RET_FAIL 1

void removePunc(string &Line)
{
    set<char> Punctuation = {',', '.', '!', '?', ';', ':', '"', '\'', '(', ')'};
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

int readInput(const string &FileName, vector<string> &OriginalText)
{
    int Ret = RET_OK;
    ifstream FileStream(FileName);
    if(FileStream.is_open())
    {
        string Line;
        while(getline(FileStream, Line))
        {
            OriginalText.push_back(Line);
        }
        FileStream.close();
    }
    else
    {
        cout << "Can not open file." << endl;
        Ret = RET_FAIL;
    }
    return Ret;
}

int mapWord(const vector<string> &OriginalText, map<string, set<size_t>> &WordMap)
{
    int Ret = RET_OK;
    size_t LineNumber = 0;
    for(string Line : OriginalText)
    {
        removePunc(Line);
        replaceCap(Line);

        string Word;
        istringstream LineStream(Line);
        while(LineStream >> Word)
        {
            WordMap[Word].insert(LineNumber);
        }

        LineNumber++;
    }
    return Ret;
}

int askKeyWord(string &KeyWord)
{
    int Ret = RET_OK;
    cout << "Type in a word you want to search: " << endl;
    if(cin >> KeyWord)
    {
        removePunc(KeyWord);
        replaceCap(KeyWord);
        char c;
        while((c = cin.get()) && (c != '\n') && (c != EOF))
        {
        }
        Ret = RET_OK;
    }
    else
    {
        Ret = RET_FAIL;
    }
    return Ret;
}

int searchWord(const string &KeyWord, const map<string, set<size_t>> &WordMap, set<size_t> &SearchResult)
{
    int Ret = RET_OK;
    auto Itr = WordMap.find(KeyWord);
    if(Itr != WordMap.cend())
    {
        SearchResult = Itr->second;
    }
    else
    {
        //do nothing
    }
    return Ret;
}

int printResult(const string &KeyWord, const set<size_t> &SearchResult, const vector<string> &OriginalText)
{
    int Ret = RET_OK;
    cout << '\"' << KeyWord << '\"' << "appears in ";
    cout << SearchResult.size() << " line(s): " << endl;
    for(size_t Pos : SearchResult)
    {
        cout << "    " << "(line " << Pos << ")";
        cout << OriginalText.at(Pos) << endl;
    }
    return Ret;
}

int askOneMore()
{
    int Ret = RET_OK;
    char OneMore;
    cout << "Conduct another search? y or n." << endl;
    if(cin >> OneMore && OneMore == 'y')
    {
        char c;
        while((c = cin.get()) && (c != '\n') && (c != EOF))
        {
        }
        Ret = RET_OK;
    }
    else
    {
        Ret = RET_FAIL;
    }
    return Ret;
}

int main()
{
    string FileName = "./input.txt";
    vector<string> OriginalText;
    map<string, set<size_t>> WordMap;
    set<size_t> SearchResult;
    string KeyWord;

    if(readInput(FileName, OriginalText) == RET_OK)
    {
        mapWord(OriginalText, WordMap);
    }
    else
    {
        return -1;
    }

    while(true)
    {
        askKeyWord(KeyWord);
        searchWord(KeyWord, WordMap, SearchResult);
        printResult(KeyWord, SearchResult, OriginalText);

        if(askOneMore() == RET_OK)
        {
            //go on
        }
        else
        {
            break; //break while
        }

    }

    return 0;
}
