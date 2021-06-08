#include <iostream>
#include <sstream>

#include "screen.h"

int main()
{
    const size_t w = 40;
    const size_t h = 10;
    Screen<w, h> screen1('x');
    Screen<w, h> screen2('o');
    Screen<8, 3> screen3;

    for (size_t i = 0; i != w/2; i++)
    {
        for (size_t j = 0; j != h/2; j++)
        {
            screen1.moveCursorPos(i, j);
            screen1.setCursorContent('@');
        }
    }

    for (size_t i = 0; i != w; i++)
    {
        for (size_t j = 0; j != h; j++)
        {
            if ((j == i)  || (j + 2 == i)  || (j + 2 == w - i - 1) || (j == w - i - 1))
            {
                screen2.moveCursorPos(i, j);
                screen2.setCursorContent('=');
            }
            else
            {
                // do nothing
            }
        }
    }

    std::stringstream stm;
    stm << "########!!!!!!!!########";
    stm >> screen3;

    screen1.display();
    std::cout << std::endl;

    std::cout << screen2;
    std::cout << std::endl;

    std::cout << screen3;
    std::cout << std::endl;

    return 0;
}
