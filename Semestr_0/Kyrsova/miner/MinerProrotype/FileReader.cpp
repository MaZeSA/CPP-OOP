#define _CRT_SECURE_NO_WARNINGS
#include "FileReader.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include "CursorPosition.h"
#include "ConsoleColor.h"
using namespace std;
extern short window_X;
extern short window_Y;
vector<Winners> ListWinners;

void ReadWinners()
{
    if (ListWinners.size() > 0)return;
    ifstream myFile;
    string line;
    myFile.open("Winners.lst");
    if (myFile.is_open())
    {
        while (getline(myFile, line))
        {
            int i = 0;
            string temp[4]{""};
            for (char c : line)
            {
                if (c != '|')
                    temp[i] += c;
                else
                    i++;
            }
            Winners win;
            win.Level_ = temp[0];
            win.Name_ = temp[1]; 
            win.time_ = stoi(temp[2]);
            win.data_ = temp[3];
            ListWinners.push_back(win);
        }
    }
    myFile.close();
}
int GetRecord(int i)
{
    if (ListWinners.size() < 1)
        return 999999;
    return(ListWinners[i].time_);
}

std::vector<Winners> GetListWinnes()
{
    return ListWinners;
}

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

void WriteWinner(int lvl, int time_, string Level)
{
	std::string name = ShowGetYouName();
  

    ListWinners[lvl].Name_ = name;
    ListWinners[lvl].Level_ = Level;
    ListWinners[lvl].time_ = time_;
  
    ListWinners[lvl].data_ = currentDateTime();
    SaveFileWinners();
}
std::string ShowGetYouName()
{
    string name = "";

    string s = "";
    for (int i = 0; i < 25; i++)
        s += " ";
   
    int color = (int)FG_COLORS::FG_LIGHTGREEN;
    SetColor((int)FG_COLORS::FG_RED, color);
    for (int i = 0; i < 9; i++)
    {
        setCursorPosition(window_X/2-15, window_Y/2-4+i);
        cout << s;
    }

    SetColor((int)FG_COLORS::FG_BLUE, color);
    setCursorPosition(window_X / 2 - 8, window_Y / 2 - 3);
    cout << "NEW RECORD!";

    SetColor((int)FG_COLORS::FG_BLACK, color);
    setCursorPosition(window_X / 2 - 10, window_Y / 2 - 1);
    cout << "Enter you name:";

    setCursorPosition(window_X / 2 - 10, window_Y / 2);
    SetColor((int)FG_COLORS::FG_BLUE, (int)FG_COLORS::FG_GRAY);
    cout << "               ";
    setCursorPosition(window_X / 2 - 10, window_Y / 2);
    SetColor((int)FG_COLORS::FG_BLUE, (int)FG_COLORS::FG_GRAY);
    cin >> name;
    return name;
}

void SaveFileWinners()
{
    ofstream myFile;
    string line;
    myFile.open("Winners.lst");
    if (myFile.is_open())
    {
        for (Winners win : ListWinners)
        {
            myFile<< win.Level_ <<"|" <<win.Name_ << "|" << win.time_ << "|" << win.data_ << endl;
        }
    }
    myFile.close();
}