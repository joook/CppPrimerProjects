#include <iostream>
#include <cstdint>
#include <string>

#include "shared_vector_template.h"
#include "shared_vector_itr_template.h"

int main()
{
    SharedVector<std::uint16_t> vec1{100, 101};
    SharedVector<std::uint16_t> vec2{vec1};

    vec2.pushBackItem(102);
    vec1.pushBackItem(103);
    vec2.popBackItem();

    for (auto itr = vec2.beginItr(); itr != vec2.endItr(); itr++)
    {
        std::cout << *itr << std::endl;
    }

    return 0;
}
