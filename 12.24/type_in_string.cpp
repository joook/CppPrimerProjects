#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    char *StrPtr = new char[10];
    char Char;
    size_t Pos = 0;

    cout << "Type in a string: " << endl;
    while(cin.get(Char) && Char != '\n' && Char != EOF)
    {
        if(Pos < 10)
        {
            StrPtr[Pos] = Char;
            Pos++;
        }
        else
        {
            cout << "Error: String too long." << endl;
            break; //break while
        }
    }

    cout << "The string is: " << endl;
    for(size_t i = 0; i < Pos; i++)
    {
        cout << StrPtr[i];
    }
    cout << endl;

    delete []StrPtr;

    return 0;
}

