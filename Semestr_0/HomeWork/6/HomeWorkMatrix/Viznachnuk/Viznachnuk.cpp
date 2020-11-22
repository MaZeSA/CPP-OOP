#include <Windows.h>
#include <iostream>
#include <time.h>
using namespace std;

#include <cmath>

double GetViznachnik(int** matrix, int n);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((int)time(0));

    int n = 3;
   
    int **matrix= new int*[n];

    cout << "Матриця із чисел від 0 до 999 \n" << endl;

    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[n];

        for (int c = 0; c < n; c++)
        {
            matrix[i][c] = rand() % 9 + 1;
            //cout << matrix[i][c] << "\t";
        }
       /* cout << endl;*/
    }
   
    cout << "------------ \n"<< GetViznachnik(matrix, n) << endl;

    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}


double GetViznachnik(int** Arr, int size)
{
    int i, j;
    double det = 0;
    int** matr;

    cout <<"---"<< endl;
    for (int i = 0; i < size; ++i)
    {
        for (int c = 0; c < size; c++)
        {
            cout << Arr[i][c] << "\t";
        }
        cout << endl;
    }

    if (size == 1)
        return Arr[0][0];
    else if (size == 2)
        return Arr[0][0] * Arr[1][1] - Arr[0][1] * Arr[1][0];
    else
    {
        matr = new int* [size - 1];
        for (i = 0; i < size; ++i)
        {
            for (j = 0; j < size - 1; ++j)
            {
                if (j < i)
                    matr[j] = Arr[j];
                else
                    matr[j] = Arr[j + 1];
            }
            return pow((double)-1, (i + j)) * GetViznachnik(matr, size - 1) * Arr[i][size - 1];
        }
        delete[] matr;
}



}