#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

int main()
{
    for(int i = 0; i < 10000; i++)
    {
        shared_ptr<int> pNum1 = make_shared<int>(i);
        shared_ptr<int> pNum2(new int(i));
        int *pNum3 = pNum1.get();
        {
            shared_ptr<int>(pNum3);
        }

        vector<double> *pNumVec = new vector<double>();
        pNumVec->resize(10000);
        pNumVec->push_back(1.234);
        delete pNumVec;

        /*
        as a test, i didn't see the freed memory(pNum1) overwritten,
        maybe there is a better way to test it
        */
        if(*pNum1 != *pNum2)
        {
            cout << "*pNum1 = " << *pNum1 << endl;
            cout << "*pNum2 = " << *pNum2 << endl;
        }
        else
        {
        }
    }
    return 0;
}
