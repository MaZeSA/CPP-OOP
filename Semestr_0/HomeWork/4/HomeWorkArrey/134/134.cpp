//134. Написать программу, которая выводит таблицу значений
//функции y = | x – 2 | +| x + 1 | .Диапазон изменения аргумента от –4
//до 4, шаг приращения аргумента 0, 5.

#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Таблиця значень функції y = | x – 2 | + | x + 1 | від -4 до 4 \n";

     double lb = -4;
     double hb = 4;
     double dx = 0.5;

    for (; lb <= hb; lb+=dx)
    {
        double y = fabs(lb - 2.0) + fabs(lb + 1.0);
        cout << lb << "\t" << y<<endl;
    }

    return 0;
}
