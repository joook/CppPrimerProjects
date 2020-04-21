#include <iostream>
#include "book_price.h"

using namespace std;

void printTotalPrice(const BookPrice &Book, size_t Number)
{
    cout << "Total price for " << Number << " book-";
    cout << Book.getBookId() << "] is: ";
    cout << Book.getTotalPrice(Number) << " (yuan)." << endl;
}

BookPrice::BookPrice(const string &Id, double Price)
: m_BookId(Id)
, m_Price(Price)
{
}

double BookPrice::getTotalPrice(size_t Number) const
{
    return Number*getUnitPrice();
}

BulkPrice::BulkPrice(const string &Id, double Price, size_t DiscountAmount, double Discount)
: BookPrice(Id, Price)
, m_DiscountAmount(DiscountAmount)
, m_Discount(Discount)
{
}

double BulkPrice::getTotalPrice(size_t Number) const
{
    double TotalPrice;
    if(Number >= m_DiscountAmount)
    {
        TotalPrice = Number*getUnitPrice()*(1-getDiscount());
    }
    else
    {
        TotalPrice = Number*getUnitPrice();
    }
    return TotalPrice;
}

LimitedDiscountPrice::LimitedDiscountPrice(const string &Id, double Price, size_t NoDiscountAmount, double Discount)
: BookPrice(Id, Price)
, m_NoDiscountAmount(NoDiscountAmount)
, m_Discount(Discount)
{
}

double LimitedDiscountPrice::getTotalPrice(size_t Number) const
{
    double TotalPrice;
    if(Number <= m_NoDiscountAmount)
    {
        TotalPrice = Number*getUnitPrice()*(1-getDiscount());
    }
    else
    {
        TotalPrice = m_NoDiscountAmount*getUnitPrice()*(1-getDiscount())+(Number-m_NoDiscountAmount)*getUnitPrice();
    }
    return TotalPrice;
}

