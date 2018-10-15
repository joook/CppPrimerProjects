#include <iostream>
#include "screen.h"

using namespace std;

int main()
{
    Screen::Position TempWidth = 40;
    Screen::Position TempHeight = 10;
    Screen TempScr(TempWidth, TempHeight, 'b');

    printScreen(TempScr);
    cout << "--------------------------" << endl;
    fillScreen(TempScr, 'H');
    printScreen(TempScr);
    cout << "--------------------------" << endl;
    printScreen(TempWidth);
    cout << "--------------------------" << endl;
    printScreen(20);

    return 0;
}
