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

    shared_ptr<BookPrice> Book1Ptr = make_shared<BookPrice>(Book1);
    shared_ptr<BookPrice> Book2Ptr = make_shared<BulkPrice>(Book2);
    shared_ptr<LimitedDiscountPrice> Book3Ptr = make_shared<LimitedDiscountPrice>(Book3);

    Basket1.addBook(Book1Ptr, 2);
    Basket1.addBook(Book2Ptr, 15);
    Basket1.addBook(Book3Ptr, 2);
    Basket1.addBook(Book3Ptr, 18);
    Basket1.removeBook(Book2Ptr, 5);

    Basket1.printBookList();
    cout << "Total price for books in Basket1 is: ";
    cout << Basket1.getTotalPrice() << endl;

    return 0;
}

