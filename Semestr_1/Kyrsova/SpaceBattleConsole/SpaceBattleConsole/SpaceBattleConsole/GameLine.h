#pragma once
#include "Activity.h"
#include <vector>
using namespace std;

class GameLine
{
public:
	GameLine(int, int);
	vector<Activity*> GetList();
	void UpdateLine();
	void SetChange(bool);
	bool GetChange();
	void SetActivity(int, Activity::TypeActyvity, int x_, Ship* ship);
	void StartTest(int);
	int GetLenght();

private:
	int Y = 0;
	int lenght;
	bool change = true;
	vector<Activity*> listActyvity;
};