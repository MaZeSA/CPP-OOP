#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <thread>
#include "ConsoleColor.h"
#include "ConsoleSize.h"
#include "CursorPosition.h"
#include <vector>
#include "FileReader.h"
#include "PlaySound.h"
using namespace std;
struct dataPxel
{
	int TextColour = -1;
	int BackgroundColour = -1;
	string textPrint = "   ";
};
static int Lvls[5][3]
{
	{12,12,10},
	{19,19,40},
	{19,32,83},
	{24,35,140},
	{30,35,200},
};
int time_ = 0;
extern short window_X;
extern short window_Y;
extern string LSMenu[];
string flag = " X ";
string none = " ? ";
bool stopTh = true;
int boombFound = 0;
int LVL;
int CountOpenItems = 0;
int BodyMas = 3;
int** Field;
int** UserActions;
int CursorY = 0, CursorX = 0;
int FildPositionY = 0, FildPositionX = 0;
int FSizeX = 0, FSizeY = 0;
bool pause = false;

std::string LostLogo[] =
{
	{"                                                         "},
	{"##    ##  ####   ##  ##     ##      ####    ####  #######"},
	{" ##  ##  ##  ##  ##  ##     ##     ##  ##  ##       ##   "},
	{"  ####   ##  ##  ##  ##     ##     ##  ##   ###     ##   "},
	{"   ##    ##  ##  ##  ##     ##     ##  ##     ##    ##   "},
	{"  ##      ####    ####      #####   ###    ####     ##   "},
	{"                                                         "}
};
std::string VinLogo[] =
{   {"                                                          "},
	{"##   ##  ####   ##  ##     ##     ##     ##  ##  ####   ##"},
	{" ## ##  ##  ##  ##  ##      ##   ####   ##   ##  ## ##  ##"},
	{"  ###   ##  ##  ##  ##       ## ##  ## ##    ##  ##  ## ##"},
	{"  ##    ##  ##  ##  ##        ###    ###     ##  ##   ####"},
	{" ##      ####    ####          #      #      ##  ##    ###"},
	{"                                                          "},
};
//extern short window_X = 0, window_Y = 0;


void Timer_()
{
	while (stopTh)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		if (pause == false)	time_++;
	}
}
thread RunTimer()
{
	time_ = 0;
	thread thr(Timer_);
	thr.detach();
	return thr;
}

void MyGame::RunGame(int lvl)
{
	LVL = lvl;
	FSizeX = Lvls[(int)lvl][0];
	FSizeY = Lvls[(int)lvl][1];
	
	int bombs = Lvls[(int)lvl][2];;
	boombFound = 0;

	FildPositionX = (window_X / 2) - (FSizeX / 2 * BodyMas);
	FildPositionY = 3;
	
	CountOpenItems = (FSizeX * FSizeY) - ((FSizeX-2)  * (FSizeY-2))  + bombs;

	CreateGameFild();

	CreateBombs(bombs);
	ShowMackFild();

	pause = false;
	stopTh = true;
	RunTimer();

	CursorY = FildPositionY + FSizeY / 2;
	CursorX = FildPositionX+ FSizeX /2* BodyMas;
	WriteInfoData(lvl);
	ShowBoombCount(0);
	CursorMove();
}


void MyGame::CreateGameFild()
{
	Field = new int* [FSizeY];
	UserActions = new int* [FSizeY];

	for (int i = 0; i < FSizeY; i++)
	{
		Field[i] = new int[FSizeX];
		UserActions[i] = new int[FSizeX];
		for (int t = 0; t < FSizeX; t++)
		{
			if (i == 0 || i == FSizeY - 1)
				Field[i][t] = 99;
			else if(t == 0 || t == FSizeX - 1)
				Field[i][t] = 98;
			else
				Field[i][t] = -1;

			UserActions[i][t] = 0;
		}
	}
}
void MyGame::CreateBombs(int bomb)
{
	while (bomb > 0)
	{
		int selX = rand() % (FSizeX - 2)+1;
		int selY = rand() % (FSizeY - 2)+1;

		if (Field[selY][selX] != 14)
		{
			Field[selY][selX] = 14;
			bomb--;
		}
	}
}

