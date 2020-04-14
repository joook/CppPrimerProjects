#include "string_class.h"
#include <iostream>
#include <vector>

using namespace std;

void printVecInfo(const vector<Str> &Vec)
{
    cout << "Vector size: " << Vec.size();
    cout << ", capacity: " << Vec.capacity() << endl;
}

int main()
{
    vector<Str> VecStr;
    Str Str1("abcd");
    Str Str2("efgh");

    //if the vector has not reserved enough space for elements,
    //elements will be moved when the vector expands
    VecStr.reserve(10);
    printVecInfo(VecStr);

    VecStr.push_back(Str1);
    printVecInfo(VecStr);
    VecStr.push_back(Str1);
    printVecInfo(VecStr);
    VecStr.push_back(std::move(Str2));
    printVecInfo(VecStr);
    VecStr.push_back("ijkl");
    printVecInfo(VecStr);

    return 0;
}
