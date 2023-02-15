#pragma once
#include "Screen.h"
#include <Windows.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include <string>


Screen::Screen()
{
    if (this->handlerOutput == NULL)
    {
        this->handlerOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        /*
           this->Width   = 0;
           this->Height  = 0;
           this->Bottom  = 0;
           this->Left    = 0;
           this->Right   = 0;
           this->title.X = 0;
           this->title.Y = 0;
         */
    }
    else
    {
        SetConsoleTextAttribute(handlerOutput, LightRed);
        std::cerr << "[--] Incorrect handler. Abort" << std::endl << std::endl;
        delete(this);
    }
}

Screen::~Screen()
{
    delete(this);
}

int Screen::GetHandlerOutput() {
    return (int)handlerOutput; // Return handler output
}

/*

int Screen::GetTop()
{
    return 0;
}

int Screen::GetBottom()
{

}
*/

int Screen::GetHandlerInput()
{
    return (int)handlerInput; // Return handler input
}

int Screen::GetBuffNumber()
{
    return(int)BuffNumber;  // Return buff descriptor
}

/*
void Screen::SetString(COORD _coord, std::string message, int color)
{

}
*/

void Screen::SetCoord(int x, int y)
{
   coord.X = x,
   coord.Y = y;
}


int Screen::GetWidthWindow() // Return width window value
{
    if (GetConsoleScreenBufferInfo(this->handlerOutput, &ConsoleBuffInfo))
    {
        return (ConsoleBuffInfo.srWindow.Right - ConsoleBuffInfo.srWindow.Left + 1);
    }
}

int Screen::GetHeightWindow() // Return height window value
{
    if (GetConsoleScreenBufferInfo(this->handlerOutput, &ConsoleBuffInfo))
    {
        return (ConsoleBuffInfo.srWindow.Right - ConsoleBuffInfo.srWindow.Top + 1);
    }
}

int Screen::GetLeft() // Return Left ground
{
    if (GetConsoleScreenBufferInfo(this->handlerOutput, &ConsoleBuffInfo))
    {
        return (ConsoleBuffInfo.srWindow.Left + 1);
    }
}

int Screen::GetRight()
{
    if (GetConsoleScreenBufferInfo(this->handlerOutput, &ConsoleBuffInfo))
    {
        return (ConsoleBuffInfo.srWindow.Right + 1);
    }
}

int Screen::GetBottom() // Return bottom ground
{
    if (GetConsoleScreenBufferInfo(this->handlerOutput, &ConsoleBuffInfo))
    {
        return (ConsoleBuffInfo.srWindow.Bottom);
    }
}


int Screen::MoveCursorPosition(COORD _coord, int mode, char symbol, int color = 0)
{
    switch (mode)
    {
    case 0: // Prev position
        SetConsoleCursorPosition(this->handlerOutput, _coord);
        WriteConsoleA(handlerOutput, " ", 1, &BuffNumber, NULL); // Clear
        break;
    case 1:// Next position
        SetConsoleCursorPosition(this->handlerOutput, _coord);
        WriteConsoleA(handlerOutput, &symbol, 1, &BuffNumber, NULL);
        break;
    case 2: // Color Print with Set Coords
        SetConsoleCursorPosition(this->handlerOutput, _coord);
        SetConsoleTextAttribute(this->handlerOutput, color);
        WriteConsoleA(handlerOutput, &symbol, 1, &BuffNumber, NULL);
        break;
    case 3:

       break;
    default:
        SetConsoleTextAttribute(handlerOutput, LightRed);
        std::cerr << "Incorrect argument. Retry again...";
        break;
    }
    return EXIT_SUCCESS;
}

void Screen::GotoXy(COORD _coord, char key, int mode = 0)
{
    MoveCursorPosition(_coord,0, ' ',2);  // Clear prev position into screen
    switch (key)
    {
    case 'w':
        if (coord.Y > 1)
            coord.Y--;
        break;
    case 's':
        if (coord.Y < this->GetBottom())
        {
            coord.Y++;
        }
        break;
    case 'a':
        if (coord.X > this->GetLeft())
        {
            coord.X--;
        }

        break;
    case 'd':
        if (coord.X < this->GetRight() - 2)
        {
            coord.X++;
        }
        break;
    case 'p':
        std::cout << "Pause mode. Press any key for continue";
          _getch();
        break;

    case 'm':
        system("cls");
        break;

    case Enter:
        posX = coord.X;
        posY = coord.Y;
    case Esc:
        system("exit");
    break;

    default:
        break;
    }
      MoveCursorPosition(coord, 2, '+', LightBlue); // Drawing next position
}

/*
void Screen::Entry()
{

}
*/

void Screen::Run(int x , int y)
{
    if (x > 0 || y > 0)
    {
      this->SetCoord(x, y);
        while (true)
        {
            char key = _getch();
            this->GotoXy(this->coord, key, 1);
        }
    }
    else
    {
          std::cerr << "Must be more than 0" << std::endl;
        delete(this);
    }
}