#include "screen.h"

std::ostream &printScreen(std::ostream &OutputStream, const Screen &Scr)
{
    for(Screen::Position j = 0; j != Scr.Height; j++)
    {
        for(Screen::Position i = 0; i != Scr.Width; i++)
        {
            OutputStream << Scr.DisplayContent[j*Scr.Width+i];
        }
        OutputStream << std::endl;
    }

    return OutputStream;
}
