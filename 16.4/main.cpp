#include <cstdint>

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

#include "my_find.h"

int main(int argc, char* argv[])
{
    std::vector<std::int16_t> vec;
    for (std::int16_t i = 0; i < 10; i++)
    {
        vec.push_back(i);
    }
    std::cout << "A vector<int16_t>:" << std::endl;
    myPrint(vec.begin(), vec.end());

    std::int16_t item1 = 7;
    std::cout << "Find item: " << item1 << " in the vector using find()." << std::endl;
    auto itr = find(vec.begin(), vec.end(), item1);
    if (itr == vec.end())
    {
        std::cout << "Not found." << std::endl;
    }
    else
    {
        std::cout << "Found." << std::endl;
    }

    std::cout << "Find item: " << item1 << " in the vector using myFind()." << std::endl;
    auto itr1 = myFind(vec.begin(), vec.end(), item1);
    if (itr1 == vec.end())
    {
        std::cout << "Not found." << std::endl;
    }
    else
    {
        std::cout << "Found." << std::endl;
    }

    std::list<std::string> lst{"hello", ", ", "world", "!"};
    std::cout << "A list<string>:" << std::endl;
    myPrint(lst.begin(), lst.end());

    std::string item2 = "world";
    std::cout << "Find item: " << item2 << " in the list using myFind()." << std::endl;
    auto itr2 = myFind(lst.begin(), lst.end(), item2);
    if (itr2 == lst.end())
    {
        std::cout << "Not found." << std::endl;
    }
    else
    {
        std::cout << "Found." << std::endl;
    }

    return 0;
}

