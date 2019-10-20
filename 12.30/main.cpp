#include <iostream>
#include "common.h"
#include "shared_text.h"
#include "search_result.h"

using namespace std;

int askKeyWord(string &KeyWord)
{
    int Ret = RET_OK;
    cout << "Type in a word you want to search: " << endl;
    if(cin >> KeyWord)
    {
        removePunc(KeyWord);
        replaceCap(KeyWord);
        char c;
        while((c = cin.get()) && (c != '\n') && (c != EOF))
        {
        }
        Ret = RET_OK;
    }
    else
    {
        Ret = RET_FAIL;
    }
    return Ret;
}

int askOneMore()
{
    int Ret = RET_OK;
    char OneMore;
    cout << "Conduct another search? y or n." << endl;
    if(cin >> OneMore && OneMore == 'y')
    {
        char c;
        while((c = cin.get()) && (c != '\n') && (c != EOF))
        {
        }
        Ret = RET_OK;
    }
    else
    {
        Ret = RET_FAIL;
    }
    return Ret;
}

int main()
{
    string FileName = "./input.txt";
    string KeyWord;
    
    SharedText Text(FileName);

    while(true)
    {
        askKeyWord(KeyWord);

        SearchResult Result = Text.search(KeyWord);

        Result.print();

        if(askOneMore() == RET_OK)
        {
            //go on
        }
        else
        {
            break; //break while
        }
    }

    return 0;
}
