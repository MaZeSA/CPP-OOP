#pragma once
#include "GameLine.h"
#include "Ship.h"
#include <ctime>
using namespace std;


class Fild
{
public:
	
	Fild(int, int, int );
	void PreparationFild();
	void StartTest();
	vector<GameLine*> GetList();
	void UpdateFild();
	void Play();
	void ShipFire(Ship* ship_);
	void Fire(Ship*, int, int, int);
	void GenerateActivity();
	int GetMinGen();
	int GetMaxGen();
private:

	Ship ship_L = Ship::Side::LEFT;
	Ship ship_R = Ship::Side::RIGHT;

	int X = 0, Y = 0, retreat =0;
	vector<GameLine*> listLine;
};

