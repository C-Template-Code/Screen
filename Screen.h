#pragma once
#include <Windows.h>
#include "ColorUtils.h"
#include "Cursor.h"
#include "IRunnable.h"
class Screen : public IRunnable
{
public:
	int Width;
	int Height;
	const char* name;
	void SetConsoleScreenWidthProperty();
	int  GetConsoleScreenWidthProperty();
	int  GetConsoleScreenHeightProperty();
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

