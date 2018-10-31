#include <iostream>
#include <vector>

using namespace std;

void findUnscender(const vector<string> &WholeDic, vector<string> &UnscenderDic)
{
    string Ascender = "bdfhijklt";
    string Descender = "gjpqy";
    bool IsAscender = true;
    bool IsDescender = true;

    UnscenderDic.clear();
    for(auto Itr = WholeDic.begin(); Itr != WholeDic.end(); Itr++)
    {
        IsAscender = ((*Itr).find_first_of(Ascender) != string::npos);
        IsDescender = ((*Itr).find_first_of(Descender) != string::npos);
        if(!IsAscender && !IsDescender)
        {
            UnscenderDic.push_back(*Itr);
        }
        else
        {
        }
    }
}

string findLongest(const vector<string> &Dictionary)
{
    string LongestWord = "";

    for(auto Itr = Dictionary.begin(); Itr != Dictionary.end(); Itr++)
    {
        if((*Itr).size() >= LongestWord.size())
        {
            LongestWord = *Itr;
        }
        else
        {
        }
    }
    return LongestWord;
}

int main()
{
    vector<string> WholeDic = {"zoo", "yellow", "optional", "source"};
    vector<string> UnscenderDic;

    findUnscender(WholeDic, UnscenderDic);
    cout << "Longest word is: " << findLongest(WholeDic) << endl;
    cout << "Longest unscender word is: " << findLongest(UnscenderDic) << endl;

    return 0;
}
