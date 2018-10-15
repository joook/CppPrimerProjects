#ifndef _WINDOW_MANAGER_
#define _WINDOW_MANAGER_

#include <vector>
#include "screen.h"

class WindowManager
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;

    WindowManager(std::vector<Screen> TempV = {}) :
        ScreenGroup(TempV) {}

    void addScreen(Screen TempScr)
    {
        ScreenGroup.push_back(TempScr);
    }
    void clearScreen(ScreenIndex);
    void printScreenGroup(ScreenIndex);

private:
    std::vector<Screen> ScreenGroup;
};

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
#endif

