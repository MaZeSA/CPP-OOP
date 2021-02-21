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
	void PrintShield();
	void PrintAmunition();
	void AddAmunition();
	bool TakeAmunition();
	void ReturnAmunition();
	void SetShipColor(FG_COLORS color_);
	void SetUp(bool);
	bool GetUp();
private:
	int	lives = 4; 
	int shipWidth = 3;
	int position_Y = 10;
	int fildLenght = 0;
	bool shield = false;
	Side side = Side::none;
	Ship* enemyShip = nullptr;
	int maxAmunition = 30, countAmunition = 3, maxUsingAmunition = 10,usingAmunition = 0;
	FG_COLORS ShipColor = FG_COLORS::FG_RED;
	bool up_ship = false;

	std::string ship_L[3]
	{
		R"(#\)",
		   "#-",
		  "#/"
	};
	std::string ship_L_UP[3]
	{
		R"(#=)",
		   "##",
		  "#="
	};
	std::string ship_R[3]
	{
		  "/#",
		 "-#",
		R"(\#)"
	};	
	
	std::string ship_R_UP[3]
	{
		  "=#",
		 "##",
		R"(=#)"
	};

};

