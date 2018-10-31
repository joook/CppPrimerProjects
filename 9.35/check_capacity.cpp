#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> Vector1(3, 1);
    vector<string> Vector2(3, "1");

    Vector1.push_back(1);
    Vector2.push_back("1");
    cout << "Capacity of vector<int>: " << Vector1.capacity() << endl;
    cout << "Capacity of vector<string>: " << Vector2.capacity() << endl;
}
