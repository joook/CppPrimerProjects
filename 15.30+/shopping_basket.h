#ifndef _SHOPPING_BASKET_H_
#define _SHOPPING_BASKET_H_

#include "book_price.h"
#include <memory>
#include <map>

class Basket
{
public:
    Basket() = default;

    void addBook(const BookPrice &Book, size_t Amount);
    void removeBook(const BookPrice &Book, size_t Amount);
    double getTotalPrice();
    void printBookList();
private:
    //records book price strategy and amount for each book id
    std::map<std::string, std::shared_ptr<BookPrice>> m_BookPriceList;
    std::map<std::string, size_t> m_BookAmountList;
};

#endif
