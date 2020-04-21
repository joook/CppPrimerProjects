#include "book_price.h"

using namespace std;

void printTotalPrice(const BookPrice &Book, size_t Number);

int main()
{
    BookPrice Book1("1234", 20.0);
    printTotalPrice(Book1, 3);
    printTotalPrice(Book1, 12);

    BulkPrice Book2("2234", 20.0, 10, 0.2);
    printTotalPrice(Book2, 3);
    printTotalPrice(Book2, 12);

    LimitedDiscountPrice Book3("3234", 20.0, 10, 0.2);
    printTotalPrice(Book3, 3);
    printTotalPrice(Book3, 12);

    return 0;
}

