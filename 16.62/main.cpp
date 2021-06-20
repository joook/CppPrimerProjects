#include <iostream>
#include <set>
#include <unordered_set>

#include "sales_data.h"

void print(const SalesData& data)
{
    std::cout << "Name: " << data.getName() << std::endl;
    std::cout << "Id: " << data.getId() << std::endl;
    std::cout << "Price: " << data.getPrice() << std::endl;
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    //std::set<SalesData> dataSet;
    //std::multiset<SalesData> dataSet;
    //std::unordered_set<SalesData> dataSet;
    std::unordered_multiset<SalesData> dataSet;

    SalesData a{"Item A", 123456789, 20};
    SalesData b{"Item B", 123456789, 15};
    SalesData c{"Item C", 111111111, 45};

    dataSet.insert(a);
    dataSet.insert(b);
    dataSet.insert(c);

    for (const auto& data : dataSet)
    {
        print(data);
    }

    return 0;
}

