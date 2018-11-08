#include <iostream>
#include <deque>
#include <stack>
#include <stdexcept>

using namespace std;

class CalculateItem
{
public:
    void clear()
    {
        Number = 2018;
        Operator.clear();
    }
public:
    int Number = 2018;
    string Operator;
};

int calculate(const string &Expression);
void pushNumToStack(stack<CalculateItem> &ExpnStack, int TempNumInt);

int main()
{
    string Expression;
    int Result;

    cout << "Input a expression" << endl;
    getline(cin, Expression);
    try
    {
        Result = calculate(Expression);
        cout << "Result: " << Result << endl;
    }
    catch(invalid_argument Err)
    {
        cerr << Err.what() << endl;
    }

    return 0;
}

int calculate(const string &Expression)
{
/*
Expression example:"9 - (12 - (5+3))"
*/
    deque<CalculateItem> TempDeque;
    stack<CalculateItem> ExpnStack(TempDeque);
    string TempNumStr;
    int TempNumInt;
    CalculateItem TempItem;

    for(auto Itr = Expression.begin(); Itr != Expression.end(); Itr++)
    {
        TempItem.clear();
        if(isdigit(*Itr))
        {
            TempNumStr += *Itr;
            if(Itr+1 == Expression.end() || !isdigit(*(Itr+1)))
            {
                TempNumInt = stoi(TempNumStr);
                pushNumToStack(ExpnStack, TempNumInt);
            }
            else
            {
            }
        }
        else
        {
            TempNumStr.clear();
        }

        if(*Itr == '(')
        {
            if(ExpnStack.empty() || ExpnStack.top().Operator == "+" || ExpnStack.top().Operator == "-")
            {
                TempItem.Operator = "(";
                ExpnStack.push(TempItem);
            }
            else
            {
                throw invalid_argument("Input invalid, please check.");
            }
        }
        else if(*Itr == ')')
        {
            if(ExpnStack.empty() || ExpnStack.top().Number == 2018)
            {
                throw invalid_argument("Input invalid, please check.");
            }
            else
            {
                int Result = ExpnStack.top().Number;
                ExpnStack.pop();
                if(ExpnStack.empty() || ExpnStack.top().Operator != "(")
                {
                    throw invalid_argument("Input invalid, please check.");
                }
                else
                {
                    ExpnStack.pop();
                    pushNumToStack(ExpnStack, Result);
                }
            }
        }
        else
        {
        }

        if(*Itr == '+')
        {
            if(ExpnStack.empty() || ExpnStack.top().Number == 2018)
            {
                throw invalid_argument("Input invalid, please check.");
            }
            else
            {
                TempItem.Operator = "+";
                ExpnStack.push(TempItem);
            }
        }
        else if(*Itr == '-')
        {
            if(ExpnStack.empty() || ExpnStack.top().Number == 2018)
            {
                throw invalid_argument("Input invalid, please check.");
            }
            else
            {
                TempItem.Operator = "-";
                ExpnStack.push(TempItem);
            }
        }
        else
        {
        }
    }

    return ExpnStack.top().Number;
}

void pushNumToStack(stack<CalculateItem> &ExpnStack, int TempNumInt)
{
    if(ExpnStack.empty() || ExpnStack.top().Operator == "(" || ExpnStack.top().Operator == "+" || ExpnStack.top().Operator == "-")
    {
    }
    else
    {
        throw invalid_argument("Input invalid, please check.");
    }

    /*
    this will cause segmentation fault:
    while(ExpnStack.top().Operator == "+" || ExpnStack.top().Operator == "-")
    {
        if(ExpnStack.top().Operator == "+")
        {
            ExpnStack.pop();
            TempNumInt = ExpnStack.top().Number + TempNumInt;
            ExpnStack.pop();
        }
        else if(ExpnStack.top().Operator == "-")
        {
            ExpnStack.pop();
            TempNumInt = ExpnStack.top().Number - TempNumInt;
            ExpnStack.pop();
        }
        else
        {
        }
    }
    */

    while(!ExpnStack.empty() && (ExpnStack.top().Operator == "+" || ExpnStack.top().Operator == "-"))
    {
        if(ExpnStack.top().Operator == "+")
        {
            ExpnStack.pop();
            TempNumInt = ExpnStack.top().Number + TempNumInt;
            ExpnStack.pop();
        }
        else if(ExpnStack.top().Operator == "-")
        {
            ExpnStack.pop();
            TempNumInt = ExpnStack.top().Number - TempNumInt;
            ExpnStack.pop();
        }
        else
        {
        }
    }

    CalculateItem TempItem;
    TempItem.Number = TempNumInt;
    ExpnStack.push(TempItem);
}
