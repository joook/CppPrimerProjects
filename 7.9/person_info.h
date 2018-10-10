#include <iostream>

class PersonInfo
{
public:
    std::string getInfo(PersonInfo &) const;
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
