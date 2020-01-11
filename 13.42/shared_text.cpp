#include <iostream>
#include <fstream>
#include <sstream>
#include "common.h"
#include "shared_text.h"
#include "search_result.h"

using namespace std;

SharedText::SharedText(const string &FileName)
: m_TextPtr(make_shared<StrVec>())
, m_WordMap()
{
    ifstream FileStream(FileName);
    if(FileStream.is_open())
    {
        string Line;
        while(getline(FileStream, Line))
        {
            m_TextPtr->pushBack(Line);
        }
        FileStream.close();
    }
    else
    {
        cout << "Can not open file." << endl;
    }

    size_t LineNumber = 0;
    for(string *Itr = m_TextPtr->begin(); Itr !=m_TextPtr->end(); Itr++)
    {
        string Line = *Itr;
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

SharedText::~SharedText()
{
    //do nothing
}

SearchResult SharedText::search(const string &KeyWord)
{
    auto Itr = m_WordMap.find(KeyWord);
    if(Itr != m_WordMap.cend())
    {
        SearchResult Result(KeyWord, m_TextPtr, Itr->second);
        return Result;
    }
    else
    {
        SearchResult Result(KeyWord, m_TextPtr);
        return Result;
    }
}


