#pragma once
enum class FG_COLORS
{
    FG_BLACK = 0,
    FG_BLUE = 1,
    FG_GREEN = 2,
    FG_CYAN = 3,
    FG_RED = 4,
    FG_MAGENTA = 5,
    FG_BROWN = 6,
    FG_LIGHTGRAY = 7,
    FG_GRAY = 8,
    FG_LIGHTBLUE = 9,
    FG_LIGHTGREEN = 10,
    FG_LIGHTCYAN = 11,
    FG_LIGHTRED = 12,
    FG_LIGHTMAGENTA = 13,
    FG_YELLOW = 14,
    FG_WHITE = 15
};

void setTextColour(FG_COLORS colour);
void SetColor(int text, int background);
void SetTextColor(int text);
void SetColor(FG_COLORS text, FG_COLORS background);
void SetBackgroundColor(FG_COLORS background);
void SetBackgroundColour(int background);
