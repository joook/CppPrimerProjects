#include <iostream>

class Screen
{
friend std::ostream &printScreen(std::ostream &, const Screen &);

public:
    typedef std::string::size_type Position;

    Screen() = default;
    Screen(Position InitWidth, Position InitHeight) :
        Cursor(0), Width(InitWidth), Height(InitHeight), 
        DisplayContent(InitWidth*InitHeight, '*') {};
    Screen(Position InitWidth, Position InitHeight, char Pix) :
        Cursor(0), Width(InitWidth), Height(InitHeight), 
        DisplayContent(InitWidth*InitHeight, Pix) {};

    Position getCursor() const
    {
        return Cursor;
    }

    void moveCursor(Position TempPos)
    {
        Cursor = TempPos;
    }

    void moveCursor(Position X, Position Y)
    {
        Cursor = X+Y*Width;
    }

    char getContent() const
    {
        return DisplayContent[Cursor];
    }

    void setContent(char Charactor)
    {
        DisplayContent[Cursor] = Charactor;
    }

    void setContent(Position X, Position Y, char Charactor)
    {
        Cursor = X+Y*Width;
        DisplayContent[Cursor] = Charactor;
    }

private:
    Position Cursor = 0;
    Position Height = 0;
    Position Width = 0;
    std::string DisplayContent = "";
};

std::ostream &printScreen(std::ostream &, const Screen &);
