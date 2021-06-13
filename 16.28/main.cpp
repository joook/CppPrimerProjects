#include <iostream>
#include <cstdint>
#include <string>

#include "my_shared_ptr.h"

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
    MySharedPtr<std::uint16_t> ptr1(new std::uint16_t(100));
    MySharedPtr<std::uint16_t> ptr2 = ptr1;

    MySharedPtr<std::string> ptr3{new std::string("abcd")};
    MySharedPtr<std::string> ptr4;
    ptr4 = ptr3;

    print(ptr1);
    print(ptr2);
    print(ptr3);
    print(ptr4);

    return 0;
}
