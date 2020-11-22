
#include <iostream>
#include <ctime>
#include<windows.h>
using namespace std;

//Вказівник на функцію, тип сортування
using SortTo = bool(int, int);
/// <summary>
/// Сортування масиву
/// </summary>
/// <param name="int*">Вказівник на масив</param>
/// <param name="int">Кількість елементів</param>
/// <param name="SortTo">Сотрувати як</param>
void SortMas(int*, int, SortTo);
/// <summary>
/// Фуекція пошуку елемента в масиві
/// </summary>
int* search(int*, int, SortTo);
/// <summary>
/// Сортувати до більшого
/// </summary>
bool SortToUP(int, int);
/// <summary>
/// Сортувати до меншого
/// </summary>
bool SortToDown(int, int);
/// <summary>
/// Генерація масиву
/// </summary>
void GenerateMas(int*, int*);
/// <summary>
/// Вивід масиву в консолі
/// </summary>
void ShowMas(int*, int*);

int main()
{
	SetConsoleCP(1251);  
	SetConsoleOutputCP(1251); 
	srand((int)time(0));

	const int count = 9;
	int mas[count] = {0}; //створення масиву заповненого нулями
	GenerateMas(mas, mas + count); //заповнюємо масив випадковими числами, через вказівники
	cout << "Сортування масиву:" << endl;
	ShowMas(mas, mas + count);//Виводимо масив
	
	cout << "Сортування масиву до більшого:" << endl;
	SortMas(mas, count, SortToUP);//Сортуємо масив по зростаючій
	ShowMas(mas, mas + count);//Виводимо масив
	
	cout << "Сортування масиву до меншого:" << endl;
	SortMas(mas, count, SortToDown);//Сортуємо масив по спадаючій
	ShowMas(mas, mas + count);//Виводимо масив
}

void SortMas(int* mas, int count, SortTo sortAs)
{
	for (int i = 0; i < count; i++)
	{
		int temp = mas[i]; //Запамятовуємо число активного елемента
    	int*  y = search(&mas[i], count-i, sortAs);//Шукаемо найбільший чи найменший елемент за активного, в діапазоні
		mas[i] = *y;//присвоємо активному елементу значення знайденого
		*y = temp;//знайденому елементу присвоюємо збережене значення активного
	}
}

int *search(int* mas, int count, SortTo sortAs)
{
		int* result = mas;
		for (int* j = mas + 1; j != mas + count; ++j)
			if (sortAs (*j, *result))//В залежності від вибраного типу сортування, вибираємо найбільший чи найменший елемент в діапазоні
				result = j;
		return result;
}

bool SortToUP(int a, int b)//Сортуємо масив по зростаючій
{
	return a < b;
}
bool SortToDown(int a, int b)//Сортуємо масив по спадаючій
{
	return a > b;
}

void GenerateMas(int* mas, int* last)
{
	for (int* i = mas; i != last; i++)
	{
		*i = rand() % 10;
	}
}
void ShowMas(int* mas, int* last)
{
	do
	{	
		cout << *mas;
	} 
	while (++mas != last);
	cout <<  endl;
}