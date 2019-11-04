#include <iostream>
#include <vector>
#include <algorithm>
#include "valuelike_string_ptr.h"

using namespace std;

int main()
{
    vector<StrPtr> NameVec;
    NameVec.push_back(StrPtr("Tom"));
    NameVec.push_back(StrPtr("Jerry"));
    NameVec.push_back(StrPtr("Hardy"));
    NameVec.push_back(StrPtr("Kate"));
    NameVec.push_back(StrPtr("Louis"));
    NameVec.push_back(StrPtr("Tom"));
    NameVec.push_back(StrPtr("Jerry"));
    NameVec.push_back(StrPtr("Hardy"));
    NameVec.push_back(StrPtr("Kate"));
    NameVec.push_back(StrPtr("Louis"));
    NameVec.push_back(StrPtr("Tom"));
    NameVec.push_back(StrPtr("Jerry"));
    NameVec.push_back(StrPtr("Hardy"));
    NameVec.push_back(StrPtr("Kate"));
    NameVec.push_back(StrPtr("Louis"));
    NameVec.push_back(StrPtr("Tom"));
    NameVec.push_back(StrPtr("Jerry"));
    NameVec.push_back(StrPtr("Hardy"));
    NameVec.push_back(StrPtr("Kate"));
    NameVec.push_back(StrPtr("Louis"));

    sort(NameVec.begin(), NameVec.end());

    cout << "After sort, the name list is: " << endl;
    for(const auto TempPtr : NameVec)
    {
        TempPtr.print();
    }

    return 0;
}
