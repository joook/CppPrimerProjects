#ifndef _SALES_DATA_H_
#define _SALES_DATA_H_

#include <cstdint>
#include <string>
#include <functional>

class SalesData
{
public:
    explicit SalesData(const std::string& name, std::uint64_t id, std::uint16_t price)
        : m_Name{name}
        , m_Id{id}
        , m_Price{price}
    {
    }

    SalesData() = delete;
    ~SalesData() = default;

    std::string getName() const { return m_Name; }
    std::uint64_t getId() const { return m_Id; }
    std::uint16_t getPrice() const { return m_Price; }

private:
    std::string m_Name;
    std::uint64_t m_Id;
    std::uint16_t m_Price;
};

bool operator< (const SalesData& left, const SalesData& right)
{
    return (left.getId() < right.getId());
}

bool operator== (const SalesData& left, const SalesData& right)
{
    return (left.getId() == right.getId());
}

namespace std
{

template<>
class hash<SalesData>
{
public:
    typedef size_t result_type;
    typedef SalesData argument_type;

    size_t operator() (const SalesData& data) const
    {
        return std::hash<std::uint64_t>() (data.getId());
    }
};

}

#endif
