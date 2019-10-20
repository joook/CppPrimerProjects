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
    SharedText(const std::string &FileName);
    ~SharedText();
    SearchResult search(const std::string &KeyWord);

private:
    std::shared_ptr<std::vector<std::string>> m_TextPtr;
    std::map<std::string, std::set<size_t>> m_WordMap;
};

#endif
