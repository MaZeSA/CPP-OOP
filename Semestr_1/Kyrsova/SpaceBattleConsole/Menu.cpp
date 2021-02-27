#include "Menu.h"
#include <iostream>
#include <thread>

Menu::ListMenu menu(10, 52);

void Menu::PrintLogo()
{
	this_thread::sleep_for(std::chrono::milliseconds(400));
	setCursorPosition(30, 19);
	system("pause");
	
	CleanFild(18, 20, 2, 98);
	MazesaPrint();	

	this_thread::sleep_for(std::chrono::seconds(1)); 
	CleanFild(1, 20, 2, 98);
	Present();

	this_thread::sleep_for(std::chrono::seconds(1));
	CleanFild(7, 15, 20, 70);
	SpaseBatlePrint((20 / 2) - (7 / 2));
	RunBullet();

	CleanFild(3, 15, 10, 90);
	SpaseBatlePrint(3);

	menu.PrintMenu(this);
}

void Menu::MazesaPrint()
{
	FG_COLORS color = FG_COLORS::FG_BLACK;

	for (int i = 0; i < 5; i++)
	{
		int y = ((20 / 2) - (5 / 2)) + i;
		int x = (100 / 2) - this->MaZeSa[i].size() / 2;
		setCursorPosition(x, y);

		for (int t = 0; t < this->MaZeSa[i].size(); t++)
		{
			if (MaZeSa[i][t] != ' ')
				color = FG_COLORS::FG_GRAY;
			else
				color = FG_COLORS::FG_BLACK;
			
			SetColor(color, color);
			std::cout << MaZeSa[i][t];
		}
	}
	SetColor(FG_COLORS::FG_WHITE, FG_COLORS::FG_BLACK);
}
void Menu::Present()
{
	int y = ((20 / 2) - 1);
	int x = (100 / 2) - 7 / 2;
	setCursorPosition(x, y);
	std::cout << "PRESENT";
}
void Menu::SpaseBatlePrint(int y_)
{
	FG_COLORS color = FG_COLORS::FG_BLACK;

	for (int i = 0; i < 7; i++)
	{
		int y = y_ + i;
		int x = (100 / 2) - this->SpaseBatle[i].size() / 2;
		setCursorPosition(x, y);

		for (int t = 0; t < this->SpaseBatle[i].size(); t++)
		{
			if (SpaseBatle[i][t] != ' ')
				color = FG_COLORS::FG_CYAN;
			else
				color = FG_COLORS::FG_BLACK;

			SetColor(color, color);
			std::cout << SpaseBatle[i][t];
		}
	}
	SetColor(FG_COLORS::FG_WHITE, FG_COLORS::FG_BLACK);
	this_thread::sleep_for(std::chrono::milliseconds(500));
	setCursorPosition(81, y_ + 5);
	cout << "CONSOLE_";
}
void Menu::RunBullet()
{
	int end = 100;
	Fire(nullptr, -96, 96, 16); 
	Fire(nullptr, 96, 3, 4); 
	Fire(nullptr, 96, 3, 6);
	Fire(nullptr, -96, 96, 8); 
	Fire(nullptr, 96, 3, 9);
	while (--end)
	{
		this_thread::sleep_for(std::chrono::milliseconds(20));
		UpdateFild();
	}
}

void Menu::PrintMenu()
{

	setCursorPosition(45, 12);



	while (true)
	{

	}
}

void Menu::StartGame()
{
	CleanFild(3, 15, 10, 90);
	PreparationFild();
	Play();

	if (this->GetResultGame() > 0)
		if (this->GetResultGame() == 1)
			cout << "Red is lost;";
		else
			cout << "Blue is lost";
	RE();

	CleanFild(0, 34, 1, 100);
	SpaseBatlePrint(3);
	menu.PrintMenu(this);
}

void Menu::Settings()
{
	CleanFild(10, 15,50, 90);
	Settings::setting->Show(100);

	CleanFild(0, 34, 0, 100);
	SpaseBatlePrint(3);
	menu.PrintMenu(this);
}


