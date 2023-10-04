#include "Screen.h"
#include "Cursor.h"
#include "ColorUtils.h"
#include <iostream>
#include "IRunnable.h"
#include <Windows.h>
#include <vector>

Screen::Screen() : output(GetStdHandle(STD_OUTPUT_HANDLE)), input(GetStdHandle(STD_INPUT_HANDLE)), 
                   Width(0), Height(0), cursor(new Cursor(GetStdHandle(STD_OUTPUT_HANDLE))){}

Screen::~Screen()
{
    //std::cout << "All object was removed!" << std::endl;
    delete (cursor);
    delete(this);
}

/**
* Set property value for Width
*/
void Screen::SetConsoleScreenWidthProperty()
{
    if (GetConsoleScreenBufferInfo(this->output, &buffer))
    {
        Width = buffer.srWindow.Right - buffer.srWindow.Left + 1;
    }
}

/**
* Return property value for Width
* Возвращает значение свойства ширины
*/
int Screen::GetConsoleScreenWidthProperty()
{
    return Width;
}

/**
* Return property value for Height
* Возвращает значения свойства высоты
*/
int Screen::GetConsoleScreenHeightProperty()
{
    return Height;
}

/*
* Set new coord pointer for cursor position
* Устанавливает новую систему координат для курсора
*/
template<typename Type>
void Screen::SetCursorScreenPositionProperty(Type x ,Type y)
{
    if (this->cursor != NULL)
    {
        this->cursor->SetCursorScreenPositionProperty(x, y);
    }
    else {
        std::cerr << "The SetCursorPositionProperty method recieve incorrect type" 
                  << std::endl;
    }
}
/*
* Set height property value
* Устанавливает значение высоты
*/
void Screen::SetConsoleScreenHeightProperty()
{
    if (GetConsoleScreenBufferInfo(this->output, &buffer))
    {
        Height=buffer.srWindow.Bottom + 1;
    }
}

/*
* Set new name for current window
* Устанавливает новое имя для окна
*/
void Screen::SetConsoleNameProperty(const char* newName)
{
    if (newName != NULL)
    {
        name = newName;
        SetConsoleTitleA(name);
    }
}

/*
* Set new color theme for console
*/
void Screen::SetConsoleTextColor(ColorUtils color)
{
    if (this->output != NULL)
    {
        SetConsoleTextAttribute(this->output, static_cast<WORD>(color));
    }
    else {
        std::cerr << "The SetConsoleTextColor nethod  recieve incorrect type"
            << std::endl;
    }
}

/*
* Test Method by method
* Тестовый метод для прогонки функций
*/

void Screen::IRun()
{
    this->SetConsoleNameProperty("Example");
    this->SetConsoleScreenHeightProperty();
    this->SetConsoleScreenWidthProperty();
    this->SetConsoleTextColor(ColorUtils::LightBlue);
    this->SetCursorScreenPositionProperty(10, 10);
    std::cout << "Hello" << std::endl;
    system("pause");
}


 