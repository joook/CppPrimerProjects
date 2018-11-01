#include <iostream>
#include <vector>
#include <map>

class YearMonthDate
{
public:
    YearMonthDate() = default;
    YearMonthDate(std::string );

    unsigned getYear()
    {
        return Year;
    }
    unsigned getMonth()
    {
        return Month;
    }
    unsigned getDate()
    {
        return Date;
    }
private:
    unsigned Year = 1900;
    unsigned Month = 1;
    unsigned Date = 1;
};

bool checkYearRange(const unsigned YearNum)
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

bool checkMonthRange(const unsigned MonthNum)
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

bool checkDateRange(const unsigned DateNum)
{
    bool ReturnVal = false;
    if(DateNum >= 1 && DateNum <= 31)
    {
        ReturnVal = true;
    }
    else
    {
        ReturnVal = false;
    }
    return ReturnVal;
}

unsigned convertMonthToNum(const std::string MonthStr)
{
    unsigned MonthNum = 0;
    std::map<std::string, unsigned> MonthDict = 
    {
        {"Jan", 1},
        {"January", 1},
        {"Feb", 2},
        {"February", 2},
        {"Mar", 3},
        {"March", 3},
        {"Apr", 4},
        {"April", 4},
        {"May", 5},
        {"Jun", 6},
        {"June", 6},
        {"Jul", 7},
        {"July", 7},
        {"Aug", 8},
        {"August", 8},
        {"Sep", 9},
        {"September", 9},
        {"Oct", 10},
        {"October", 10},
        {"Nov", 11},
        {"November", 11},
        {"Dec", 12},
        {"December", 12}
    };
    try
    {
        MonthNum = stoi(MonthStr);
    }
    catch(std::invalid_argument Err)
    {
        auto Itr = MonthDict.find(MonthStr);
        if(Itr != MonthDict.end())
        {
            MonthNum = Itr->second;
        }
        else
        {
            std::cerr << "Invalid month input, please check." << std::endl;
        }
    }
    /*
    catch(std::out_of_range Err)
    {
        cerr << "Invalid month input, please check." << endl;
    }
    */

    return MonthNum;
}

unsigned convertDateToNum(const std::string DateStr)
{
    unsigned DateNum = 0;
    std::map<std::string, unsigned> DateDict = 
    {
        {"1st", 1},
        {"2nd", 2},
        {"3rd", 3},
        {"4th", 4},
        {"5th", 5},
        {"6th", 6},
        {"7th", 7},
        {"8th", 8},
        {"9th", 9},
        {"10th", 10},
        {"11th", 11},
        {"12th", 12},
        {"13th", 13},
        {"14th", 14},
        {"15th", 15},
        {"16th", 16},
        {"17th", 17},
        {"18th", 18},
        {"19th", 19},
        {"20th", 20},
        {"21st", 21},
        {"22nd", 22},
        {"23rd", 23},
        {"24th", 24},
        {"25th", 25},
        {"26th", 26},
        {"27th", 27},
        {"28th", 28},
        {"29th", 29},
        {"30th", 30},
        {"31st", 31}
    };
    try
    {
        DateNum = stoi(DateStr);
    }
    catch(std::invalid_argument Err)
    {
        auto Itr = DateDict.find(DateStr);
        if(Itr != DateDict.end())
        {
            DateNum = Itr->second;
        }
        else
        {
            std::cerr << "Invalid date input, please check." << std::endl;
        }
    }
    /*
    catch(std::out_of_range Err)
    {
        cerr << "Invalid date input, please check." << endl;
    }
    */

    return DateNum;
}

YearMonthDate::YearMonthDate(const std::string InputDate)
{
/*
[Effective data]
Year: 1900-2100;
Month: 1-12;
    01-12;
    Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec;
    January, February, March, April, May, June, July, August, September, October, November, December;
Date: 1-31;
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
    std::string DateStr;
    unsigned YearNum;
    unsigned MonthNum;
    unsigned DateNum;

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
        DateStr = Num[2];
    }
    else
    {
        YearStr = Num[2];
        MonthStr = Num[0];
        DateStr = Num[1];
    }

    try
    {
        YearNum = stoi(YearStr);
        MonthNum = convertMonthToNum(MonthStr);
        DateNum = convertDateToNum(DateStr);
    }
    catch(std::invalid_argument Err)
    {
    }
    catch(std::out_of_range Err)
    {
    }

    if(checkYearRange(YearNum) &&
        checkMonthRange(MonthNum) &&
        checkDateRange(DateNum))
    {
        Year = YearNum;
        Month = MonthNum;
        Date = DateNum;
    }
    else
    {
        throw std::out_of_range("Input number out of range, quit.");
    }
}

