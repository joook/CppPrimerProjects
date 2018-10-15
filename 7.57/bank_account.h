#ifndef _BANK_ACCOUNT_
#define _BANK_ACCOUNT_

#include <iostream>

class BankAccount
{
public:
    static double getInterestRate()
    {
        return InterestRate;
    }

    static void setInterestRate(double TempI)
    {
        InterestRate = TempI;
    }

    int getAccountID()
    {
        return AccountID;
    }

    void setAccountID(int TempID)
    {
        AccountID = TempID;
    }

    float getDeposit()
    {
        return Deposit;
    }

    void setDeposit(double TempD)
    {
        Deposit = TempD;
    }

    double getAnnualInterest()
    {
        return InterestRate*Deposit;
    }


private:
    static double InterestRate;
    int AccountID;
    float Deposit;
};
/*
double BankAccount::InterestRate = 0.35*0.01;
*/
#endif

