#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::string word;
    std::string line;
    std::ofstream text;
    text.open("Text.txt", std::ios::app);
    /*
    cout << "Type in a message: " << endl;
    while (cin >> word)
    {
        text << word << " ";
    }
    text << endl;
    */

    cout << "Type in the message again: " << endl;
    while (getline(cin, line))
    {
        text << line << endl;
    }
    text << endl;
    text.close();

    return 0;
}
