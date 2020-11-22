#include <Windows.h>
#include <iostream>
#include <conio.h>
void Size(short x, short y)
{
    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD crd = { x, y };
    SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
    SetConsoleWindowInfo(out_handle, true, &src);
    SetConsoleScreenBufferSize(out_handle, crd);

}
//void SetSize()
//{
//    HWND hwnd;
//    char Title[1024];
//    GetConsoleTitle(Title, 1024); // Узнаем имя окна
//    hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна
//    MoveWindow(hwnd, 0, 0, 200, 200, TRUE);//xnew,ynew,wnew,hnew -новые положение x,y, ширина и высота
//    _getch();
//}
//
//void u()
//{
//    char szTITLE[] = "SEARCHEDSTRINGTITLE";
//
//    SetConsoleTitle(szTITLE);
//    Sleep(1.5);
//    MoveWindow(FindWindow(NULL, szTITLE), 1, 1, 400, 400, false);
//
//    getch();
//}

void r()
{
    RECT r;
    HWND console = GetConsoleWindow();
    GetWindowRect(console, &r); //stores the console current dimensions
    MoveWindow(console, r.left, r.top, 1800, 1000, TRUE);
}