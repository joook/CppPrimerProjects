#ifndef _SEARCH_RESULT_H_
#define _SEARCH_RESULT_H_

#include <set>

class SearchResult
{
public:
    SearchResult() = default;
    SearchResult(const std::set<size_t> &Result)
    : m_Result(Result)
    {
    }
    size_t size() const { return m_Result.size(); }
    std::set<size_t>::iterator begin() const { return m_Result.begin(); }
    std::set<size_t>::iterator end() const { return m_Result.end(); }

private:
    std::set<size_t> m_Result;
};

SearchResult operator|(const SearchResult &Result1, const SearchResult &Result2);
SearchResult operator&(const SearchResult &Result1, const SearchResult &Result2);

#endif
