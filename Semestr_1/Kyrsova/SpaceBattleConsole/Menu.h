#pragma once
#include "Fild.h"
#include <iostream>
class Menu : public Fild
{
public:

	class ListMenu
	{
	public:

		ListMenu(int y_, int x_)
		{
			this->x = x_;
			this->y = y_;
		}
		void PrintMenu()
		{
			for (int i = 0; i < 3; i++)
			{
				setCursorPosition(this->x, this->y + i);
				std::cout << menu[i];
			}
			++(*this); 
			--(*this);
		}
		void SelectMenu(FG_COLORS color, char c_)
		{
			setCursorPosition(this->x - 1, this->y + this->selectItem);
			setTextColour(color);
			cout << c_ << menu[this->selectItem];
		}
		int GetSelect()
		{
			return this->selectItem;
		}
		int* operator++()
		{
			if (this->selectItem == 2) return &selectItem;
			SelectMenu(defColor, ' ');
			this->selectItem++;
			SelectMenu(selColor, '*');
			return &selectItem;
		}
		int* operator--()
		{
			if (this->selectItem == 0) return &selectItem;
			SelectMenu(defColor, ' ');
			this->selectItem--;
			SelectMenu(selColor, '*');
			return  &selectItem;
		}

	private:
		string menu[3] = {" Start Game"," Settings"," Exit" };
		FG_COLORS defColor = FG_COLORS::FG_LIGHTGRAY;
		FG_COLORS selColor = FG_COLORS::FG_YELLOW;
		int selectItem = 0;
		int x = 0, y = 0;
	};

	Menu(int x_, int y_, int retreat_) : Fild(x_, y_, retreat_) {};
	void PrintLogo();
	void MazesaPrint();
	void Present();
	void SpaseBatlePrint(int y_);
	void RunBullet();
	void PrintMenu();

private:
	
	std::string MaZeSa4[7] =
	{
		"II         II                IIIIIIIIII              IIIIIII             ",
		"IIII     IIII      III              II     IIIII    II     II     III    ",
		"II  II  II II   II    II           II    II     II  II          II   II  ",
		"II   IIII  II  II      II        II     IIIIIIIII     IIIII    II     II ",
		"II    II   II  II      II      II       II                 II  II     II ",
		"II         II   II    III    II          II     II  II     II   II   III ",
		"II         II    IIIII  II  IIIIIIIIII    IIIIIII    IIIIIII     IIII  II"
	}; 
	std::string MaZeSa[5] =
	{
		" ii     ii     i     iiiiii iiiiii  iiii     i    ",
		" iii   iii    i i        i  i      i        i i   ",	
		" ii i i ii   i   i     i    iiiiii  iiii   i   i  ",	
		" ii  i  ii  iiiiiii   i     i           i iiiiiii ",	
		" ii     ii ii     ii iiiiii iiiiii iiiii ii     ii"
	};
	std::string SpaseBatle[10] =
	{
		"     IIIII IIIII    I      IIIII IIIIII    IIIII      I   IIIIIIII II     IIIIII  ",
		"   II      II   I  I I    II     II        II   I    I I     II    II     II      ",
		"    IIII   IIIII  I   I    IIII  IIIIII    IIIII    I   I    II    II     IIIIII  ",
		"       II  II    IIIIIII      II II        II   I  IIIIIII   II    II     II      ",
		"   IIIII   II   II     II IIIII  IIIIII    IIIII  II     II  II    IIIIII IIIIII  "
	};

};

