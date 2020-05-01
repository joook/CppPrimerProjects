#include <iostream>
#include "shopping_basket.h"

using namespace std;

void Basket::addBook(const BookPrice &Book, size_t Amount)
{
    auto Ptr = Book.clone();
    auto Id = Ptr->getBookId();
    if(m_BookList.find(Id) == m_BookList.end())
    {
        m_BookList.insert({Id, make_pair(Ptr, Amount)});
    }
    else
    {
        (m_BookList[Id]).second += Amount;
    }
}

void Basket::removeBook(const BookPrice &Book, size_t Amount)
{
    auto Ptr = Book.clone();
    auto Id = Ptr->getBookId();
    if(m_BookList.find(Id) == m_BookList.end())
    {
    }
    else
    {
        if((m_BookList[Id]).second > Amount)
        {
            (m_BookList[Id]).second -= Amount;
        }
        else
        {
            m_BookList.erase(Id);
        }
    }
}

double Basket::getTotalPrice()
{
    double TotalPrice;
    for(auto Itr = m_BookList.begin(); Itr != m_BookList.end(); Itr++)
    {
        TotalPrice += Itr->second.first->getTotalPrice(Itr->second.second);
    }
    return TotalPrice;
}

void Basket::printBookList()
{
    for(auto Itr = m_BookList.begin(); Itr != m_BookList.end(); Itr++)
    {
        cout << "[Book-" << Itr->first << "], ";
        cout << "Unit Price: " << Itr->second.first->getUnitPrice() << ", ";
        cout << "Amount: " << Itr->second.second << endl;
    }
}


