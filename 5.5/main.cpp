#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> VecMarks;
    vector<string> VecGrades;
    int mark;

    while(cin >> mark)
    {
        VecMarks.push_back(mark);
    }

    if(VecMarks.size() == 0)
    {
        cout << "No valid input, quit." << endl;
        return -1;
    }

    for(auto it = VecMarks.begin(); it !=VecMarks.end(); ++it)
    {
        string grade;
        if(*it >= 95 && *it <=100)
        {
            grade = "A+";
        }
        else if(*it >= 90 && *it < 95)
        {
            grade = "A";
        }
        else if(*it >= 80 && *it < 90)
        {
            grade = "B";
        }
        else if(*it >= 60 && *it < 80)
        {
            grade = "C";
        }
        else if(*it >= 0 && *it < 60)
        {
            grade = "D";
        }
        else
        {
            grade = "ERROR";
        }
        VecGrades.push_back(grade);
    }

    int i = 0;
    for(auto it = VecGrades.begin(); it !=VecGrades.end(); ++it)
    {
        ++i;
        cout << "Student " << i << " gets the grade ";
        cout << *it << "." << endl;
    }

    return 0;
}
