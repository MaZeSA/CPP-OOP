//167. Написать программу, которая проверяет, есть ли во введен -
//ном с клавиатуры массиве элементы с одинаковым значением.

#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int n = 10;
    cout << "Введіть " << n << " значень для масиву:\n";

    int _arrey[n];

    for (int item = 0; item < n; item++)
    {
        cout << "Введіть значення [" << item << "]=";
        cin >> _arrey[item];
    }

    //Альтернативний варіант сортуванню
    bool found = false;
    int masFound[n] = { 0 }; //зберігання результатів пошуку
    for (int sItem = 0; sItem < n - 1; sItem++)
    {
        if (masFound[sItem] != -1) //значення -1 вже були перевірені і мають повторення
            for (int x = sItem + 1; x < n; x++)
                if (_arrey[sItem] == _arrey[x])
                {
                    masFound[sItem]++;//кількість повторень
                    masFound[x] = -1;
                    found = true;
                }
    }

    if (found)
    {
        for (int f = 0; f < n; f++)
            if (masFound[f] != -1 && masFound[f] != 0)
                cout << "Число " << _arrey[f] << " повторяється " << masFound[f] + 1 << " раз(и)" << endl;
    }
    else
        cout << "Числа не повторяються " << endl;

    return 0;
}
