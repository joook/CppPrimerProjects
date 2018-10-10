#include <iostream>

class PersonInfo
{
public:
    PersonInfo() = default;
    PersonInfo(const std::string &InitName) :
        Name(InitName), Address(InitName+"'s home") {}
    PersonInfo(const std::string &InitName, const std::string &InitAddr) :
        Name(InitName), Address(InitAddr) {}
    PersonInfo(std::istream &);

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
