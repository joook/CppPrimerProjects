#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

//typedef string::size_type size_t

string make_plural(size_t, const string &, const string &ending = "s");

int main()
{
    string word;
    int num;
    string is_s;

    cout << "Input a word: " << endl;
    cin >> word;
    cout << "The number of \"" << word << "\" is: " << endl;
    cin >> num;
    cout << "The ending of \"" << word << "\" is \"s\"?" << endl;
    cout << "(y or n)" << endl;
    cin >> is_s;

    cout << "The form of it should be: ";
    if(!cin || is_s == "y")
    {
        cout << make_plural(num, word) << endl;
    }
    else
    {
        cout << make_plural(num, word, "es") << endl;
    }

    return 0;
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}
