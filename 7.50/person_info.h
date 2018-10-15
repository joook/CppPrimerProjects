#include <iostream>

class PersonInfo
{
friend std::istream &readPersonInfo(std::istream &, PersonInfo &);
friend std::ostream &printPersonInfo(std::ostream &, const PersonInfo &);

public:
    PersonInfo() = default;
    explicit PersonInfo(const std::string &InitName) :
        Name(InitName), Address(InitName+"'s home") {}
    PersonInfo(const std::string &InitName, const std::string &InitAddr) :
        Name(InitName), Address(InitAddr) {}
    explicit PersonInfo(std::istream &InputStream)
    {
        std::string TempName, TempAddress;
        std::cout << "Input person name: ";
        getline(InputStream, TempName);
        std::cout << "Input person address: ";
        getline(InputStream, TempAddress);
        this->setName(TempName);
        this->setAddress(TempAddress);
    }

    std::string getName() const
    {
        return Name;
    }
    void setName(std::string NewName)
    {
        Name = NewName;
    }
    std::string getAddress() const
    {
        return Address;
    }
    void setAddress(std::string NewAddress)
    {
        Address = NewAddress;
    }

private:
    std::string Name;
    std::string Address;

};

std::istream &readPersonInfo(std::istream &, PersonInfo &);
std::ostream &printPersonInfo(std::ostream &, const PersonInfo &);
