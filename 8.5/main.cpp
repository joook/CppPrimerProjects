#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void writeFile(ofstream &WriteOnlyFile, string &FileName)
{
    string TempStr;
    WriteOnlyFile.open(FileName);
    while(getline(cin, TempStr))
    {
        WriteOnlyFile << TempStr << endl;
    }
    WriteOnlyFile.close();
}

int main()
{
    ofstream WriteOnlyFile;
    string FileName = "func_log.txt";

    cout << "Type in log: " << endl;
    writeFile(WriteOnlyFile, FileName);

    return 0;
}
