#ifndef _SCREEN_
#define _SCREEN_

#include <iostream>

class Screen
{
    friend void fillScreen(Screen &TempScr, char TempC);
    /*
    friend void printScreen(Screen &TempScr);
    */
    friend void printScreen(const Screen &TempScr);
public:
    using Position = std::string::size_type;

    Screen() = default;
    Screen(Position TempWidth) :
        Width(TempWidth), Height(TempWidth*1/4), Cursor(0), 
        DisplayContent(std::string(TempWidth*TempWidth*1/4, '*')) {}
    /*
    explicit Screen(Position TempWidth) :
        Width(TempWidth), Height(TempWidth*1/4), Cursor(0), 
        DisplayContent(std::string(TempWidth*TempWidth*1/4, '*')) {}
    */
    Screen(Position TempWidth, Position TempHeight) :
        Width(TempWidth), Height(TempHeight), Cursor(0), 
        DisplayContent(std::string(TempWidth*TempHeight, '*')) {}
    Screen(Position TempWidth, Position TempHeight, char TempC) :
        Width(TempWidth), Height(TempHeight), Cursor(0), 
        DisplayContent(std::string(TempWidth*TempHeight, TempC)) {}

private:
    Position Width;
    Position Height;
    Position Cursor;
    std::string DisplayContent;
};

void fillScreen(Screen &TempScr, char TempC);
/*
void printScreen(Screen &TempScr);
*/
void printScreen(const Screen &TempScr);
#endif