void MyGame::WriteInfoData(int lvl)
{
	setCursorPosition(0, 0);
	SetColor((int)FG_COLORS::FG_BROWN, (int)FG_COLORS::FG_LIGHTGRAY);
	string s = "";
	for (int i = 0; i < window_X; i++)
		s += " ";
	cout << s << endl << s << endl << s;

	SetColor((int)FG_COLORS::FG_BLUE, (int)FG_COLORS::FG_LIGHTGRAY);
	setCursorPosition(window_X / 2 - 7, 0);
	cout << "Game: " << LSMenu[lvl] <<" ("<< Lvls[lvl][0]-2 << "x" << Lvls[lvl][1]-2 << ")  ";
	
	SetColor((int)FG_COLORS::FG_GRAY, (int)FG_COLORS::FG_LIGHTGRAY);
	setCursorPosition(window_X - 25, 1);
	int r = GetRecord(lvl);
	cout << "Record: " << to_string(r/60) << " min. " << to_string(r % 60)<<" sec.";

	setCursorPosition(0, window_Y - 1);
	cout << s;
	setCursorPosition(1, window_Y - 1);
	SetColor((int)FG_COLORS::FG_BLACK, (int)FG_COLORS::FG_LIGHTGRAY);
	cout << "Press 'SPACE' to PAUSE      Press 'ESCAPE' to exit ";
}
void MyGame::ShowTimer()
{
	SetColor((int)FG_COLORS::FG_GRAY, (int)FG_COLORS::FG_LIGHTGRAY);
	setCursorPosition(window_X -25, 2);
	cout << "Time: ";
	SetColor((int)FG_COLORS::FG_LIGHTBLUE, (int)FG_COLORS::FG_LIGHTGRAY);
	cout << time_ / 60;
	SetColor((int)FG_COLORS::FG_GRAY, (int)FG_COLORS::FG_LIGHTGRAY);
	cout << " min. ";
	SetColor((int)FG_COLORS::FG_LIGHTBLUE, (int)FG_COLORS::FG_LIGHTGRAY);
	cout << time_ % 60;
	SetColor((int)FG_COLORS::FG_GRAY, (int)FG_COLORS::FG_LIGHTGRAY);
	cout << " sec.  ";
}
void  MyGame::ShowBoombCount(int action)
{
	if (action != 0)
		if (action < 0 && boombFound >0)
			boombFound -= 1;
		else if (boombFound < 10)
			boombFound += 1;

	SetColor((int)FG_COLORS::FG_BLACK, (int)FG_COLORS::FG_LIGHTGRAY);
	setCursorPosition(1, 2);
	cout << "Boombs: " << Lvls[(int)LVL][2] - boombFound << "     ";
}

dataPxel GetPixel(int data)
{
	dataPxel pixel;

	pixel.TextColour = -1;
	pixel.BackgroundColour = -1;
	pixel.textPrint = "   ";

	switch (data)
	{
		case 99:
		case 98:
		{
			pixel.BackgroundColour = (int)FG_COLORS::FG_GRAY;
			pixel.TextColour = pixel.BackgroundColour;
			pixel.textPrint = " # ";
			return pixel;
		}
		case 0:
		{
			pixel.TextColour = 2;
			pixel.BackgroundColour = 15;
			pixel.textPrint = "   ";
			return pixel;
		}
		case -1:
		case 14:
		{
			pixel.TextColour = -1;
			pixel.BackgroundColour = -1;
			pixel.textPrint = "   ";
			return pixel;
		}
		case 15:
		{
			pixel.TextColour = 0;
			pixel.BackgroundColour = 15;
			pixel.textPrint = " X ";
			return pixel;
		}
		default:
		{
			FG_COLORS color = FG_COLORS::FG_BLUE;
			if (data == 1)
				color = FG_COLORS::FG_BLUE;
			else if (data == 2)
				color = FG_COLORS::FG_GREEN;
			else if (data == 3)
				color = FG_COLORS::FG_RED;
			else if (data == 4)
				color = FG_COLORS::FG_MAGENTA;
			else if (data == 5)
				color = FG_COLORS::FG_CYAN;
			else if (data == 6)
				color = FG_COLORS::FG_LIGHTGREEN;
			else if (data == 7)
				color = FG_COLORS::FG_BLACK;
			else if (data == 8)
				color = FG_COLORS::FG_CYAN;

			pixel.TextColour = (int)color;
			pixel.BackgroundColour = (int)FG_COLORS::FG_YELLOW;
			pixel.textPrint = ' ' + to_string(data) + ' ';
			return pixel;
		}
	}
}

