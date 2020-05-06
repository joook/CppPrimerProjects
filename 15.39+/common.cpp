#include <string>
#include <set>
#include <iostream>
#include "common.h"

using namespace std;

void removePunc(string &Line)
{
    static set<char> Punctuation = {',', '.', '!', '?', ';', ':', '"', '\'', '(', ')'};
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

void printResult(const SharedText &Text, const std::string &KeyWord, const SearchResult &Result)
{
    cout << '\"' << KeyWord << '\"' << "appears in ";
    cout << Result.size() << " line(s): " << endl;
    for(auto Itr = Result.begin(); Itr != Result.end(); Itr++)
    {
        cout << "    " << "(line " << *Itr << ")";
        cout << Text.at(*Itr) << endl;
    }
}

