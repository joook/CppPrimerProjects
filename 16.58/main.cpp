#include <iostream>
#include <string>
#include <cstdint>

#include "my_vector.h"

template <typename T>
void print(const T& container)
{
    for (auto itr = container.begin(); itr != container.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl << std::endl;
}

int main()
{
    MyVector<std::string> vec1;
    char arr[] = "abc";
    vec1.emplaceBack(arr, 2);
    print(vec1);

    MyVector<std::string> vec2 = vec1;
    vec2.emplaceBack(3, 'd');
    print(vec2);

    MyVector<std::uint16_t> vec3{100, 101, 102, 103, 104};
    vec3.emplaceBack(105);
    print(vec3);

    return 0;
}
