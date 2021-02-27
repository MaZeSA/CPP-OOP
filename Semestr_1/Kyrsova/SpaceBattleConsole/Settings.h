#pragma once
#include <string>
#include <vector>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include "ConsoleColor.h"
#include "SetCursor.h"
using namespace std;
class Settings
{
public:
	
	struct  Keys
	{
	public:
		Keys(int* key_, std::string name_)
		{
			key = key_;
			name = name_;
		}
		int* key = nullptr;
		std::string name = "";
		int indexY = 0;
	};

	static Settings* setting;
	static Settings* GetSetting();

	Settings();
	void Show(int);
	void Menu();
	void PrintItem(FG_COLORS color_, Settings::Keys* key_);
	int Get_Up_key(int player_); 
	int Get_Down_key(int player_); 
	int Get_Shot_key(int player_);
	int ret();

private:

	std::vector<Keys> listKey;

	int p1_key_Up = 87,
		p1_key_Down = 83,
		p1_key_Shot = 32;

	int p2_key_Up = 104,
		p2_key_Down = 98,
		p2_key_Shot = 96;



};

