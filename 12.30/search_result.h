#ifndef _SEARCH_RESULT_H_
#define _SEARCH_RESULT_H_

#include <vector>
#include <string>
#include <set>
#include <map>
#include <memory>

class SearchResult
{
public:
    SearchResult(const std::string &KeyWord, std::shared_ptr<std::vector<std::string>> TextPtr);
    SearchResult(const std::string &KeyWord, std::shared_ptr<std::vector<std::string>> TextPtr, const std::set<size_t> &Result);
    ~SearchResult();
    void print();
private:
    std::string m_KeyWord;
    std::shared_ptr<std::vector<std::string>> m_TextPtr;
    std::set<size_t> m_Result;
};

#endif
