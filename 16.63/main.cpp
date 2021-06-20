#include <iostream>
#include <vector>
#include <string>

#include "get_count.h"

int main(int argc, char* argv[])
{
    std::vector<int> a{100, 101, 102, 100};
    std::vector<double> b{1.0, 1.1, 1.2, 1.0};
    std::vector<std::string> c{"ab", "cd", "ef", "ab"};
    std::vector<const char*> d{"ab", "cd", "ef", "ab"};

    int keyA = 100;
    double keyB = 1.5;
    std::string keyC = "ef";
    const char* keyD = "ab";

    std::cout << "Key " << keyA << " appears " << getCount(keyA, a.begin(), a.end()) << " time(s)." << std::endl;
    std::cout << "Key " << keyB << " appears " << getCount(keyB, b.begin(), b.end()) << " time(s)." << std::endl;
    std::cout << "Key " << keyC << " appears " << getCount(keyC, c.begin(), c.end()) << " time(s)." << std::endl;
    std::cout << "Key " << keyD << " appears " << getCount(keyD, d.begin(), d.end()) << " time(s)." << std::endl;

    return 0;
}

