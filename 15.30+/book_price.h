#ifndef _BOOK_PRICE_H_
#define _BOOK_PRICE_H_

#include <string>
#include <memory>

class BookPrice
{
public:
    BookPrice(const std::string &Id, double Price);
public:
    std::string getBookId() const { return m_BookId; }
    double getUnitPrice() const { return m_Price; }
    virtual double getTotalPrice(size_t Number) const;
    virtual std::shared_ptr<BookPrice> clone() const;
private:
    std::string m_BookId;
    double m_Price;
};

class DiscountPriceBase : public BookPrice
{
public:
    DiscountPriceBase(const std::string &Id, double Price, size_t DiscountAmount, double Discount);
public:
    double getDiscount() const { return m_Discount; }
    size_t getDiscountAmount() const { return m_DiscountAmount; }
    virtual double getTotalPrice(size_t Number) const override = 0;
    virtual std::shared_ptr<BookPrice> clone() const override = 0;
private:
    size_t m_DiscountAmount;
    double m_Discount;
};

class BulkPrice : public DiscountPriceBase
{
public:
    BulkPrice(const std::string &Id, double Price, size_t DiscountAmount, double Discount);
public:
    virtual double getTotalPrice(size_t Number) const override;
    virtual std::shared_ptr<BookPrice> clone() const override;
};

class LimitedDiscountPrice : public DiscountPriceBase
{
public:
    LimitedDiscountPrice(const std::string &Id, double Price, size_t DiscountAmount, double Discount);
public:
    virtual double getTotalPrice(size_t Number) const override;
    virtual std::shared_ptr<BookPrice> clone() const override;
};

#endif
