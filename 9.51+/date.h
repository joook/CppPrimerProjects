#include <iostream>
#include <vector>

class YearMonthDay
{
public:
    YearMonthDay() = default;
    YearMonthDay(std::string );

    unsigned getYear()
    {
        return Year;
    }
    unsigned getMonth()
    {
        return Month;
    }
    unsigned getDay()
    {
        return Day;
    }
private:
    unsigned Year = 1900;
    unsigned Month = 1;
    unsigned Day = 1;
};

bool checkYearRange(unsigned YearNum)
{
    bool ReturnVal = false;
    if(YearNum >= 1900 && YearNum <= 2100)
    {
        ReturnVal = true;
    }
    else
    {
        ReturnVal = false;
    }
    return ReturnVal;
}

bool checkMonthRange(unsigned MonthNum)
{
    bool ReturnVal = false;
    if(MonthNum >= 1 && MonthNum <= 12)
    {
        ReturnVal = true;
    }
    else
    {
        ReturnVal = false;
    }
    return ReturnVal;
}

bool checkDayRange(unsigned DayNum)
{
    bool ReturnVal = false;
    if(DayNum >= 1 && DayNum <= 31)
    {
        ReturnVal = true;
    }
    else
    {
        ReturnVal = false;
    }
    return ReturnVal;
}

YearMonthDay::YearMonthDay(std::string InputDate)
{
/*
[Effective data]
Year: 1900-2100;
Month: 1-12;
    01-12;
    Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec;
    January, February, March, April, May, June, July, August, September, October, November, December;
Day: 1-31;
    01-31;
    1st, 2nd, 3rd, 4-20th, 21st, 22nd, 23rd, 24-30th, 31st;
Separator: .-,/ ;
Sequence: YYYY.MM.DD;
    YYYY-MM-DD;
    MM DD,YYYY;
    MM/DD/YYYY;
    MM DD YYYY;
*/
    std::vector<std::string> Num = {"", "", ""};
    std::vector<std::string> Sep = {"", ""};
    auto NumItr = Num.begin();
    auto SepItr = Sep.begin();
    std::string YearStr;
    std::string MonthStr;
    std::string DayStr;
    unsigned YearNum;
    unsigned MonthNum;
    unsigned DayNum;

    for(char TempChar : InputDate)
    {
        if(NumItr == Num.end())
        {
            throw std::out_of_range("Input too many numbers, quit.");
        }
        else
        {
        }

        if(TempChar != '.' && TempChar !='-' && TempChar != ',' && TempChar != '/' && TempChar != ' ')
        {
            *NumItr = *NumItr+TempChar;
        }
        else
        {
            NumItr++;
            if(SepItr == Sep.end())
            {
            }
            else
            {
                *SepItr = TempChar;
                SepItr++;
            }
        }
    }

    if(Sep.front() == "." || Sep.front() == "-")
    {
        YearStr = Num[0];
        MonthStr = Num[1];
        DayStr = Num[2];
    }
    else
    {
        YearStr = Num[2];
        MonthStr = Num[0];
        DayStr = Num[1];
    }

    try
    {
        YearNum = stoi(YearStr);
        MonthNum = stoi(MonthStr);
        DayNum = stoi(DayStr);
    }
    catch(std::invalid_argument Err)
    {
    }
    catch(std::out_of_range Err)
    {
    }

    if(checkYearRange(YearNum) &&
        checkMonthRange(MonthNum) &&
        checkDayRange(DayNum))
    {
        Year = YearNum;
        Month = MonthNum;
        Day = DayNum;
    }
    else
    {
        throw std::out_of_range("Input number out of range, quit.");
    }
}

