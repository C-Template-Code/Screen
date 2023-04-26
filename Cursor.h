#pragma once
#include <Windows.h>
#include "ColorUtils.h"
class Cursor
{
  public:
	  COORD _coord;
	  Cursor();
	  ~Cursor();
	  template<typename Type>
	  void SetCursorScreenPosition(Type, Type);
	  template<typename Type>
	  void SetColor(Type);
	  int  GetPosX();
	  int  GetPosY();
protected:
	  HANDLE output;
};

