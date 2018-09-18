#include <iostream>
#include "Sales_item.h"

int main()
{
    std::cout << "Info of 1st book:" << std::endl;
    std::cout << "13-43-789-567" << std::endl;
    std::cout << "23" << std::endl;
    std::cout << "15.0" << std::endl;
    std::string str = "13-43-789-567";
    unsigned so = 23;
    double eo = 15.0;
    Sales_item a(str, so, eo);
    std::cout << "Input info of 2nd book:" << std::endl;
    Sales_item b(std::cin);
    std::cout << "Revenue of book " << a.isbn() << " is " << a.revenue() << std::endl;
    std::cout << "Revenue of book " << b.isbn() << " is " << b.revenue() << std::endl;
}
