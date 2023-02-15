#pragma once
#include <Windows.h>
#include <iostream>
#include <string.h>
enum KeyboardKey
{
    Up = 72, Down = 80, Right = 77, Left = 75, Enter = 13, Space = 32, Esc = 27
};

enum Colors
{
    Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
    LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

class Screen
{

private:
    //DWORD BuffNumber = NULL;
    CONSOLE_SCREEN_BUFFER_INFO ConsoleBuffInfo;
    HANDLE handlerOutput;
    HANDLE handlerInput = NULL;

public:

    int Width;
    int Height;
    int Left;
    int Right;
    int Bottom;
    int posX;
    int posY;

    DWORD BuffNumber = NULL;
    COORD dwSizer;
    COORD coord;
    COORD title;
    Screen();
    ~Screen();
    int GetHandlerOutput();
    int GetHandlerInput();
    int GetBuffNumber();
    void SetCoord(int, int);
   // void Entry();
    void SetString(COORD,std::string, int);
    
    int GetWidthWindow();
    int GetHeightWindow();
    int GetLeft();
    int GetRight();
    int GetBottom();
    int MoveCursorPosition(COORD, int, char, int);
    void GotoXy(COORD, char, int);
    void Run(int,int);
};