#pragma once
#include "Fild.h"
class Menu : public Fild
{
public:
	Menu(int x_, int y_, int retreat_) : Fild(x_, y_, retreat_) {};
	void PrintLogo();
	void MazesaPrint();
private:
	
	std::string MaZeSa[7] =
	{
		"II         II                IIIIIIIIII              IIIIIII             ",
		"IIII     IIII      III              II     IIIII    II     II     III    ",
		"II  II  II II   II    II           II    II     II  II          II   II  ",
		"II   IIII  II  II      II        II     IIIIIIIII     IIIII    II     II ",
		"II    II   II  II      II      II       II                 II  II     II ",
		"II         II   II    III    II          II     II  II     II   II   III ",
		"II         II    IIIII  II  IIIIIIIIII    IIIIIII    IIIIIII     IIII  II"
	};
};

