#include <iostream>
#include "book_price.h"

using namespace std;

void printTotalPrice(const BookPrice &Book, size_t Number)
{
    cout << "Total price for " << Number << " book-";
    cout << Book.getBookId() << "] is: ";
    cout << Book.getTotalPrice(Number) << " (yuan)." << endl;
}

int main()
{
    BookPrice Book1("1234", 20.0);
    printTotalPrice(Book1, 3);
    printTotalPrice(Book1, 12);

    BulkPrice Book2("2234", 20.0, 10, 0.2);
    printTotalPrice(Book2, 3);
    printTotalPrice(Book2, 12);

    return 0;
}

