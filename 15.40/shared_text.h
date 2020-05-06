#ifndef _SHARED_TEXT_H_
#define _SHARED_TEXT_H_

#include <vector>
#include <string>
#include <set>
#include <map>
#include <memory>

class SearchResult;

class SharedText
{
public:
    SharedText() = default;
    SharedText(const std::string &FileName);
    SearchResult search(const std::string &KeyWord) const;
    std::string at(size_t LineNumber) const;
    size_t size() const { return m_TextPtr->size(); }

private:
    std::shared_ptr<std::vector<std::string>> m_TextPtr;
    std::map<std::string, std::set<size_t>> m_WordMap;
};

#endif
