#include <time.h>
#include <thread>
#include "Fild.h"
#include <iostream>
#include <Windows.h>
#include "Ship.h"
#include "Menu.h"
#include <stdio.h>
#include <conio.h>
//
//void setCursorPositio(int x, int y)
//{
//	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	std::cout.flush();
//	COORD coord = { (SHORT)x, (SHORT)y };
//	SetConsoleCursorPosition(hOut, coord);
//}

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

	/*Fild fild(100, 20, 3);
	fild.PreparationFild();*/

	setCursorPosition(0, 21);

	std::cout << "First update";

	//fild.UpdateFild();


	setCursorPosition(0, 22);
	std::cout << "Test end run\n"
		<< "Player 1 >> 'W', 'S', fire >'Spase'\n"
		<< "Player 2 >> 'num 8', 'num 2', fire >'num 0'\n";

	//fild.Play();
	return 0;
}
