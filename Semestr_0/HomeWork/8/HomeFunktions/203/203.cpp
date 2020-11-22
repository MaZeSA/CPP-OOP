// 203. Написать функцию пересчета расстояния из миль в километры(1 миля = 1, 60094 км).

#include <Windows.h>
#include <iostream>
using namespace std;

void RunConverter();
double MileToKm(double);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Конвертер миль в кілометри" << endl;

    RunConverter();
}

void RunConverter()
{
    cout << "Введіть милі для конвертування чи 0 для виходу"
        << endl
        << "_>";

    double num = 0;
    cin >> num;

    if (num == 0)
        exit(0);
    else
        cout << num << " миль дорівнює "
        << MileToKm(num) << " кілометрів"
        << endl << endl;

    RunConverter();
}

double MileToKm(double mile)
{
    return mile * 1.60094;
}