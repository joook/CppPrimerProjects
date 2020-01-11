#ifndef _SEARCH_RESULT_H_
#define _SEARCH_RESULT_H_

#include <string>
#include <set>
#include <map>
#include <memory>
#include "string_vector_class.h"

class SearchResult
{
public:
    SearchResult(const std::string &KeyWord, std::shared_ptr<StrVec> TextPtr);
    SearchResult(const std::string &KeyWord, std::shared_ptr<StrVec> TextPtr, const std::set<size_t> &Result);
    ~SearchResult();
    void print();
private:
    std::string m_KeyWord;
    std::shared_ptr<StrVec> m_TextPtr;
    std::set<size_t> m_Result;
};

#endif
