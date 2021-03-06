#include "book_price.h"

using namespace std;

BookPrice::BookPrice(const string &Id, double Price)
: m_BookId(Id)
, m_Price(Price)
{
}

double BookPrice::getTotalPrice(size_t Number) const
{
    return Number*getUnitPrice();
}

DiscountPriceBase::DiscountPriceBase(const string &Id, double Price, size_t DiscountAmount, double Discount)
: BookPrice(Id, Price)
, m_DiscountAmount(DiscountAmount)
, m_Discount(Discount)
{
}

BulkPrice::BulkPrice(const string &Id, double Price, size_t DiscountAmount, double Discount)
: DiscountPriceBase(Id, Price, DiscountAmount, Discount)
{
}

double BulkPrice::getTotalPrice(size_t Number) const
{
    double TotalPrice;
    if(Number >= getDiscountAmount())
    {
        TotalPrice = Number*getUnitPrice()*(1-getDiscount());
    }
    else
    {
        TotalPrice = Number*getUnitPrice();
    }
    return TotalPrice;
}

LimitedDiscountPrice::LimitedDiscountPrice(const string &Id, double Price, size_t DiscountAmount, double Discount)
: DiscountPriceBase(Id, Price, DiscountAmount, Discount)
{
}

double LimitedDiscountPrice::getTotalPrice(size_t Number) const
{
    double TotalPrice;
    if(Number <= getDiscountAmount())
    {
        TotalPrice = Number*getUnitPrice()*(1-getDiscount());
    }
    else
    {
        TotalPrice = getDiscountAmount()*getUnitPrice()*(1-getDiscount())+(Number-getDiscountAmount())*getUnitPrice();
    }
    return TotalPrice;
}

