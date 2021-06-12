#include <iostream>
#include <cstdint>
#include <string>
#include <array>
#include <list>

#include "shared_vector_template.h"
#include "shared_vector_itr_template.h"

int main()
{
    const std::array<std::uint16_t, 5> arr{1, 2, 3, 4, 5};
    std::list<std::string> lst{"ab", "cd", "ef"};

    SharedVector<std::uint16_t> vec(arr.begin(), arr.end());
    SharedVector<std::string> vec1(lst.begin(), lst.end());

    for (auto itr = vec.beginItr(); itr != vec.endItr(); itr++)
    {
        std::cout << *itr << std::endl;
    }

    for (auto itr = vec1.beginItr(); itr != vec1.endItr(); itr++)
    {
        std::cout << *itr << std::endl;
    }

    return 0;
}
