#pragma once
#include "SetCursor.h"
#include <string>
#include "ConsoleColor.h"

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
	void Print();
	void SetPosition(int, int);
	int GetPosition();
	int GetLenght();
	void Clear();
	void Damage();
	void SetHP(int);
	void PrintLife();
	bool HitCheck(int);
	Side GetSide();
	void SetEnemy(Ship*);	
	Ship* GetEnemy();
	void SetShield(bool);
	bool GetShield();
	void PrintAmunition();
	void AddAmunition();
	bool TakeAmunition();
	void ReturnAmunition();
	void SetShipColor(FG_COLORS color_);

private:
	int	lives = 3; 
	int shipWidth = 3;
	int position_Y = 10;
	int fildLenght = 0;
	bool shield = false;
	Side side = Side::none;
	Ship* enemyShip = nullptr;
	int countAmunition = 3;
	int usingAmunition = 0;
	FG_COLORS ShipColor = FG_COLORS::FG_RED;

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

