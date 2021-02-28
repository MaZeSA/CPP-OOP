#include <time.h>
#include <Windows.h>
#include "Menu.h"

int main()
{
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
	
	srand((unsigned int)time(0));
	Settings::GetSetting();

	Menu menu(100, 20, 3);
	menu.PrintLogo();

	return 0;
}
