#include <iostream>
#include "shopping_basket.h"

using namespace std;

void Basket::addBook(const std::shared_ptr<BookPrice> &Book, size_t Amount)
{
    if(m_BookList.find(Book) == m_BookList.end())
    {
        m_BookList.insert({Book, Amount});
    }
    else
    {
        m_BookList[Book] += Amount;
    }
}

void Basket::removeBook(const std::shared_ptr<BookPrice> &Book, size_t Amount)
{
    if(m_BookList.find(Book) == m_BookList.end())
    {
    }
    else
    {
        if(m_BookList[Book] > Amount)
        {
            m_BookList[Book] -= Amount;
        }
        else
        {
            m_BookList.erase(Book);
        }
    }
}

double Basket::getTotalPrice()
{
    double TotalPrice;
    for(auto Itr = m_BookList.begin(); Itr != m_BookList.end(); Itr++)
    {
        TotalPrice += Itr->first->getTotalPrice(Itr->second);
    }
    return TotalPrice;
}

void Basket::printBookList()
{
    for(auto Itr = m_BookList.begin(); Itr != m_BookList.end(); Itr++)
    {
        cout << "[Book-" << Itr->first->getBookId() << "], ";
        cout << "Unit Price: " << Itr->first->getUnitPrice() << ", ";
        cout << "Amount: " << Itr->second << endl;
    }
}


