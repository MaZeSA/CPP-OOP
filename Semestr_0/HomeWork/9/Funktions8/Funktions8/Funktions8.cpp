//Сортування масиву по зростаню або по спаданню.
#include <Windows.h>
#include <iostream>
#include <time.h>
using namespace std;

void Sort(int*, int, bool);
void ShowMas(const int*, int);
void Recursion(int*, int);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((int)time(0));
    
    const int n = 10;
    int mas[n] = { 0 };

    cout << "Генерація масиву \n" << endl;

    for (int i = 0; i < n; i++) //створення масиву
    {
        mas[i] = rand() % 10;
    }
    ShowMas(mas, n);
    Recursion(mas, n);
}

void Recursion(int* mas, int n) // функція для зручності щоб не перезапускати програму
{
    cout << "Оберіть як сортувати масив: \n"
        << "0 - До більшого\n"
        << "1 - До меньшого\n"
        << "2 - Для виходу з програми\n"
        << "_> ";

    int select = 0;
    cin >> select;

    bool isUp = true; //вірно якщо сортувати по зростанню

    if (select == 2)
        exit(0);
    else
    {
        if (select < 0 || select > 2)
            cout << "Не вірний ввід\n" << endl;
        else
        {
            if (select == 1)
                isUp = false;

            Sort(mas, n, isUp); // сортування
            cout << "Масив відсортовано:" << endl;
            ShowMas(mas, n);
        }
        Recursion(mas, n);
    }
}


void Sort(int* mas, int masCount, bool isUp)//сортування
{
    for (int i = 0; i < masCount; i++)
    {
        for (int t = i + 1; t < masCount; t++)
        {
            if (isUp)
            {
                if (mas[i] > mas[t])
                    swap(mas[i], mas[t]);
            }
            else
            {
                if (mas[i] < mas[t])
                    swap(mas[i], mas[t]);
            }
        }
    }
}

void ShowMas(const int* mas, int count)//вивід масиву
{
    for (int i = 0; i < count; i++)
    {
        cout << mas[i] << " ";
    }
    cout << endl << endl;
}