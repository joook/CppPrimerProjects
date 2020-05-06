#include <iostream>
#include "common.h"
#include "shared_text.h"
#include "search_result.h"
#include "query.h"

using namespace std;

int main()
{
    string FileName = "./input.txt";
    string KeyWord1 = "my";
    string KeyWord2 = "come";
    string KeyWord3 = "passed";
    
    SharedText Text(FileName);
    Query::setText(Text);

    while(true)
    {
        //Query Query1 = Query(KeyWord1) & Query(KeyWord2) | Query(KeyWord3);
        //Query Query2 = Query(KeyWord1) | Query(KeyWord2) & Query(KeyWord3);
        //Query Query3 = (Query(KeyWord1) | Query(KeyWord2)) & Query(KeyWord3);
        Query Query4 = (Query(KeyWord1) | Query(KeyWord2)) & ~Query(KeyWord3);
        //SearchResult Result1 = Query1.getResult();
        //SearchResult Result2 = Query2.getResult();
        //SearchResult Result3 = Query3.getResult();
        SearchResult Result4 = Query4.getResult();
        //printResult(Text, "my & come | passed", Result1);
        //printResult(Text, "my | come & passed", Result2);
        //printResult(Text, "(my | come) & passed", Result3);
        printResult(Text, "(my | come) & ~passed", Result4);

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
