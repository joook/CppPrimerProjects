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
    /*
    Be careful with the const_iterator here.
    */
    for(vector<BookInfo>::const_iterator Itr = VecBook.begin(); Itr != VecBook.end(); Itr++)
    {
        cout << Itr->getIsbn() << " " << Itr->getPrice() << endl;
    }
}

/*
bool compareIsbn(const BookInfo &TempBook1, const BookInfo &TempBook2)
{
    return (TempBook1.getIsbn() < TempBook2.getIsbn());
}
*/

int main()
{
    vector<BookInfo> VecBook;
    string FileName;

    cout << "Input the file's name that contains the book info: " << endl;
    cin >> FileName;
    readBookInfo(VecBook, FileName);

    sort(VecBook.begin(), VecBook.end(), 
[](const BookInfo &TempBook1, const BookInfo &TempBook2)
{return (TempBook1.getIsbn() < TempBook2.getIsbn());});
    cout << "After sort by dictionary order, new book info is: " << endl;
    printBookInfo(VecBook);

    return 0;
}
