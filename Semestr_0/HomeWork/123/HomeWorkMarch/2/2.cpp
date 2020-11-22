//2. Используя указатель на массив целых чисел, посчитать сумму элементов массива.Использовать
//в программе арифметику указателей для продвижения по массиву, а также оператор
//разыменования.
#include <iostream>
#include <Windows.h>
using namespace std;

/// <summary>
/// Сума масива
/// </summary>
int GetSum(int*, int*);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int c = 9;
	int mas[c] = { 1,2,3,4,5,6,7,8,9 };
	cout << "Вхідний масив: \n";
	
	for (int* i = mas; i != mas + c; i++)
		cout << *i;
	cout << endl;

	cout << "Сума масива: "
		<< GetSum(mas, mas + c - 1);
	
}

int GetSum(int* mas, int* last)
{
	int result = 0;
	do
	{
		result+=*mas;
	} 
	while (mas++ != last);
	return result;
}