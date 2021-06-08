#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <cstdint>
#include <iostream>

template <size_t Width, size_t Height>
class Screen;

template <size_t Width, size_t Height>
std::ostream& operator<< (std::ostream& stm, const Screen<Width, Height>& screen);

template <size_t Width, size_t Height>
std::istream& operator>> (std::istream& stm, Screen<Width, Height>& screen);

template <size_t Width, size_t Height>
class Screen
{
friend std::ostream& operator<< <Width, Height> (std::ostream& stm, const Screen<Width, Height>& screen);
friend std::istream& operator>> <Width, Height> (std::istream& stm, Screen<Width, Height>& screen);

public:
    Screen()
        : m_CursorPos(0)
        , m_Content(Width * Height, m_DefaultPixel)
    {
    }

    Screen(char c)
        : m_CursorPos(0)
        , m_Content(Width * Height, c)
    {
    }

    ~Screen() = default;
    Screen(const Screen& screen) = default;
    Screen(Screen&& screen) = default;
    Screen& operator= (const Screen& screen) = default;
    Screen& operator= (Screen&& screen) = default;

    size_t getCursorPos() const
    {
        return m_CursorPos;
    }

    void moveCursorPos(size_t pos)
    {
        if (isPosValid(pos))
        {
            m_CursorPos = pos;
        }
        else
        {
            throw std::runtime_error("Position out of range.");
        }
    }

    void moveCursorPos(size_t x, size_t y)
    {
        if (isPosValid(x + y * Width))
        {
            m_CursorPos = x + y * Width;
        }
        else
        {
            throw std::runtime_error("Position out of range.");
        }
    }

    char getCursorContent() const
    {
        if (isPosValid(m_CursorPos))
        {
            return m_Content.at(m_CursorPos);
        }
        else
        {
            throw std::runtime_error("Position out of range.");
        }
    }

    void setCursorContent(char c)
    {
        if (isPosValid(m_CursorPos))
        {
            m_Content.at(m_CursorPos) = c;
        }
        else
        {
            throw std::runtime_error("Position out of range.");
        }
    }

    void reset()
    {
        m_CursorPos = 0;
        m_Content = std::string(Width * Height, m_DefaultPixel);
    }

    void display() const;

private:
    bool isPosValid(size_t pos) const
    {
        if (pos < m_Content.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    size_t m_CursorPos;
    std::string m_Content;

    static char m_DefaultPixel;
};

template <size_t Width, size_t Height>
char Screen<Width, Height>::m_DefaultPixel = '*';

template <size_t Width, size_t Height>
void Screen<Width, Height>::display() const
{
    for (size_t j = 0; j != Height; j++)
    {
        for (size_t i = 0; i != Width; i++)
        {
            std::cout << m_Content.at(j * Width + i);
        }
        std::cout << std::endl;
    }
}

template <size_t Width, size_t Height>
std::ostream& operator<< (std::ostream& stm, const Screen<Width, Height>& screen)
{
    for (size_t j = 0; j != Height; j++)
    {
        for (size_t i = 0; i != Width; i++)
        {
            stm << screen.m_Content.at(j * Width + i);
        }
        stm << std::endl;
    }
}

template <size_t Width, size_t Height>
std::istream& operator>> (std::istream& stm, Screen<Width, Height>& screen)
{
    stm >> screen.m_Content;
    if (stm)
    {
    }
    else
    {
        screen.reset();
    }

    return stm;
}

#endif

