#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> AllMarks;
    int Mark;
    vector<int> MarkCount(11, 0);

    while(cin >> Mark)
    {
        AllMarks.push_back(Mark);
    }

    for(auto it = AllMarks.begin(); it != AllMarks.end(); ++it)
    {
        int k = *it/10;
        MarkCount[k]++;
    }

    for(int it = 0; it != 11; ++it)
    {
        cout << "The number of students in zone (";
        if(it != 10)
        {
            cout << it << "0" << " ~ " << it << "9";
        }
        else
        {
            cout << "100";
        }
        cout << ") is: " << MarkCount[it] << endl;
    }

    return 0;
}
