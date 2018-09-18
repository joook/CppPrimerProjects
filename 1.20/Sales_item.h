#include <iostream>

class Sales_item
{
public:
    Sales_item() = default;
    Sales_item(const std::string &s, unsigned u, double r) : 
        bookNo(s), units_sold(u), total_price(r) {}
    Sales_item(std::istream &);
    std::string isbn() const {return bookNo;}
    double revenue() const {return total_price;}
protected:
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double total_price = 0.0;
};

Sales_item::Sales_item(std::istream &is)
{
    double price = 0.0;
    is >> bookNo >> units_sold >> price;
    total_price = price * units_sold;
}
