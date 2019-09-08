#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    string FileName;
    map<string, size_t> WordMap;

    if(argc == 2)
    {
        FileName = argv[1];
        ifstream FileStream(FileName);
        if(FileStream.is_open())
        {
            string TempWord;
            while(FileStream >> TempWord)
            {
                WordMap[TempWord]++;
            }

            for(auto &Pair : WordMap)
            {
                cout << Pair.first << " appears " << Pair.second;
                cout << ((Pair.second > 1) ? " times" : " time") << endl;
            }

            FileStream.close();
        }
        else
        {
            throw runtime_error("Cannot open file, quit.");
        }

    }
    else
    {
        throw runtime_error("Invalid input format, quit.");
    }

    return 0;
}
