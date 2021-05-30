#include "sales_data.h"

SalesData::SalesData(const std::string& name, std::uint16_t id, std::uint16_t price)
    : m_Name{name}
    , m_Id{id}
    , m_Price{price}
{
}

bool operator<(const SalesData& left, const SalesData& right)
{
    if (left.m_Id < right.m_Id)
    {
        return true;
    }
    else
    {
        return false;
    }
}

