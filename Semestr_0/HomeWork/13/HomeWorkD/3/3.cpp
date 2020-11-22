//3. Заданий одновимірний масив А[10].Знайти
//найменший по модулю елемент масиву.Заданий
//масив відсортувати за спаданням методом
//вставки

#include <string>
#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;

/// <summary>
/// Сортування методом вставки
/// </summary>
void Sort(int*, int);
/// <summary>
/// Мінімальне число по модулю
/// </summary>
int GetMinimum(int*, int);
/// <summary>
/// Модуль числа (abs())
/// </summary>
int Module(int);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((int)time(0));

    cout << "Створено масив: " << endl;
    int const count = 10;
    int A[count] = { 0 };
    for (int &s : A)
    {
        s = rand() % 20 + (-10);
        cout << s << " " ;
    }
    
    cout <<"\nСортування масиву за спаданням: \n" ;
    Sort(A, count);
    for (int s : A)
        cout << s << " ";

    int m = GetMinimum(A, count);
    cout << "\nНайменший елемент по модулю: \nA[" << m << "]=" << A[m];
}

 void Sort(int* A, int count)
{
    int x, j;
    for (int i = 0; i < count; i++)
    {
        x = A[i];
        for (j = i - 1; j >= 0 && A[j] < x; j--)
        {
            A[j + 1] = A[j];
        }
        A[j + 1] = x; 
    }
}

int GetMinimum(int* A, int count)
{
    int result = 0;
    for (int i = 1; i < count; i++)
        if (Module(A[result]) > Module(A[i]))
            result = i;

    return result;
}

int Module(int num)
{
    if (num < 0)
        return num * -1;
    return num;
}
