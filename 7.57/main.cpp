#include <iostream>
#include "bank_account.h"

using namespace std;

double BankAccount::InterestRate = 0.38*0.01;

int main()
{
    BankAccount TempAccount001;
    BankAccount TempAccount002;

    TempAccount001.setDeposit(100);
    cout << TempAccount001.getAnnualInterest() << endl;
    TempAccount002.setDeposit(100);
    cout << TempAccount002.getAnnualInterest() << endl;

    TempAccount001.setInterestRate(0.32*0.01);
    cout << TempAccount002.getAnnualInterest() << endl;

    return 0; 
}
