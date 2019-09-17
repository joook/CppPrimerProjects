#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

void readMap(const string &FileName, map<string, size_t> &WordCountMap)
{
    ifstream FileStream(FileName);
    if(FileStream.is_open())
    {
        WordCountMap.clear();
        string Word;
        while(FileStream >> Word)
        {
            //WordCountMap[Word]++;
            auto Ret = WordCountMap.insert({Word, 1});
            if(Ret.second == false)
            {
                (Ret.first->second)++;
            }
            else
            {
                //do nothng
            }
        }
        FileStream.close();
    }
    else
    {
        cout << "Can not open file." << endl;
    }
}

void printMap(const map<string, size_t> &WordCountMap)
{
    auto Itr = WordCountMap.begin();
    while(Itr != WordCountMap.cend())
    {
        cout << Itr->first << " appears " << Itr->second;
        cout << ((Itr->second > 1) ? " times" : " time") << endl;
        Itr++;
    }
}

int main()
{
    string FileName = "./input.txt";
    map<string, size_t> WordCountMap;

    readMap(FileName, WordCountMap);
    cout << "After read, WordCountMap is:" << endl;
    printMap(WordCountMap);

    return 0;
}
