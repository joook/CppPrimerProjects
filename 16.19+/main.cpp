#include <iostream>
#include <vector>
#include <string>
#include <list>

#include "print.h"

int main(int argc, char* argv[])
{
    const std::vector<std::string> vec{"ab", "cd", "ef"};
    std::list<std::uint32_t> lst{100, 101, 102};

    print(vec);
    std::cout << std::endl;

    print(lst);
    std::cout << std::endl;

    return 0;
}
