#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> VecStr{"1", "11", "111"};

    auto it = VecStr.begin();
    cout << it++->size() << endl;

    //it = VecStr.begin();
    //cout << ++it->size() << endl;

    it = VecStr.begin();
    cout << (++it)->size() << endl;

    return 0;
}
