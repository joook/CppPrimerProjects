#ifndef _SHOPPING_BASKET_H_
#define _SHOPPING_BASKET_H_

#include "book_price.h"
#include <memory>
#include <map>
#include <utility>

class Basket
{
public:
    Basket() = default;

    void addBook(const BookPrice &Book, size_t Amount);
    void removeBook(const BookPrice &Book, size_t Amount);
    double getTotalPrice();
    void printBookList();
private:
    //m_BookList records book price strategy and amount for each book id
    std::map<std::string, std::pair<std::shared_ptr<BookPrice>, size_t>> m_BookList;
};

#endif
