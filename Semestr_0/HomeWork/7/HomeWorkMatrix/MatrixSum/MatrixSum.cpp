//2. Задана матрица неотрицательных чисел.
//Посчитать сумму элементов в каждом столбце.
//Определить, какой столбец содержит максимальную сумму.
#include <Windows.h>
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((int)time(0));

    const int n = 5;
    int matrix[n][n];


    int suma[n][1] = {0};
    int maxIndex = 0;
    //квадратна матриця nxn
    for (int colum = 0; colum < n; colum++)
    {
        for (int str = 0; str < n; str++)//генерація матриці по стовпцям
        {
            matrix[str][colum] = rand() % 9 + 1;
            suma[colum][0] += matrix[str][colum];//сума стовпця
        }

        if (suma[colum][0] > suma[maxIndex][0]) //знаходження стовпця з максимальною сумою
            maxIndex = colum;
    }

    //відображення матриці для користувача
    cout << "Матриця додатніх чисел:\n"<< endl;
    for (int i = 0; i < n; i++) 
    {
        for (int u = 0; u < n; u++)
            cout << matrix[i][u] << " ";
        cout << endl;
    }

    cout << "\nСума стовпців:" << endl;
    for (int *i : suma)
        cout << i[0] << " ";

    cout << "\n\nМаксимальна сума стовпця:" << endl;
    cout <<"№"<< maxIndex+1<< " = "<< suma[maxIndex][0] <<endl;
    
}

