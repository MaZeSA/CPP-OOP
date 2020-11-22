// Зробити програму для множення матриць.
#include <Windows.h>
#include <time.h>
#include <iostream>
using namespace std;

const int n = 2; //розмір матриці

void SetMatrix(int array[][n]); //створення матриць

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((int)time(0));

	int a[n][n], b[n][n];

	cout << "Перша матриця: \n";
	SetMatrix(a); //матриця А
	cout << "Друга матриця: \n";
	SetMatrix(b); //матриця В

	cout << "Множення матриць: \n";

	for (int s = 0; s < n; s++) //вибір строки А
	{
		for (int k = 0; k < n; k++) //вибір колонки В
		{
			int suma = 0;
			for(int i = 0; i <n; i++) //строка  В на колонку в А
			{ 
				suma += b[i][k] * a[s][i]; 
			}
			cout << suma << "\t";
		}
		cout << endl;

	}

}

void SetMatrix(int array[][n]) 
{
	for (int i = 0; i < n; i++)
	{
		for (int iI = 0; iI < n; iI++)
		{
			array[i][iI] = rand() % 8 + 2;
			cout << array[i][iI] << "\t";
		}
		cout << endl;
	}
}
