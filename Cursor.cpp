#include "Cursor.h"
#include "ColorUtils.h"
#include <iostream>
#include <Windows.h>
template void Cursor::SetCursorScreenPositionProperty<int>(int x, int y);

Cursor::Cursor(HANDLE descriptor) : output(descriptor)
{
    
}

Cursor::~Cursor()
{
}


template<typename Type>
void Cursor::SetCursorScreenPositionProperty(Type x , Type y)
{
	if (std::is_same_v<Type, int> == true)
	{
		this->_coord.X = static_cast<SHORT>(x);
		this->_coord.Y = static_cast<SHORT>(y);
		SetConsoleCursorPosition(this->output, _coord);
    }
    else
    {
        std::cerr << "The method SetCursorScreenPosition recieve Incorrect type" 
                  << std::endl 
                  << "Abort!";
        return; 
    }
}

template<typename Type>
void Cursor::SetColor(Type color)
{
    if (std::is_same_v<Type, int>)
    {
        SetConsoleTextAttribute(this->output, static_cast<WORD>(color));
    }
    else if (std::is_enum_v<Type>)
    {
        using underlying_type = std::underlying_type_t<Type>;
        SetConsoleTextAttribute(this->output, static_cast<WORD>(static_cast<underlying_type>(color)));
    }
    else {
        std::cerr << "The method SetColor recieve Incorrect type" << std::endl
                  << "Abort!";
        return;
    }
}

int Cursor::GetPosX()
{
	return this->_coord.X;
}

int Cursor::GetPosY()
{
	return this->_coord.Y;
}
