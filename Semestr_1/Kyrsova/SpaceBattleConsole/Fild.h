#pragma once
#include "GameLine.h"
#include "Ship.h"
#include <ctime>
#include "Settings.h"
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
	void CleanFild(int y_start_, int y_end_, int x_start, int x_end_);
	int GetResultGame();
	void RE()
	{
		ship_L = *(new Ship(Ship::Side::LEFT, &liv));
	    ship_R = *(new Ship( Ship::Side::RIGHT, &liv));

		listLine.clear();
		for (int i = 0; i < Y; i++)
		{
			this->listLine.push_back(new GameLine(retreat + i, X));
		}
	}
private:

	Ship ship_L = *(new Ship(Ship::Side::LEFT, &liv));
	Ship ship_R = *(new Ship(Ship::Side::RIGHT, &liv));
	bool liv = true;

	int X = 0, Y = 0, retreat =0;
	vector<GameLine*> listLine;
};

