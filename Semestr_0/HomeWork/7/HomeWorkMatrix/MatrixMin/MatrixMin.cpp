//3. Вывести на экран индексы всех минимальных элементов матрицы.
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

    cout <<"Пошук мінімальних елементів матриці: \n"<< endl;

    int min = 10;
    //матриця nxn
    for (int str = 0; str < n; str++)//генерація матриці по рядкам
    {
        for (int colum = 0; colum < n; colum++)
        {
            int r = rand() % 14 + (-4); //-4 до 9
            matrix[str][colum] = r;
         
            string tab = r < 0 ? "  " : "   "; //для оформлення вигляду таблиці
            cout <<tab<< r; //вивід матриці
           
            if (r < min)
                min = r;
        }

        cout << endl;
    }

    cout << "\nМінімальні елементи матриці: \n" << endl;

    for(int i=0; i<n; i++)
        for (int s = 0; s < n; s++)
        {
            if (matrix[i][s] == min)
                cout << "matrix[" << i << "][" << s << "] = " << min<<endl;
        
        }
}

