//202. Написать функцию пересчета длины из дюймов в миллиметры(1 дюйм = 2, 54 см).

#include <Windows.h>
#include <iostream>
using namespace std;

double InchToMM(double);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Конвертер дюймів в міліметри" << endl;

    while (1)
    {
        double num=0;
        cout << "Введіть дюйми для конвертування чи 0 для виходу" 
            << endl
            <<"_>";

        cin >> num;

        if (num == 0)
            exit(0);
        else
            cout << num << " дюймів дорівнює "
                 << InchToMM(num) << " міліметрів"
                 << endl << endl;
    }
}

double InchToMM(double num)
{
    return num * 2.54 * 10;
}
