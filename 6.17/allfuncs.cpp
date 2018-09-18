#include <iostream>
#include "allfuncs.h"

using std::string;

bool checkcap(const string &s)
{
    bool ret = false;
    for(auto c : s)
    {
        if(c >= 'A' && c <='Z')
        {
            ret = true;
        }
        else
        {
        }
    }
    return ret;
}

void lower(string &s)
{
    for(auto &c : s)
    {
        if(c >= 'A' && c <='Z')
        {
            c = c+32;
        }
        else
        {
        }
    }
}
