#include "window_manager.h"

/*
inline func should be put into .h,
not in .cpp,
otherwise it doesn't work.
*/

/*
inline void WindowManager::clearScreen(ScreenIndex TempI)
{
    Screen &TempScr = ScreenGroup[TempI];
    TempScr.DisplayContent = std::string(TempScr.Width*TempScr.Height, ' ');
}

inline void WindowManager::printScreenGroup(ScreenIndex TempI)
{
    Screen &TempScr = ScreenGroup[TempI];
    printScreen(std::cout, TempScr);
}
*/
