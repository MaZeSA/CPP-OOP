#include <string>
#include <Windows.h>
#include <thread>
#include <iostream>
#include "ConsoleSize.h"
#include "Logo.h"
#include "CursorPosition.h"
#include "ConsoleColor.h"
#include "Menu.h"
#include "Game.h"
#include "PlaySound.h"
#include "Functions.h"
#include "FileReader.h"
#pragma comment(lib,"Winmm.lib")

using namespace std;
void PrintLogo(bool, long);
void MakeMenu();
void ShowMenu(int);
void StartGame();
void Leaderboard();
void About();
void GameExit();
void RunGame(int i);
void PrintTekran(bool);
void WaitBack();
void PrintStep();

short window_Y(40), window_X(90);

int const y = 10, x = 50;

extern string LSMenu[];

bool firstStart = false;
int main()
{    void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &structCursorInfo);
    srand((int)time(0));
    setTextColour(FG_COLORS::FG_BLACK);
    
    SetColor(15, 0);
       
    Size(window_X,  window_Y);
  
    //WhatColor();//testColor
    CleanEkran(0, window_Y, window_X);

    PrintLogo(firstStart, 30);
    firstStart = true;

    ReadWinners();

    MakeMenu();
  
}

void PrintLogo(bool firstStart, long wait)
{
    this_thread::sleep_for(std::chrono::milliseconds(70));

    int widthLogo = (int)Logo[0].length();
    int spase = (window_X - widthLogo) / 2;

    int count = sizeof(Logo) / sizeof(string);

    SetColor(FG_COLORS::FG_BLUE, FG_COLORS::FG_CYAN);
    char cCout = '_';
    for (int i = count - 1; i >= 0; i--)
    {
        if (i == ChColorY)
        {
            SetColor(FG_COLORS::FG_BLACK, FG_COLORS::FG_BROWN);
            cCout = ' ';
        }

        this_thread::sleep_for(std::chrono::milliseconds(20));
        for (int t = 0; t < Logo[i].length(); t++)
        {
            if (Logo[i][t] == '#')
            {
                setCursorPosition(spase + t, i + LogoPositionY);
                cout << cCout;
            }
        }
    }
    SetColor(FG_COLORS::FG_GRAY, FG_COLORS::FG_BLACK);
    setCursorPosition(window_X/2, LogoPositionY + count + 1);
    cout << "v1.0";

    setCursorPosition(1, window_Y - 2);

    if (firstStart == false)
        system("pause");
    else
        this_thread::sleep_for(std::chrono::milliseconds(wait));
}

Menu_L menu;
void MakeMenu()
{ 
    int MenuPositionY = 15;
    int menuPosition = window_X / 2 -5;
    menu.SetPositionMenu(menuPosition, MenuPositionY);   
    ShowMenu(0);
}

void ShowMenu( int m)
{
    void (*ListFunktions[4])() = { StartGame, Leaderboard, About, GameExit };
    menu.CreteMenu(m);
    menu.SetMenuWait(true);
    while (menu.GetMenuWait())
    {
        this_thread::sleep_for(std::chrono::milliseconds(2));

        if (GetAsyncKeyState(VK_UP) == -32767) {
            menu.SetSelectMenu(-1);
        }
        if (GetAsyncKeyState(VK_DOWN) == -32767) {
            menu.SetSelectMenu(1);
        }
        if (GetAsyncKeyState(VK_RETURN) == -32767) {
            menu.SetMenuWait(false);

            if (m == 0)
            {
                ListFunktions[menu.GetSelectMenu()]();
            }
            else
            {
                int i = menu.GetSelectMenu();
                if (i != 5)
                    RunGame(i);
                else
                    ShowMenu(0);
            }
               
        }
    }
}

void StartGame() {
    ShowMenu(1);
}
void Leaderboard() {
    PrintTekran(false); 
    
    string s = "";
    for (int i = 0; i < window_X; i++)
        s += " ";

    int count = sizeof(Logo) / sizeof(string);
    setCursorPosition(window_X/2-3, (count - ChColorY) + 6);
    SetColor((int)FG_COLORS::FG_BLUE, (int)FG_COLORS::FG_GRAY);
    cout << "Records";

    SetColor((int)FG_COLORS::FG_LIGHTGRAY, (int)FG_COLORS::FG_BLUE);
    setCursorPosition(0, (count - ChColorY) + 8);
    cout << s;

    setCursorPosition(1, (count - ChColorY) + 8);
    string list[4] = { "Name", "Severity level","Time","Data"};
    
    int cou = window_X / 4;
    for (int i = 0; i < 4; i++)
    {
        cout << list[i];
        for (int t = list[i].length(); t < cou; t++)
            cout << " ";
    }

    vector<Winners> wins = GetListWinnes();

    int pY = (count - ChColorY) + 9;

    for (Winners win : wins)
    {
        setCursorPosition(0, pY);

        if (pY % 2 == 0)
            SetColor((int)FG_COLORS::FG_BLACK, (int)FG_COLORS::FG_WHITE);
        else
            SetColor((int)FG_COLORS::FG_LIGHTBLUE, (int)FG_COLORS::FG_LIGHTGRAY);
        cout << s;

        setCursorPosition(1, pY);

        cout << win.Name_;
        for (int t = win.Name_.length(); t < cou; t++)
            cout << " ";
        cout << win.Level_;
        for (int t = win.Level_.length(); t < cou; t++)
            cout << " ";

        string tim = to_string(win.time_/60) + " min. ";
        tim += to_string(win.time_ % 60) + " sec. ";
        cout << tim;
        for (int t =tim.length(); t < cou; t++)
            cout << " ";

        cout << win.data_;
        for (int t = win.data_.length(); t < cou; t++)
            cout << " ";
        pY++;
    }

    while (pY != window_Y - 1)
    {
        setCursorPosition(0, pY);

        if (pY % 2 == 0)
            SetColor((int)FG_COLORS::FG_BLACK, (int)FG_COLORS::FG_WHITE);
        else
            SetColor((int)FG_COLORS::FG_WHITE, (int)FG_COLORS::FG_LIGHTGRAY);
        cout << s;
        pY++;
    }

    WaitBack();
}