void MyGame::ShowMackFild()
{
	for (int y = 0; y < FSizeY; y++)
	{
		setCursorPosition(FildPositionX, FildPositionY + y);

		int t = 0;
		if (y % 2 == 0)t = 1;

		for (int x = 0; x < FSizeX; x++, t++)
		{
			if (t % 2 == 0)
				SetColor(2, 15);
			else
				SetColor(4, 7);

			if (UserActions[y][x] == 0)
			{
				dataPxel getPixel = GetPixel(Field[y][x]);		
				SetColor(getPixel.TextColour,getPixel.BackgroundColour);
				cout << getPixel.textPrint;
			}
			else
			{
				SetColor(FG_COLORS::FG_WHITE, FG_COLORS::FG_GRAY);
				cout << GetActionSum(UserActions[y][x]);
			}
		}
		//cout << endl;
	}
}
void MyGame::RecOpen(int y, int x)
{
	if (Field[y][x] == -1 && UserActions[y][x] ==0)
	{
		Field[y][x] = ItsBoomb(y, x);
		CountOpenItems++;

		if (Field[y][x] < 1)
		{
			RecOpen(y - 1, x - 1);
			RecOpen(y, x - 1);
			RecOpen(y + 1, x - 1);
			RecOpen(y - 1, x);
			RecOpen(y + 1, x);
			RecOpen(y - 1, x + 1);
			RecOpen(y, x + 1);
			RecOpen(y + 1, x + 1);
		}
	}
	else {}

}

int MyGame::ItsBoomb(int y, int x)
{
	int result = 0;

	if (Field[y - 1][x - 1] == 14)
		result++;
	if (Field[y - 1][x] == 14)
		result++;
	if (Field[y - 1][x + 1] == 14)
		result++;
	if (Field[y][x - 1] == 14)
		result++;
	if (Field[y][x + 1] == 14)
		result++;
	if (Field[y + 1][x - 1] == 14)
		result++;
	if (Field[y + 1][x] == 14)
		result++;
	if (Field[y + 1][x + 1] == 14)
		result++;

	return result;
}

void MyGame::ShowAllBombs()
{
	for (int i = 0; i < FSizeY; i++)
	{
		for (int t = 0; t < FSizeX; t++)
		{
			if (Field[i][t] == 14)
			{
				Field[i][t] = 15;
				UserActions[i][t] = 0;
			}
		}
	}
	ShowMackFild();
}

