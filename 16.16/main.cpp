#include <iostream>
#include <string>

#include "my_vector.h"

int main()
{
    MyVector<std::string> vec1;
    std::string str = "ab";
    vec1.pushBack(str);

    MyVector<std::string> vec2 = vec1;
    vec2.pushBack("cd");

    MyVector<std::uint16_t> vec3{100, 101, 102, 103, 104};
    vec3.pushBack(105);

    return 0;
}
