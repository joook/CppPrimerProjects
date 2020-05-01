#ifndef _SHOPPING_BASKET_H_
#define _SHOPPING_BASKET_H_

#include "book_price.h"
#include <memory>
#include <map>

class Basket
{
public:
    Basket() = default;

    void addBook(const std::shared_ptr<BookPrice> &Book, size_t Amount);
    void removeBook(const std::shared_ptr<BookPrice> &Book, size_t Amount);
    double getTotalPrice();
    void printBookList();
private:
    std::map<std::shared_ptr<BookPrice>, size_t> m_BookList;
};

#endif