void About() {
    PrintTekran(true);

    int count = sizeof(Logo) / sizeof(string);
    setCursorPosition(window_X / 2 - 3, (count - ChColorY) + 6);
    SetColor((int)FG_COLORS::FG_BLUE, (int)FG_COLORS::FG_GRAY);
    cout << "About";

    int position = count - ChColorY + 8;
    int colorLabelText = (int)FG_COLORS::FG_BLACK; 
    int colorLabelBack = (int)FG_COLORS::FG_LIGHTGRAY;
    int colorLabelText2 = (int)FG_COLORS::FG_LIGHTBLUE;

    setCursorPosition(1, ++position);
    SetColor(colorLabelText, colorLabelBack);
    cout << "Name: ";
    SetColor(colorLabelText2, colorLabelBack);
    cout << "MINES Console";   
    
    setCursorPosition(1, ++position);
    SetColor(colorLabelText, colorLabelBack);
    cout << "Version: ";
    SetColor(colorLabelText2, colorLabelBack);
    cout << "1.0";  
    
    setCursorPosition(1, ++position);
    SetColor(colorLabelText, colorLabelBack);
    cout << "Autor: ";
    SetColor(colorLabelText2, colorLabelBack);
    cout << "Pol Marshenko (MaZeSa)"; 
    
    setCursorPosition(1, ++position);
    SetColor(colorLabelText, colorLabelBack);
    cout << "For: ";
    SetColor(colorLabelText2, colorLabelBack);
    cout << " IT Step Academy Course project";
   
    PrintStep();
    //WaitBack();
}

void PrintStep()
{
    std::string itStep[] =
    {
        {" #######    ############    #######    ######## "},
        {"##               ##         ##         ##     ##"},
        {"##               ##         ##         ##     ##"},
        {" ######          ##         #######    #######  "},
        {"      ##         ##         ##         ##       "},
        {"      ##         ##         ##         ##       "},
        {"#######          ##         #######    ##       "}
    };

    int c1 = itStep[0].length() / 2;

    int color = 1;

    while (true)
    {

        if (GetAsyncKeyState(VK_ESCAPE) == -32767)
        {
            SetColor((int)FG_COLORS::FG_BLACK, (int)FG_COLORS::FG_BLACK);
            MakeMenu();
        }

        int posY = window_Y / 2 + 9;

        for (int i = 0; i < itStep[0].length(); i++)
        { 
            this_thread::sleep_for(std::chrono::milliseconds(2));
          
            if (i % 12 == 0) 
            {
                if (color == 15) color = 1;
                else if (color == 7) color++;
                else if (color == 14) color = rand() % 10;
                SetColor(12, color++);
            }

            for (int y = 0; y < 7; y++)
            {
                setCursorPosition((window_X / 2) - c1 + i, posY + y);
                if (itStep[y][i] == '#')
                    cout << " ";
            }
        }
    }
}

void RunGame(int i)
{
    setCursorPosition(0, 1);
    CleanEkran(0, window_Y, window_X, (int)FG_COLORS::FG_GRAY);
    MyGame game;

    if (i != 5)
        game.RunGame(i);
   
    main();
}

void PrintTekran(bool white)
{
    int count = sizeof(Logo) / sizeof(string);
    setCursorPosition(0, (count- ChColorY)+5);
    SetColor((int)FG_COLORS::FG_BROWN, (int)FG_COLORS::FG_GRAY);
    string s = "";
    for (int i = 0; i < window_X; i++)
        s += " ";
    cout << s << endl << s << endl << s;
   
    for (int t = (count - ChColorY) + 8; t < window_Y - 1; t++)
    {
        if (white)
            SetColor((int)FG_COLORS::FG_BLACK, (int)FG_COLORS::FG_LIGHTGRAY);
        else
            if (t % 2 == 0)
                SetColor((int)FG_COLORS::FG_BLACK, (int)FG_COLORS::FG_LIGHTGRAY);
            else
                SetColor((int)FG_COLORS::FG_WHITE, (int)FG_COLORS::FG_WHITE);

        setCursorPosition(0, t);
        cout << s;
    }
 
    SetColor((int)FG_COLORS::FG_BLACK, (int)FG_COLORS::FG_GRAY);
    setCursorPosition(0, window_Y - 1);
    cout << s;
    setCursorPosition(1, window_Y - 1);
    cout <<" Press 'ESCAPE' to back ";
}

void WaitBack()
{
    SetColor((int)FG_COLORS::FG_BLACK, (int)FG_COLORS::FG_BLACK);
    while (true)
    {
        if (GetAsyncKeyState(VK_ESCAPE) == -32767) {
         
            MakeMenu();
        }
    }
}

void GameExit() {
    exit(0);
}