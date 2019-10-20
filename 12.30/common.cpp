#include <string>
#include <set>
#include "common.h"

using namespace std;

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

