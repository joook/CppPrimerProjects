#include <iostream>
#include <cstdint>
#include <string>

#include "my_unique_ptr.h"

template <typename T>
void print(const T& ptr)
{
    if (ptr)
    {
        std::cout << *ptr << std::endl;
    }
    else
    {
        std::cout << "Nullptr, quit." << std::endl;
    }
}

int main()
{
    MyUniquePtr<std::uint16_t> ptr1(new std::uint16_t(100));
    MyUniquePtr<std::uint16_t> ptr2 = std::move(ptr1);

    MyUniquePtr<std::string> ptr3{new std::string("abcd")};
    MyUniquePtr<std::string> ptr4;
    ptr4 = std::move(ptr3);

    print(ptr1);
    print(ptr2);
    print(ptr3);
    print(ptr4);

    return 0;
}
