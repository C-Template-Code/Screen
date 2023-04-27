#pragma once
#include <Windows.h>
#include "ColorUtils.h"
#include "Cursor.h"
#include "IRunnable.h"
#include <vector>

class Screen : public IRunnable
{
	public:
		int Width;
		int Height;
		const char* name;
		int  GetConsoleScreenWidthProperty();
		int  GetConsoleScreenHeightProperty();
		void SetConsoleScreenWidthProperty();
		template<typename Type>
		void SetCursorScreenPositionProperty(Type, Type);
		void SetConsoleScreenHeightProperty();
		void SetConsoleNameProperty(const char*);
		void SetConsoleTextColor(ColorUtils);
		virtual void IRun() override;
		Screen();
		~Screen();

	private:
		Cursor* cursor;
	protected:
		CONSOLE_SCREEN_BUFFER_INFO buffer;
		HANDLE output;
		HANDLE input;
};


