#include <iostream>
#include "screen.h"
#include "window_manager.h"

using namespace std;

int main()
{
    Screen::Position TempWidth = 40;
    Screen::Position TempHeight = 10;
    Screen TempScr01(TempWidth, TempHeight, 'x');
    Screen TempScr02(TempWidth, TempHeight, '8');
    Screen TempScr03(TempWidth, TempHeight, '?');

    for(Screen::Position i = 0; i != TempWidth/2; i++)
    {
        for(Screen::Position j = 0; j != TempHeight/2; j++)
        {
            TempScr01.moveCursor(i, j);
            TempScr01.setContent('o');
        }
    }

    for(Screen::Position i = 0; i != TempWidth; i++)
    {
        for(Screen::Position j = 0; j != TempHeight; j++)
        {
            if(j == i)
            {
                TempScr02.moveCursor(i, j);
                TempScr02.setContent('1');
            }
        }
    }

    printScreen(cout, TempScr01);
    cout << endl;
    printScreen(cout, TempScr02);
    cout << endl;
    printScreen(cout, TempScr03);
    cout << endl;

    WindowManager TempWin;
    TempWin.addScreen(TempScr01);
    TempWin.addScreen(TempScr02);
    TempWin.addScreen(TempScr03);
    WindowManager::ScreenIndex TempI01 = 0;
    WindowManager::ScreenIndex TempI02 = 1;
    WindowManager::ScreenIndex TempI03 = 2;
    TempWin.clearScreen(TempI02);
    TempWin.printScreenGroup(TempI01);
    cout << endl;
    TempWin.printScreenGroup(TempI02);
    cout << endl;
    TempWin.printScreenGroup(TempI03);
    cout << endl;

    return 0;
}
