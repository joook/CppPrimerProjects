#include <set>
#include <algorithm>
#include "search_result.h"

using namespace std;

SearchResult operator|(const SearchResult &Result1, const SearchResult &Result2)
{
    set<size_t> TempResult(Result1.begin(), Result1.end());
    TempResult.insert(Result2.begin(), Result2.end());
    return SearchResult(TempResult);
}

SearchResult operator&(const SearchResult &Result1, const SearchResult &Result2)
{
    set<size_t> TempResult;
    set_intersection(Result1.begin(), Result1.end(), Result2.begin(), Result2.end(), inserter(TempResult, TempResult.begin()));
    return SearchResult(TempResult);
}

