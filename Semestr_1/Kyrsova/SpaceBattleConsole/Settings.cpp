#include "Settings.h"

#include <iostream>
#include <limits>
#include <thread>

Settings* Settings::setting = nullptr;

Settings* Settings::GetSetting()
{
    if (setting == nullptr)
        setting = new Settings();
   
    return setting;
}

Settings::Settings()
{
    listKey.push_back(Settings::Keys(&p1_key_Up, "Moving up: "));
    listKey.push_back(Settings::Keys(&p1_key_Down, "Moving down: "));
    listKey.push_back(Settings::Keys(&p1_key_Shot, "Shooting: ")); 
    
    listKey.push_back(Settings::Keys(&p2_key_Up, "Moving up: "));
    listKey.push_back(Settings::Keys(&p2_key_Down, "Moving down: "));
    listKey.push_back(Settings::Keys(&p2_key_Shot, "Shooting: "));
}

void Settings::Show(int l_)
{   
    SetColor(FG_COLORS::FG_WHITE, FG_COLORS::FG_GRAY);
    setCursorPosition(0, 9);
    for (int i = 0; i < l_; i++)
        std::cout << " ";
    setCursorPosition(45, 9);
    std::cout << "Controls";
   
    setTextColour(FG_COLORS::FG_WHITE);
    setCursorPosition(15, 11);
    std::cout << "Action"; 
    setCursorPosition(30, 11);
    std::cout << "Key";

    setTextColour(FG_COLORS::FG_LIGHTRED);
    setCursorPosition(12, 13);
    std::cout << "Player 1:";

    int y_P = 14;
    for (int i = 0; i < listKey.size(); i++)
    {
        if (i == 3)
        {
            setTextColour(FG_COLORS::FG_CYAN);
            setCursorPosition(12, y_P + i+1);
            std::cout << "Player 2";
            y_P += 2;
        }

        setCursorPosition(10, y_P +i);
        setTextColour(FG_COLORS::FG_LIGHTGRAY);
        std::cout << listKey[i].name;

        setCursorPosition(30, y_P +i);
        setTextColour(FG_COLORS::FG_LIGHTGRAY);
        std::cout << *(listKey[i].key) << " (" << (char)*(listKey[i].key) <<")";

        listKey[i].indexY = y_P + i;
    }

    setCursorPosition(45, 30);
    setTextColour(FG_COLORS::FG_YELLOW);
    std::cout << "ESC - Save/Back\t Enter - Change key";

    Menu();
}

void Settings::Menu()
{
    bool back = true;
    int sel = 0;

    while (back)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
    
        PrintItem(FG_COLORS::FG_LIGHTGRAY, &listKey[sel]);

        if (GetAsyncKeyState(40) == -32767)
            (sel < listKey.size()-1) ? sel++ : sel;
        if (GetAsyncKeyState(38) == -32767)
            (sel > 0) ? sel-- : sel;  
        if (GetAsyncKeyState(27) == -32767)
            back = false;
        if (GetAsyncKeyState(13) == -32767)
        {
            setCursorPosition(30, listKey[sel].indexY);
           // cin.clear();
            int t = ret();
            *(listKey[sel].key) = t;
         
            PrintItem(FG_COLORS::FG_GREEN, &listKey[sel]);
        }

        PrintItem(FG_COLORS::FG_CYAN, &listKey[sel]);
    }
}

void Settings::PrintItem(FG_COLORS color_, Settings::Keys* key_)
{
        setCursorPosition(30, key_->indexY);
        setTextColour(color_);
        std::cout << *(key_->key) << " (" << (char)*(key_->key) << ")             ";
}

int Settings::ret()
{
    //cin.ignore();
   // cin.clear();
    cout<<("Press any key");
    cin.ignore();
   // cin.clear();
    while (!_kbhit());
    return VkKeyScanEx(_getch(), GetKeyboardLayout(0));
}

int Settings::Get_Up_key(int player_)
{
    return (player_ == 1) ? p1_key_Up : p2_key_Up;
}

int Settings::Get_Down_key(int player_)
{
    return (player_ == 1) ? p1_key_Down : p2_key_Down;
}

int Settings::Get_Shot_key(int player_)
{
    return (player_ == 1) ? p1_key_Shot : p2_key_Shot;
}
