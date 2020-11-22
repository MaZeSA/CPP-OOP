
#include <string>
#include "CursorPosition.h"
#include <iostream>
#include "Funktions.h"
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