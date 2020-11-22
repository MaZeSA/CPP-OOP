#pragma once
#include <string>
#include "Menu.h"
using std::string;
class MyGame
{
public:
	
	void RunGame(int);
	void CreateGameFild();
	void CreateBombs(int c);
	void ShowTimer(); 
	void WriteInfoData(int lvl);
	void ShowMackFild();
	void RecOpen(int y, int x);
	void Ups_Boomb();
	void Victory();
	void CursorMove();
	int ItsBoomb(int x, int y);
	void BackColorSet(int y, int x);
	void ShowAllBombs();
	void CloseRaund();
	string GetActionSum(int i);
	void ShowBoombCount(int action);
	void ShowPause();
	
private:


	int GetFaktual_X();
	int GetFaktual_Y();
	
};
