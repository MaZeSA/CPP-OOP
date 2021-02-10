#pragma once
#include "SetCursor.h"
#include <string>

class Ship
{
public:
	enum class Side
	{
		LEFT,
		RIGHT,
		none
	};
	Ship(Side);
	void Print(int);
	void SetPosition(int, int);
	int GetPosition();
	void Clear(int);
	//void Fire(GameLine*);
	void Damage();
	void PrintLife(int);
	bool HitCheck(int, int);
	Side GetSide();
	void SetEnemy(Ship*);	
	Ship* GetEnemy();

private:
	int	lives = 3; 
	int shipWidth = 3;
	int position_Y = 10;
	Side side = Side::none;
	Ship* enemyShip = nullptr;

	std::string ship_L[3]
	{
		R"(#\)",
		   "#-",
		  "#/"
	};
	std::string ship_R[3]
	{
		  "/#",
		 "-#",
		R"(\#)"
	};

};

