#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    const char *Str1 = "I have";
    const char *Str2 = " a dream.";

    char *ConStr = new char[strlen(Str1)+strlen(Str2)+1];
    strcpy(ConStr, Str1);
    strcat(ConStr, Str2);
    cout << ConStr << endl;
    delete []ConStr;

    return 0;
}


