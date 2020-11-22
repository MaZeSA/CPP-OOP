#pragma once
#include "ConsoleColor.h"
#include <string>
class Menu_L
{
public:
bool GetMenuWait();
void SetPositionMenu(int x, int y);
int GetPositionMenu_X();
int GetPositionMenu_Y();
void CreteMenu(int i);
int GetSelectMenu();
void SetSelectMenu(int i);
int GetCountLSMenu();
std::string* GetLStMenu();
void ReColorMenuItem();
void MoveMenu();
void SetMenuWait(bool b);
void CreateSubMenu();
private:

};