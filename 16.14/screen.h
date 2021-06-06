#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <cstdint>
#include <iostream>

template <size_t H, size_t W>
class Screen
{
public:
    Screen() = default;
    ~Screen() = default;

private:
};

template <size_t H, size_t W>
void printScreen(const Screen<H, W>& screen)
{
    for (auto i = 0; i < H; i++)
    {
        for (auto j = 0; j < W; j++)
        {
            std::cout << "@";
        }
        std::cout << std::endl;
    }
}

#endif
