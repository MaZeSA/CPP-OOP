#include <time.h>
#include <thread>
#include "Fild.h"
#include <iostream>
#include <Windows.h>
#include "Ship.h"
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

  //  std::cout << "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
	
	Fild fild(100, 20, 3);

	setCursorPosition(0, 21);

	std::cout << "First update";

	fild.UpdateFild();
	
	//setCursorPosition(0, 21);
	//system("pause");
	//fild.StartTest();

	setCursorPosition(0, 22);
	std::cout << "Test end run\n"
		<< "Player 1 >> 'W', 'S', fire >'Spase'\n"
		<< "Player 2 >> 'num 8', 'num 2', fire >'num 0'\n";

	fild.Play();

	//ship1.SetPosition(10, 100);
	//ship2.SetPosition(10, 100);
	//
	//int y = 10;
	//while (true)

	//{//	setCursorPositio(0, 21);

	//	this_thread::sleep_for(std::chrono::milliseconds(40));	

	//	fild.UpdateFild();
	//


	//	if (GetAsyncKeyState(VK_UP) == -32767)
	//	{fild.StartTest();
	//		y--;
	///*		ship1.SetPosition(y, 100);
	//		ship2.SetPosition(y, 100);*/
	//	}
	//	if (GetAsyncKeyState(VK_DOWN) == -32767)
	//	{
	//		y++;
	//		//ship1.SetPosition(y, 100);
	//		//ship2.SetPosition(y, 100);
	//	}	
	//	if (GetAsyncKeyState(VK_SPACE) == -32767)
	//	{

	//	}

	//}
}
