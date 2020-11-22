//4.Сформировать матрицу из чисел от 0 до 999, вывести ее на экран.
//Посчитать количество двузначных чисел в ней.Використати рандом.
#include <Windows.h>
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((int)time(0));


    const int n = 7;
    int matrix[n][n];

    cout << "Матриця із чисел від 0 до 999 \n" << endl;

    int count = 0;

    for (int str = 0; str < n; str++)//генерація матриці по рядкам
    {
        for (int colum = 0; colum < n; colum++)
        {
            int r = rand() % 1000 ; 
            cout <<  r << "\t"; //вивід матриці
            if (r > 9 && r< 100)//підрахунок двохзначних чисел
                count++; 
        }

        cout << endl;
    }

    cout << " \nКількість двохзначних чисел:  "<< count << endl;
}

