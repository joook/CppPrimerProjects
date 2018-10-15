#include "person_info.h"

std::istream &readPersonInfo(std::istream &InputStream, PersonInfo &PrsnInfoIn)
{
    std::cout << "Input person name: ";
    getline(InputStream, PrsnInfoIn.Name);
    std::cout << "Input person address: ";
    getline(InputStream, PrsnInfoIn.Address);
    return InputStream;
}

std::ostream &printPersonInfo(std::ostream &OutputStream, const PersonInfo &PrsnInfoOut)
{
    OutputStream << "Name: " << PrsnInfoOut.Name  << std::endl;
    OutputStream << "Address: " << PrsnInfoOut.Address << std::endl;
    return OutputStream;
}