void MyGame::CursorMove()
{
	while (true)
	{
		this_thread::sleep_for(std::chrono::milliseconds(10));
		if (GetAsyncKeyState(VK_ESCAPE) == -32767) {
			CloseRaund();
			return;
		}
		if (GetAsyncKeyState(VK_SPACE) == -32767) {
			ShowPause();
		}
		else if(pause == false)
		{
			if (GetAsyncKeyState(VK_LEFT) == -32767) {
				if (GetFaktual_X() > 1)
				{
					BackColorSet(GetFaktual_Y(), GetFaktual_X());
					CursorX -= BodyMas;
				}
			}
			if (GetAsyncKeyState(VK_RIGHT) == -32767) {
				if (GetFaktual_X() < FSizeX - 2)
				{
					BackColorSet(GetFaktual_Y(), GetFaktual_X());
					CursorX += BodyMas;
				}
			}
			if (GetAsyncKeyState(VK_UP) == -32767) {
				if (GetFaktual_Y() > 1)
				{
					BackColorSet(GetFaktual_Y(), GetFaktual_X());
					CursorY--;
				}
			}
			if (GetAsyncKeyState(VK_DOWN) == -32767) {
				if (GetFaktual_Y() < FSizeY - 2)
				{
					BackColorSet(GetFaktual_Y(), GetFaktual_X());
					CursorY++;
				}
			}
			if (GetAsyncKeyState(VK_SHIFT) == -32767)
			{
				if (Field[GetFaktual_Y()][GetFaktual_X()] == -1 || Field[GetFaktual_Y()][GetFaktual_X()] > 8)
				{
					if (UserActions[GetFaktual_Y()][GetFaktual_X()] == 24)
					{
						UserActions[GetFaktual_Y()][GetFaktual_X()] = 0;
						ShowBoombCount(-1);
					}
					else
					{
						UserActions[GetFaktual_Y()][GetFaktual_X()] = 24;
						ShowBoombCount(1);
					}

					ShowMackFild();
				}
			}
			if (GetAsyncKeyState(VK_CONTROL) == -32767)
			{
				if (Field[GetFaktual_Y()][GetFaktual_X()] == -1 || Field[GetFaktual_Y()][GetFaktual_X()] > 8)
				{
					if (UserActions[GetFaktual_Y()][GetFaktual_X()] == 94)
						UserActions[GetFaktual_Y()][GetFaktual_X()] = 0;
					else
					{
						if (UserActions[GetFaktual_Y()][GetFaktual_X()] == 24)
							ShowBoombCount(-1);

						UserActions[GetFaktual_Y()][GetFaktual_X()] = 94;
					}

					ShowMackFild();
				}
			}

			setCursorPosition(CursorX, CursorY);
			SetColor((int)FG_COLORS::FG_LIGHTGRAY, (int)FG_COLORS::FG_BLUE);
			if (UserActions[GetFaktual_Y()][GetFaktual_X()] == 0)
				cout << GetPixel(Field[GetFaktual_Y()][GetFaktual_X()]).textPrint;
			else
			{
				cout << GetActionSum(UserActions[GetFaktual_Y()][GetFaktual_X()]);
			}

			if (GetAsyncKeyState(VK_RETURN) == -32767)
			{
				if (UserActions[GetFaktual_Y()][GetFaktual_X()] != 24)
				{
					UserActions[GetFaktual_Y()][GetFaktual_X()] = 0;

					if (Field[GetFaktual_Y()][GetFaktual_X()] == 14)
					{
						Field[GetFaktual_Y()][GetFaktual_X()] = 15;
						Ups_Boomb();
						CloseRaund();
						return;
					}
					else
					{
						RecOpen(GetFaktual_Y(), GetFaktual_X());
					}
					ShowMackFild();
					if (CountOpenItems == FSizeX * FSizeY)
					{
						Victory();

						if(GetRecord(LVL)> time_)
							WriteWinner(LVL, time_, LSMenu[LVL]);

						CloseRaund();
						return;
					}
				}
			}

			ShowTimer();
		}
	}
}

