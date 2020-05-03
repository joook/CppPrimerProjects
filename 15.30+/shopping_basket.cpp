#include <iostream>
#include "shopping_basket.h"

using namespace std;

void Basket::addBook(const BookPrice &Book, size_t Amount)
{
    auto Ptr = Book.clone();
    auto Id = Ptr->getBookId();
    if(m_BookPriceList.find(Id) == m_BookPriceList.end())
    {
        m_BookPriceList.insert({Id, Ptr});
        m_BookAmountList.insert({Id, Amount});
    }
    else
    {
        m_BookAmountList[Id] += Amount;
    }
}

void Basket::removeBook(const BookPrice &Book, size_t Amount)
{
    auto Ptr = Book.clone();
    auto Id = Ptr->getBookId();
    if(m_BookPriceList.find(Id) == m_BookPriceList.end())
    {
    }
    else
    {
        if(m_BookAmountList[Id] > Amount)
        {
            m_BookAmountList[Id] -= Amount;
        }
        else
        {
            m_BookPriceList.erase(Id);
            m_BookAmountList.erase(Id);
        }
    }
}

double Basket::getTotalPrice()
{
    double TotalPrice;
    for(auto Itr = m_BookPriceList.begin(); Itr != m_BookPriceList.end(); Itr++)
    {
        TotalPrice += Itr->second->getTotalPrice(m_BookAmountList[Itr->first]);
    }
    return TotalPrice;
}

void Basket::printBookList()
{
    for(auto Itr = m_BookPriceList.begin(); Itr != m_BookPriceList.end(); Itr++)
    {
        cout << "[Book-" << Itr->first << "], ";
        cout << "Unit Price: " << Itr->second->getUnitPrice() << ", ";
        cout << "Amount: " << m_BookAmountList[Itr->first] << endl;
    }
}

