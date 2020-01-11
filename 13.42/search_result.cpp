#include <iostream>
#include "search_result.h"

using namespace std;

SearchResult::SearchResult(const string &KeyWord, shared_ptr<StrVec> TextPtr)
: m_KeyWord(KeyWord)
, m_TextPtr(TextPtr)
, m_Result()
{
}

SearchResult::SearchResult(const string &KeyWord, shared_ptr<StrVec> TextPtr, const set<size_t> &Result)
: m_KeyWord(KeyWord)
, m_TextPtr(TextPtr)
, m_Result(Result)
{
}

SearchResult::~SearchResult()
{
    //do nothing
}

void SearchResult::print()
{
    cout << '\"' << m_KeyWord << '\"' << "appears in ";
    cout << m_Result.size() << " line(s): " << endl;
    for(size_t Pos : m_Result)
    {
        cout << "    " << "(line " << Pos << ")";
        cout << m_TextPtr->at(Pos) << endl;
    }
}

