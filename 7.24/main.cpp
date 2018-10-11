#include <iostream>
#include "screen.h"

using namespace std;

int main()
{
    Screen::Position TempWidth = 40;
    Screen::Position TempHeight = 10;
    Screen TempScr(TempWidth, TempHeight, 'x');

    for(Screen::Position i = 0; i != TempWidth/2; i++)
    {
        for(Screen::Position j = 0; j != TempHeight/2; j++)
        {
            TempScr.moveCursor(i, j);
            TempScr.setContent('o');
        }
    }
    printScreen(cout, TempScr);

    return 0;    
}
