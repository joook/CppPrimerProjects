#ifndef _SALES_DATA_H_
#define _SALES_DATA_H_

#include <cstdint>
#include <string>

class SalesData
{
friend bool operator<(const SalesData& left, const SalesData& right);

public:
    explicit SalesData(const std::string& name, std::uint16_t id, std::uint16_t price);
    SalesData() = delete;
    ~SalesData() = default;

private:
    std::string m_Name;
    std::uint16_t m_Id;
    std::uint16_t m_Price;
};

bool operator<(const SalesData& left, const SalesData& right);

#endif
