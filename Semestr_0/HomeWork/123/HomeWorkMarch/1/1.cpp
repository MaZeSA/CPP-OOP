//1.Используя два указателя на массивы целых чисел, скопировать один массив в другой так, чтобы
//во втором массиве элементы находились в обратном порядке.
//Использовать в программе арифметику указателей для продвижения по массиву, а также
//оператор разыменования.
#include <Windows.h>
#include <iostream>
using namespace std;

int* Reverse(int*, int*);
/// <summary>
/// Кількість елементів в масиві
/// </summary>
int GetCount(int*, int*);
/// <summary>
/// Вивести масив
/// </summary>
void ShowMas(int*, int);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int c = 9;
	int mas[c] = {1,2,3,4,5,6,7,8,9};
	cout << "Вхідний масив: \n";
	ShowMas(mas, c);

	int* result = Reverse(mas, mas+c-1);
	cout << "Вихідний масив: \n";
	ShowMas(result, c);
}

int* Reverse(int* mas, int* last)
{
	int* result = new int[GetCount(mas, last)];

	int i = 0;
	do {
		*(result + i++) = *last;
	}
	while (mas != last--);

	return result;
}

int GetCount(int* mas, int* last)
{
	int result = 0;
	do 
	{
		result++;
	} while (mas++ != last);
	return result;
}

void ShowMas(int* mas, int count)
{
	for (int* i = mas; i != mas + count; i++)
		cout << *i;
	cout << endl;
}