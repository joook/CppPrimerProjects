#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "book_info.h"

using namespace std;

void readBookInfo(vector<BookInfo> &VecBook, string FileName)
{
    ifstream TempFStream(FileName);
    istringstream TempSStream;
    string TempLine;
    string TempIsbn;
    double TempPrice;

    while(getline(TempFStream, TempLine))
    {
        TempSStream.str(TempLine);
        TempSStream >> TempIsbn >> TempPrice;
        VecBook.emplace_back(TempIsbn, TempPrice);
        TempSStream.clear();
    }
}

void printBookInfo(const vector<BookInfo> &VecBook)
{
    for(auto Itr = VecBook.begin(); Itr != VecBook.end(); Itr++)
    {
        cout << Itr->getIsbn() << " " << Itr->getPrice() << endl;
    }
}

void printBookInfo(vector<BookInfo>::iterator ItrBeg, const vector<BookInfo>::iterator ItrEnd)
{
    for(; ItrBeg != ItrEnd; ItrBeg++)
    {
        cout << ItrBeg->getIsbn() << " " << ItrBeg->getPrice() << endl;
    }
}

bool compareIsbn(const BookInfo &TempBook1, const BookInfo &TempBook2)
{
    return (TempBook1.getIsbn() < TempBook2.getIsbn());
}

bool filterByPrice30to50(const BookInfo &TempBook)
{
    bool ReturnVal = false;
    if(TempBook.getPrice() >= 30 && TempBook.getPrice() <= 50)
    {
        ReturnVal = true;
    }
    else
    {
        ReturnVal = false;
    }
}

int main()
{
    vector<BookInfo> VecBook;
    string FileName;

    cout << "Input the file's name that contains the book info: " << endl;
    cin >> FileName;
    readBookInfo(VecBook, FileName);

    auto ItrEnd = partition(VecBook.begin(), VecBook.end(), filterByPrice30to50);
    cout << "After filtered by price, new book info is: " << endl;
    printBookInfo(VecBook.begin(), ItrEnd);

    return 0;
}
