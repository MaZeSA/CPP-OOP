#include "CursorPosition.h"
#include <string>
#include <iostream>
#include "Functions.h"
#include "ConsoleColor.h"
using namespace std;
void CleanEkran(int startY, int endY, int countSpase)
{
    if (endY == 0) endY = 29;
    string s = "";
    for (int i = 0; i < countSpase; i++)
        s += " ";
    for (int i = startY; i < endY; i++)
    {
        setCursorPosition(0, i);
        cout << s;
    }
}

void CleanEkran(int startY, int endY, int countSpase, int color)
{
    SetColor(FG_COLORS::FG_BLACK, (FG_COLORS)color);

    if (endY == 0) endY = 29;
    string s = "";
    for (int i = 0; i <= countSpase; i++)
        s += " ";
    for (int i = startY; i <= endY; i++)
    {
        setCursorPosition(0, i);
        cout << s;
    }
}