#include <iostream>
#include "screen.h"

void fillScreen(Screen &TempScr, char TempC)
{
    TempScr.DisplayContent = std::string(TempScr.Width*TempScr.Height, TempC);
}

/*
This will not work:
void printScreen(Screen &TempScr)
*/
void printScreen(const Screen &TempScr)
{
    for(Screen::Position j = 0; j != TempScr.Height; j++)
    {
        for(Screen::Position i = 0; i != TempScr.Width; i++)
        {
            std::cout << TempScr.DisplayContent[j*TempScr.Width+i];
        }
        std::cout << std::endl;
    }
}
