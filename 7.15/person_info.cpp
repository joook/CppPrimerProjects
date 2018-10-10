#include "person_info.h"

std::istream &readPersonInfo(std::istream &InputStream, PersonInfo &PrsnInfoIn)
{
    std::string TempName, TempAddress;
    std::cout << "Input person name: ";
    getline(InputStream, TempName);
    std::cout << "Input person address: ";
    getline(InputStream, TempAddress);
    PrsnInfoIn.setName(TempName);
    PrsnInfoIn.setAddress(TempAddress);
    return InputStream;
}

std::ostream &printPersonInfo(std::ostream &OutputStream, const PersonInfo &PrsnInfoOut)
{
    OutputStream << "Name: " << PrsnInfoOut.getName()  << std::endl;
    OutputStream << "Address: " << PrsnInfoOut.getAddress() << std::endl;
    return OutputStream;
}

PersonInfo::PersonInfo(std::istream &InputStream)
{
    readPersonInfo(InputStream, *this);
}