void MyGame::BackColorSet(int y, int x)
{
	int text = -1;
	int back = -1;
	string tex = "   ";

	if (UserActions[y][x] == 0)
	{
		dataPxel getPixel = GetPixel(Field[y][x]);
		text = getPixel.TextColour;
		back = getPixel.BackgroundColour;
		tex = getPixel.textPrint;

		if (back == -1)
			if (GetFaktual_Y() % 2 == 0 && GetFaktual_X() % 2 == 0 || GetFaktual_Y() % 2 != 0 && GetFaktual_X() % 2 != 0)
				back = (int)FG_COLORS::FG_LIGHTGRAY;
			else
				back = (int)FG_COLORS::FG_WHITE;

		if (text == -1) text = 1;
	}
	else
	{
		text = (int)FG_COLORS::FG_WHITE;
		back = (int)FG_COLORS::FG_GRAY;
		tex = GetActionSum(UserActions[y][x]);
	}
	setCursorPosition(CursorX, CursorY);
	SetColor(text, back);
	cout << tex;
}

int MyGame::GetFaktual_X()
{
	return (CursorX - FildPositionX) / BodyMas;
}
int MyGame::GetFaktual_Y()
{
	return CursorY - FildPositionY;
}
string MyGame::GetActionSum(int i)
{
	if (i == 24)
	{
		return flag;
	}
	else
	{
		return none;
	}
}

void MyGame::Ups_Boomb()
{
	MyGame::ShowAllBombs();
	GameLost();//звук взрива

	SetColor((int)FG_COLORS::FG_BLACK, (int)FG_COLORS::FG_GREEN);
	setCursorPosition(0, window_Y-2);
	system("pause");

	int widthLogo = (int)LostLogo[0].length();
	int spase = (window_X - widthLogo) / 2;
	int count = sizeof(LostLogo) / sizeof(string);

	int YPosition = (window_Y / 2) - (count / 2);
	
	
	string s = "";
	for (int i = 0; i < window_X ; i++)
		s += " ";

	for (int i = 0; i < count; i++)
	{
		setCursorPosition(0, YPosition+i);
		SetBackgroundColor(FG_COLORS::FG_BLUE);
		cout << s;
		for (int t = 0; t < LostLogo[i].length(); t++)
		{
			if (LostLogo[i][t] == '#')
			{
				SetColor((int)FG_COLORS::FG_RED, (int)FG_COLORS::FG_RED);
				setCursorPosition(spase + t, i + YPosition);
				cout << "#";
			}
		}
	}
	SetColor((int)FG_COLORS::FG_LIGHTGRAY, (int)FG_COLORS::FG_BLUE);
	setCursorPosition(0, window_Y-2);
	system("pause");
}

void MyGame::Victory()
{
	GameWin();//звук перемоги

	int widthLogo = (int)VinLogo[0].length();
	int spase = (window_X - widthLogo) / 2;
	int count = sizeof(VinLogo) / sizeof(string);

	int YPosition = (window_Y / 2) - (count / 2);

	string s = "";
	for (int i = 0; i < window_X; i++)
		s += " ";

	for (int i = 0; i < count; i++)
	{
		setCursorPosition(0, YPosition + i);
		SetBackgroundColor(FG_COLORS::FG_BLUE);
		cout << s;
		for (int t = 0; t < VinLogo[i].length(); t++)
		{
			if (VinLogo[i][t] == '#')
			{
				SetColor((int)FG_COLORS::FG_GREEN, (int)FG_COLORS::FG_GREEN);
				setCursorPosition(spase + t, i + YPosition);
				cout << "#";
			}
		}
	}

	setCursorPosition(0, window_Y-2);
	system("pause");
}

void MyGame::ShowPause()
{
	string p = ">> PAUSE <<";
	if (pause)
	{
		pause = false;
		setCursorPosition(window_X / 2- (p.length()/2), 2);
		SetColor((int)FG_COLORS::FG_LIGHTGRAY, (int)FG_COLORS::FG_LIGHTGRAY);
		cout << p;
	}
	else
	{
		pause = true;

		setCursorPosition(window_X / 2 - (p.length() / 2), 2);
		SetColor((int)FG_COLORS::FG_RED, (int)FG_COLORS::FG_LIGHTGRAY);
		cout << p;
	}
}

void MyGame::CloseRaund()
{
	stopTh = false;
	pause = true;
}