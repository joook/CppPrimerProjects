#include "book_price.h"
#include "shopping_basket.h"
#include <memory>
#include <iostream>

using namespace std;

int main()
{
    Basket Basket1;
    BookPrice Book1("9871234", 20.0);
    BulkPrice Book2("9762345", 20.0, 10, 0.2);
    LimitedDiscountPrice Book3("9653456", 20.0, 10, 0.2);

    Basket1.addBook(Book1, 2);
    Basket1.addBook(Book2, 15);
    Basket1.addBook(Book3, 2);
    Basket1.addBook(Book3, 18);
    Basket1.removeBook(Book2, 5);

    Basket1.printBookList();
    cout << "Total price for books in Basket1 is: ";
    cout << Basket1.getTotalPrice() << endl;

    return 0;
}

