#include <iostream>
#include <cstdint>

#include "add.h"

int main(int argc, char* argv[])
{
    auto res1 = add_without_expand(std::uint16_t(65530), std::uint16_t(6));
    auto res2 = add_with_expand(std::uint16_t(65530), std::uint8_t(6));

    std::cout << "Result of add_without_expand: " << res1 << std::endl;
    std::cout << "Result of add_with_expand: " << res2 << std::endl;

    return 0;
}
