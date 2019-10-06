#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<int> pNum(new int(100));

    //unique_ptr<int> pNum2(pNum);

    //unique_ptr<int> pNum1;
    //pNum1 = pNum;

    cout << *pNum << endl;

    return 0;
}
