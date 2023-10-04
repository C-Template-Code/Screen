#pragma once
#include <Windows.h>
#include "ColorUtils.h"

	class Cursor
	{
	public:
		COORD _coord;
		Cursor(HANDLE);
		~Cursor();
		template<typename Type>
		void SetCursorScreenPositionProperty(Type x, Type y);
		template<typename Type>
		void SetColor(Type);
		int  GetPosX();
		int  GetPosY();
	protected:
		HANDLE output;
	};


