#ifndef _BOOK_PRICE_H_
#define _BOOK_PRICE_H_

#include <string>

class BookPrice
{
public:
    BookPrice() = default;
    BookPrice(const std::string &Id, double Price);
    virtual ~BookPrice() = default;
public:
    std::string getBookId() const { return m_BookId; }
    double getUnitPrice() const { return m_Price; }
    virtual double getTotalPrice(size_t Number) const;
private:
    std::string m_BookId;
    double m_Price;
};

class DiscountPriceBase : public BookPrice
{
public:
    DiscountPriceBase() = default;
    DiscountPriceBase(const std::string &Id, double Price, size_t DiscountAmount, double Discount);
    virtual ~DiscountPriceBase() = default;
public:
    double getDiscount() const { return m_Discount; }
    size_t getDiscountAmount() const { return m_DiscountAmount; }
    virtual double getTotalPrice(size_t Number) const override = 0;
private:
    size_t m_DiscountAmount;
    double m_Discount;
};

class BulkPrice : public DiscountPriceBase
{
public:
    BulkPrice() = default;
    BulkPrice(const std::string &Id, double Price, size_t DiscountAmount, double Discount);
    virtual ~BulkPrice() = default;
public:
    virtual double getTotalPrice(size_t Number) const override;
};

class LimitedDiscountPrice : public DiscountPriceBase
{
public:
    LimitedDiscountPrice() = default;
    LimitedDiscountPrice(const std::string &Id, double Price, size_t DiscountAmount, double Discount);
    virtual ~LimitedDiscountPrice() = default;
public:
    virtual double getTotalPrice(size_t Number) const override;
};

#endif
