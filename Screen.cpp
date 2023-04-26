#include "Screen.h"
#include "ColorUtils.h"
#include <iostream>
#include "IRunnable.h"
#include <Windows.h>

Screen::Screen() : output(GetStdHandle(STD_OUTPUT_HANDLE)), input(GetStdHandle(STD_INPUT_HANDLE)), 
                   Width(0), Height(0), cursor(new Cursor()){}
Screen::~Screen()
{
    std::cout << "All object was removed!" << std::endl;
    delete (cursor);
    delete(this);
}

void Screen::SetConsoleScreenWidthProperty()
{
    if (GetConsoleScreenBufferInfo(this->output, &buffer))
    {
        Width = buffer.srWindow.Right - buffer.srWindow.Left + 1;
    }
}

int Screen::GetConsoleScreenWidthProperty()
{
    return Width;
}

int Screen::GetConsoleScreenHeightProperty()
{
    return Height;
}

void Screen::SetConsoleScreenHeightProperty()
{
    if (GetConsoleScreenBufferInfo(this->output, &buffer))
    {
        Height=buffer.srWindow.Bottom + 1;
    }
}

void Screen::SetConsoleNameProperty(const char* newName)
{
    if (newName != NULL)
    {
        name = newName;
        SetConsoleTitleA(name);
    }
}

void Screen::SetConsoleTextColor(ColorUtils color)
{
    if (this->output != NULL)
    {
        SetConsoleTextAttribute(this->output, static_cast<WORD>(color));
    }
}

void Screen::IRun()
{
    this->SetConsoleNameProperty("Example");
    this->SetConsoleScreenHeightProperty();
    this->SetConsoleScreenWidthProperty();
    this->SetConsoleTextColor(ColorUtils::LightBlue);
    system("pause");
}

 