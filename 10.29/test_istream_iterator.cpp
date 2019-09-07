#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

int main()
{
    string FileName = "./input.txt";
    ifstream FileStream(FileName);
    if(FileStream.is_open())
    {
        istream_iterator<string> ItrBegin(FileStream);
        istream_iterator<string> ItrEnd;
        vector<string> StrVec(ItrBegin, ItrEnd);

        for(auto Itr = StrVec.begin(); Itr != StrVec.cend(); Itr++)
        {
            cout << *Itr << endl;
        }
    }
    else
    {
        cout << "Cannot open file." << endl;
        return -1;
    }

    return 0;
}
