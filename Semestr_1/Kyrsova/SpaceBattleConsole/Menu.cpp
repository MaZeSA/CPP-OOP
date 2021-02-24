#include "Menu.h"
#include <iostream>

void Menu::PrintLogo()
{
	MazesaPrint();
}

void Menu::MazesaPrint()
{
	FG_COLORS color = FG_COLORS::FG_BLACK;

	for (int i = 0; i < 7; i++)
	{
		int y = ((20 / 2) - (7 / 2)) + i;
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
		//std::cout << endl;;

	}
}

