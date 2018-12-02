class BookInfo
{
public:
    BookInfo(const std::string TempI, const std::string TempT, const std::string TempA, const double TempP) : Isbn(TempI), Title(TempT), Author(TempA), Price(TempP) {}

    BookInfo(const std::string TempI, const double TempP) : Isbn(TempI), Price(TempP) {}

    /*
    These getXXX functions without a const [this] pointer in the end may not work, see Cpp Primer page 231 & 232 to get more info.
    */
    /*
    std::string getIsbn()
    {
        return Isbn;
    }

    double getPrice()
    {
        return Price;
    }
    */
    std::string getIsbn() const
    {
        return Isbn;
    }

    double getPrice() const
    {
        return Price;
    }

private:
    std::string Isbn;
    std::string Title;
    std::string Author;
    double Price = 0.0;
};
