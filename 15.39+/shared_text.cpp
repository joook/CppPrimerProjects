#include <iostream>
#include <fstream>
#include <sstream>
#include "common.h"
#include "shared_text.h"
#include "search_result.h"

using namespace std;

SharedText::SharedText(const string &FileName)
: m_TextPtr(make_shared<vector<string>>())
, m_WordMap()
{
    ifstream FileStream(FileName);
    if(FileStream.is_open())
    {
        string Line;
        while(getline(FileStream, Line))
        {
            m_TextPtr->push_back(Line);
        }
        FileStream.close();
    }
    else
    {
        cout << "Can not open file." << endl;
    }

    size_t LineNumber = 0;
    for(string Line : *m_TextPtr)
    {
        removePunc(Line);
        replaceCap(Line);

        string Word;
        istringstream LineStream(Line);
        while(LineStream >> Word)
        {
            m_WordMap[Word].insert(LineNumber);
        }

        LineNumber++;
    }
}

SearchResult SharedText::search(const string &KeyWord) const
{
    auto Itr = m_WordMap.find(KeyWord);
    if(Itr != m_WordMap.cend())
    {
        SearchResult Result(Itr->second);
        return Result;
    }
    else
    {
        SearchResult Result;
        return Result;
    }
}

string SharedText::at(size_t LineNumber) const
{
    string TempStr;
    if(m_TextPtr->size() > LineNumber)
    {
        TempStr = m_TextPtr->at(LineNumber);
    }
    else
    {
    }
    return TempStr;
}

