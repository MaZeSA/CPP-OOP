#include "Menu.h"
#include "CursorPosition.h"
#include <iostream>
#include <thread>
#include "PlaySound.h"
#include "Functions.h"
using namespace std;   

extern short window_X; extern short window_Y;

    const int IMCount = 4;  
    string IMenu[IMCount] = { "Start Game","Records","About","Exit" };
    const int LSMCount = 6;
    string LSMenu[LSMCount] = { "Easy", "Simply", "Normal", "Hard", "Very Hard", "Back" };

    int ActualMenu = 0; 
    int ActualCountMenu = IMCount;
    string* ActualListMenu = IMenu;

    int selectMenu = 0;
    int MenuPositionX = 0, MenuPositionY = 0;
    bool MenuWait_ = true;
    FG_COLORS NormalStateColor = FG_COLORS::FG_CYAN;


    void Menu_L::SetMenuWait(bool b)
    {
        MenuWait_ = b;
    }
    bool Menu_L::GetMenuWait()
    {
        return  MenuWait_;
    }
    void Menu_L::SetPositionMenu(int x, int y)
    {
        MenuPositionX = x;
        MenuPositionY = y;
    }
    int Menu_L::GetPositionMenu_X()
    {
        return MenuPositionX;
    }
    int Menu_L::GetPositionMenu_Y()
    {
        return MenuPositionY;
    }  
    
    int Menu_L::GetCountLSMenu()
    {
        return LSMCount;
    } 
   std::string* Menu_L::GetLStMenu()
    {
       return LSMenu;
    }

    void Menu_L::CreteMenu(int i)
    {
        selectMenu = 0;
        CleanEkran(MenuPositionY - 4, window_Y, ::window_X);
        ActualMenu = i;
        if (i == 1) {
            ActualListMenu = LSMenu;
            ActualCountMenu = LSMCount;
        }
        else
        {
            ActualListMenu = IMenu;
            ActualCountMenu = IMCount;
        }
        for (int i = 0; i < ActualCountMenu; i++)
        {
            setTextColour(NormalStateColor);
            setCursorPosition(MenuPositionX, MenuPositionY + i);
            cout << ActualListMenu[i];
        }
        SetSelectMenu(0);
    }

    int Menu_L::GetSelectMenu()
    {
      return selectMenu;
    }
   

    void Menu_L::SetSelectMenu(int i)
    {   
        if (i != 0)
            if (i < 0)
            {
                PlayMenu();
                if (MenuPositionY + selectMenu <= MenuPositionY)return;
            }
            else
            {
                PlayMenu();
                if (MenuPositionY + selectMenu >= MenuPositionY + ActualCountMenu - 1)return;
            }

        ReColorMenuItem();
        selectMenu += i;
        MoveMenu();
    }
    void Menu_L::ReColorMenuItem()
    {
        setCursorPosition(MenuPositionX, MenuPositionY + selectMenu);
        setTextColour(NormalStateColor);
        cout << ActualListMenu[selectMenu];
        setCursorPosition(MenuPositionX - 1, MenuPositionY + selectMenu);
    }
    void Menu_L::MoveMenu()
    {
        setCursorPosition(MenuPositionX, MenuPositionY + selectMenu);
        setTextColour(FG_COLORS::FG_BROWN);
        cout << ActualListMenu[selectMenu];
        setCursorPosition(MenuPositionX - 1, MenuPositionY + selectMenu);
    }
    

    void Menu_L::CreateSubMenu()
    {
       
        for (int i = 0; i < 3; i++)
        {
            setCursorPosition(MenuPositionX, MenuPositionY + i);
        }
        SetSelectMenu(0);
    }