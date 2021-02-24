#include <time.h>
#include <thread>
#include "Fild.h"
#include <iostream>
#include <Windows.h>
#include "Ship.h"
#include "Menu.h"
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
	srand((unsigned int)time(0));

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

}
