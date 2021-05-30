#include <iostream>

#include "compare.h"
#include "sales_data.h"

int main(int argc, char* argv[])
{
    SalesData a{"a", 1024, 20};
    SalesData b{"b", 1024, 15};

    std::cout << "Object a and b are the same: " << compare(a, b) << std::endl;
    return 0;
}

