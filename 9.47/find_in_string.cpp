#include <iostream>

using namespace std;

void findNum(const string &SourceString)
{
    string Rule = "1234567890";

    auto Position = SourceString.find_first_of(Rule);
    if(Position == string::npos)
    {
        cout << "No number in the string." << endl;
    }
    else
    {
        cout << "The position of number(s) in the string: " << endl;
    }
    while(Position != string::npos)
    {
        cout << Position << " ";
        Position++;
        Position = SourceString.find_first_of(Rule, Position);
    }
    cout << endl;
}

void findLetter(const string &SourceString)
{
    string Rule = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string RuleNum = "1234567890";

    //auto Position = SourceString.find_first_of(Rule);
    auto Position = SourceString.find_first_not_of(RuleNum);
    if(Position == string::npos)
    {
        cout << "No letter in the string." << endl;
    }
    else
    {
        cout << "The position of letter(s) in the string: " << endl;
    }
    while(Position != string::npos)
    {
        cout << Position << " ";
        Position++;
        //Position = SourceString.find_first_of(Rule, Position);
        Position = SourceString.find_first_not_of(RuleNum, Position);
    }
    cout << endl;
}

int main()
{
    string SourceString = "ab2c3d7R4E6";

    cout << "The string is: " << endl << SourceString << endl;
    findNum(SourceString);
    findLetter(SourceString);

    return 0;
}
