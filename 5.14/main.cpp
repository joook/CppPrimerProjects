#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int main()
{
    string word, PreWord, MaxWord;
    int WordCnt = 1;
    int WordCntMax = 0;

    while(cin >> word)
    {
        if(word == PreWord)
        {
            WordCnt++;
        }
        else
        {
            if(WordCnt > WordCntMax)
            {
                MaxWord = PreWord;
                WordCntMax = WordCnt;
            }
            else
            {
            }
            PreWord = word;
            WordCnt = 1;
        }
    }

    if(WordCntMax == 1)
    {
        cout << "No word repeats." << endl;
        return -1;
    }

    cout << "The word that repeats most is: ";
    cout << MaxWord << ", it appears ";
    cout << WordCntMax << " times." << endl;

    return 0;
}
