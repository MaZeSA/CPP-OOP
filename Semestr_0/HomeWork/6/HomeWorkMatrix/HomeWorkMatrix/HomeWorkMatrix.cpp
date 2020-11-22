//1. Найти положительные элементы главной диагонали квадратной матрицы.
#include <Windows.h>
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((int)time(0));

    cout << "Пошук позитивних елементів головної діагоналі квадратної матриці: \n\n";

    const int n = 10;
    int matrix[n][n];

    //квадратна матриця nxn
    for (int i = 0; i < n; i++) //Створення матриці від -4 до 6
    {
        for (int& s : matrix[i])
        {
            s = rand() % 12 + (-5); 

            string tab = s < 0 ? "  " : "   "; //для оформлення вигляду таблиці
            cout << tab << s;
        }
        cout << endl;
    }

    cout << "\nПозитивні елементи головної діагоналі: \n"<< endl;

    for (int c = 0; c < n; c++)
    {
        if (matrix[c][c] > 0)
            cout <<"\t"<< matrix[c][c] << endl;
    }
}
