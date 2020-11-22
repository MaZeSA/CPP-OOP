//Класна задача
//Поєднання двох відсортованих масивів, по зростаючій без використання сортування

#include <Windows.h>
#include <iostream>
using namespace std;
/// <summary>
/// Обєднати масиви
/// </summary>
/// <param name="mas1">масив 1</param>
/// <param name="countItemMas1">кількість елемантів масива 1</param>
/// <param name="countItemMas2">масив 2</param>
/// <param name="mas2">кількість елемантів масива 2</param>
/// <returns></returns>
int* GlueMas(int*, int, int*, int);
/// <summary>
/// Вивести масив
/// </summary>
void ShowMas(int*, int);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Поєднання масивів:\n\n"
		<< "Приклад №1:" << endl;

	const int c1 = 9; 
	const int c2 = 6;
	int mas1[c1] = { 0,1,1,2,3,4,5,6,7 };
	int mas2[c2] = { 5,6,7,8,8,9 };
	cout << "Масив №1_>: "; 
	ShowMas(mas1, c1);
	cout << "Масив №2_>: "; 
	ShowMas(mas2, c2);
	int* result = GlueMas(mas1, c1, mas2, c2);
	cout << "Результат: "; 
	ShowMas(result, c1 + c2);
	delete result;
	
	cout << "\nПриклад №2: " << endl;
	const int c3 = 5;
	const int c4 = 8;
	int mas3[c3] = { 4,5,6,8,9};
	int mas4[c4] = { 0,1,3,5,7,7,8,8 };
	cout << "Масив №3_>: "; 
	ShowMas(mas3, c3);
	cout << "Масив №4_>: "; 
	ShowMas(mas4, c4);
	int* result1 = GlueMas(mas3, c3, mas4, c4);
	cout << "Результат: "; 
	ShowMas(result1, c3 + c4);
	delete result1;
}

int *GlueMas(int* mas1, int countItemMas1, int *mas2, int countItemMas2)
{
	int* result = new int[countItemMas1 + countItemMas2]{0}; 

	int *selectIMas1 = mas1,//вибраний елемент масива 1
		*selectIMas2 = mas2;//вибраний елемент масива 2

	for (int i = 0; i < countItemMas1 + countItemMas2 ; i++) 
	{
		//якщо елемент[i] масива 1 меньший-рівний елементу[i] масива 2 і масив 1 не дорівнює свому останьму елементу, або масив 2 досяг свого кінця
		if (*selectIMas1 <= *selectIMas2 && selectIMas1 != mas1+ countItemMas1|| selectIMas2 == mas2 + countItemMas2 )
		{
			result[i] = *selectIMas1;
			selectIMas1++;
		}
		else
		{
			result[i] = *selectIMas2;
			selectIMas2++;
		}
	}
	return result;
}

void ShowMas(int* mas, int count)
{
	for (int* i = mas; i != mas + count; i++)
		cout << *i;
	cout << endl;
}
