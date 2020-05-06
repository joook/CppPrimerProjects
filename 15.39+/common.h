#ifndef _COMMON_H_
#define _COMMON_H_

#include <string>
#include "shared_text.h"
#include "search_result.h"

#define RET_OK 0
#define RET_FAIL 1

void removePunc(std::string &Line);
void replaceCap(std::string &Line);
int askOneMore();
void printResult(const SharedText &Text, const std::string &KeyWord, const SearchResult &Result);

#endif
