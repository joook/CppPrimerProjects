#include <iostream>
#include <string>

using namespace std;

int main()
{
    char CharArray[] = {'a', 'p', 'p', 'l', 'e', '\0', 's'};
    //string String = CharArray; //this will end at '\0'
    //string String(CharArray); //this will end at '\0'
    string String;
    //String.assign(CharArray, CharArray+7);
    String.insert(String.end(), CharArray, CharArray+7);
    cout << "String is: " << String << endl;

    return 0;
}
